#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

vector<pair<pair<int,int>,pair<int,int> > > r;
int n;
bool o[8][8];
int pi[8][8],pj[8][8];
queue<pair<int,int> > q;
int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};
bool done[8][8];

int main(){
	scanf("%d",&n);
	fore(_,0,n){
		char s[4];
		scanf("%s",s);
		int i=s[0]-'a',j=s[1]-'1';
		o[i][j]=true;
	}
	int t=0;
	fore(j,0,8){
		if(t==n)break;
		fore(i,0,8){
			if(t==n)break;
			if(o[i][j]){done[i][j]=true;t++;continue;}
			auto p=mp(-1,-1);
			fore(i,0,8)fore(j,0,8)if(!done[i][j]&&o[i][j])p=mp(i,j);
			assert(p.fst>=0);
			int x=p.fst,y=p.snd;
			mset(pi,-1);
			pi[x][y]=pj[x][y]=-2;
			q.push(mp(x,y));
			while(!q.empty()){
				auto p=q.front();q.pop();
				int x=p.fst,y=p.snd;
				fore(i,0,8){
					int xx=x+dx[i],yy=y+dy[i];
					if(xx>=0&&xx<8&&yy>=0&&yy<8&&pi[xx][yy]==-1){
						pi[xx][yy]=x;
						pj[xx][yy]=y;
						q.push(mp(xx,yy));
					}
				}
			}
			//printf(" %d %d %d %d\n",x,y);puts("");
			assert(pi[i][j]>=0);
			vector<pair<int,int> > z;
			int xx=i,yy=j;
			z.pb(mp(xx,yy));
			while(xx!=x||yy!=y){
				int xxx=pi[xx][yy],yyy=pj[xx][yy];
				xx=xxx;yy=yyy;
				z.pb(mp(xx,yy));
			}
			reverse(z.begin(),z.end());
			stack<pair<int,int> > s;
			fore(i,0,SZ(z)-1){
				int x=z[i].fst,y=z[i].snd;
				int xx=z[i+1].fst,yy=z[i+1].snd;
				assert(o[x][y]);
				if(o[xx][yy]){s.push(mp(x,y));continue;}
				r.pb(mp(mp(x,y),mp(xx,yy)));

				//auto p=r.back();
				//printf("%c%c-%c%c\n",(char)(p.fst.fst+'a'),(char)(p.fst.snd+'1'),(char)(p.snd.fst+'a'),(char)(p.snd.snd+'1'));fflush(stdout);

				o[x][y]=false;
				o[xx][yy]=true;
				xx=x;yy=y;
				while(!s.empty()){
					int x=s.top().fst,y=s.top().snd;s.pop();
					assert(o[x][y]&&!o[xx][yy]);
					r.pb(mp(mp(x,y),mp(xx,yy)));
					o[x][y]=false;o[xx][yy]=true;
					xx=x;yy=y;
				}
			}
			assert(o[i][j]);assert(s.empty());
			t++;
			done[i][j]=true;
		}
	}
	fore(i,0,8)fore(j,0,8)if(done[i][j]){assert(o[i][j]);}
	assert(SZ(r)<=1500);
	printf("%d\n",SZ(r));
	for(auto p:r)printf("%c%c-%c%c\n",(char)(p.fst.fst+'a'),(char)(p.fst.snd+'1'),(char)(p.snd.fst+'a'),(char)(p.snd.snd+'1'));
	return 0;
}
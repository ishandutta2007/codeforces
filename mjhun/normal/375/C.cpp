#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define INF (1<<25)
using namespace std;
typedef long long ll;

int n,m;
char b[32][32];
int d[2][32][32][256][2];
int t[8],px[8],py[8],v[8],k,o,xs,ys;

bool valid(int x, int y){return x>=0&&x<n&&y>=0&&y<m&&b[x][y]=='.';}

queue<pair<pair<int,int>,pair<int,int> > > q;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void bfs(int x, int y, int m, int b, int d[32][32][256][2]){
	d[x][y][m][b]=0;
	q.push(mp(mp(x,y),mp(m,b)));
	while(!q.empty()){
		auto p=q.front();q.pop();
		x=p.fst.fst;y=p.fst.snd;m=p.snd.fst;b=p.snd.snd;
		fore(i,0,4){
			int nx=x+dx[i],ny=y+dy[i];
			if(!valid(nx,ny))continue;
			int nm=m;
			if(i==b)fore(j,0,k)if(px[j]==x&&py[j]>y)nm^=1<<j;
			int nb=b;
			if(i<2)nb=i;
			if(d[nx][ny][nm][nb]<0){
				d[nx][ny][nm][nb]=d[x][y][m][b]+1;
				q.push(mp(mp(nx,ny),mp(nm,nb)));
			}
		}
	}
}

int main(){
	memset(d,-1,sizeof(d));
	scanf("%d%d",&n,&m);
	fore(i,0,n){
		scanf("%s",b[i]);
		fore(j,0,m){
			if(b[i][j]=='S')xs=i,ys=j,b[i][j]='.';
			else if(b[i][j]!='.'&&b[i][j]!='#'){
				px[k]=i;py[k]=j;
				if(b[i][j]=='B')t[k]=-1;
				else {
					t[k]=b[i][j]-'1';
					o=max(o,b[i][j]-'0');
				}
				k++;
			}
		}
	}
	fore(i,0,o)scanf("%d",v+i);
	bfs(xs,ys,0,0,d[0]);
	bfs(xs,ys,0,1,d[1]);
	int r=0;
	fore(m,0,1<<k){
		bool asd=true;
		fore(i,0,k)if(((m>>i)&1)&&t[i]<0)asd=false;
		if(!asd)continue;
		int a=d[0][xs][ys][m][0];
		int b=d[1][xs][ys][m][1];
		if(a<0)a=INF;
		if(b<0)b=INF;
		int rr=-min(a,b);
		fore(i,0,k)if((m>>i)&1)rr+=v[t[i]];
		r=max(r,rr);
	}
	printf("%d\n",r);
	return 0;
}
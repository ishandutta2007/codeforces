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
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int sgn(int x){
	if(!x)return 0;
	return x<0?-1:1;
}

int n,d[1024],l[1024];
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
int asd[256];
bool o[2048][2048],v[2048][2048];
set<int> xs,ys;
map<int,int> idx,idy;int nx,ny;
int wx[2048],wy[2048];

void dfs(int x, int y){
	if(x<0||x>=nx||y<0||y>=ny||v[x][y]||o[x][y])return;
	v[x][y]=true;
	fore(_,0,4)dfs(x+dx[_],y+dy[_]);
}

void doit(set<int>& s, map<int,int>& id, int *w, int& n){
	vector<int> v(s.begin(),s.end());n=0;
	fore(i,0,SZ(v)){
		w[n]=1;id[v[i]]=n++;
		if(i<SZ(v)-1&&v[i+1]>v[i]+1)w[n++]=v[i+1]-v[i]-1;
	}
}

int main(){
	asd['L']=0;asd['R']=1;asd['U']=2;asd['D']=3;
	scanf("%d",&n);
	int x=0,y=0;xs.insert(x);ys.insert(y);
	fore(i,0,n){
		char s[4];
		scanf("%s%d",s,l+i);
		d[i]=asd[s[0]];
		x+=dx[d[i]]*l[i];xs.insert(x);
		y+=dy[d[i]]*l[i];ys.insert(y);
	}
	doit(xs,idx,wx,nx);
	doit(ys,idy,wy,ny);
	x=0;y=0;o[idx[x]][idy[y]]=1;
	fore(i,0,n){
		int xx=x+dx[d[i]]*l[i],yy=y+dy[d[i]]*l[i];
		int x0=idx[x],y0=idy[y],x1=idx[xx],y1=idy[yy];
		while(x0!=x1||y0!=y1){
			x0+=sgn(x1-x0);y0+=sgn(y1-y0);
			o[x0][y0]=1;
		}
		x=xx;y=yy;
	}
	fore(i,0,nx)dfs(i,0),dfs(i,ny-1);
	fore(i,0,ny)dfs(0,i),dfs(nx-1,i);
	ll r=0;
	fore(i,0,nx)fore(j,0,ny)if(!v[i][j])r+=1LL*wx[i]*wy[j];
	printf("%lld\n",r);
	return 0;
}
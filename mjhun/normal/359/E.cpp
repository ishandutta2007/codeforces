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
#define y0 PENAZZI
using namespace std;
typedef long long ll;

int n,x0,y0;
int b[512][512];
bool v0[512][512],v1[512][512];
int mnx[512],mny[512],mxx[512],mxy[512];
string r;

void dfs0(int x, int y){
	v0[x][y]=true;
	if(!b[x][y]){
		r.pb('1');
		mnx[x]=min(mnx[x],y);mxx[x]=max(mxx[x],y);
		mny[y]=min(mny[y],x);mxy[y]=max(mxy[y],x);
	}
	if(mnx[x]<y&&!v0[x][y-1])r.pb('L'),dfs0(x,y-1),r.pb('R');
	if(mxx[x]>y&&!v0[x][y+1])r.pb('R'),dfs0(x,y+1),r.pb('L');
	if(mny[y]<x&&!v0[x-1][y])r.pb('U'),dfs0(x-1,y),r.pb('D');
	if(mxy[y]>x&&!v0[x+1][y])r.pb('D'),dfs0(x+1,y),r.pb('U');
}

void dfs1(int x, int y){
	v1[x][y]=true;
	if(y>=0&&v0[x][y-1]&&!v1[x][y-1])r.pb('L'),dfs1(x,y-1),r.pb('R');
	if(y<n-1&&v0[x][y+1]&&!v1[x][y+1])r.pb('R'),dfs1(x,y+1),r.pb('L');
	if(x>=0&&v0[x-1][y]&&!v1[x-1][y])r.pb('U'),dfs1(x-1,y),r.pb('D');
	if(x<n-1&&v0[x+1][y]&&!v1[x+1][y])r.pb('D'),dfs1(x+1,y),r.pb('U');
	r.pb('2');
}

int main(){
	scanf("%d%d%d",&n,&x0,&y0);x0--;y0--;
	fill(mnx,mnx+n,1<<30);fill(mxx,mxx+n,-1);
	fill(mny,mny+n,1<<30);fill(mxy,mxy+n,-1);
	fore(i,0,n)fore(j,0,n){
		scanf("%d",&b[i][j]);
		if(b[i][j]){
			mnx[i]=min(mnx[i],j);mxx[i]=max(mxx[i],j);
			mny[j]=min(mny[j],i);mxy[j]=max(mxy[j],i);
		}
	}
	dfs0(x0,y0);
	fore(i,0,n)fore(j,0,n)if(b[i][j]&&!v0[i][j]){puts("NO");return 0;}
	dfs1(x0,y0);
	printf("YES\n%s\n",r.c_str());
	return 0;
}
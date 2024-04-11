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

vector<int> g[200005];
int f[200005][3]; // 0 -> lo tengo que cubrir, 1 -> esta pintado, 2-> esta cubierto
int n,r;

void dfs(int x, int p){
	for(int y:g[x])if(y!=p)dfs(y,x);
	f[x][0]=0;
	for(int y:g[x])if(y!=p)f[x][0]+=f[y][2];
	f[x][1]=1;
	for(int y:g[x])if(y!=p)f[x][1]+=f[y][0];
	int t=1<<30;
	for(int y:g[x])if(y!=p)t=min(t,f[y][1]-f[y][2]);
	f[x][2]=min(f[x][1],f[x][0]+t);
	f[x][2]=min(f[x][2],f[x][1]);
	f[x][0]=min(f[x][0],f[x][2]);
}

int main(){
	scanf("%d",&n);
	fore(_,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	for(int x:g[0])for(int y:g[x])if(y)dfs(y,x),r+=f[y][0];
	printf("%d\n",r);
	return 0;
}
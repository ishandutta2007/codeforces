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

vector<int> g[100005];
int c[100005];
int q[2];
int n;

void dfs(int x, int cc){
	if(c[x]>=0)return;
	//puts("hola");
	c[x]=cc;q[cc]++;
	for(int y:g[x])dfs(y,!cc);
}

int main(){
	memset(c,-1,sizeof(c));
	scanf("%d",&n);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	dfs(0,0);
	printf("%lld\n",1LL*q[0]*q[1]-(n-1));
	return 0;
}
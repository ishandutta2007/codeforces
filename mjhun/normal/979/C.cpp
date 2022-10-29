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

int s[300005];
vector<int> g[300005];
int n,x,y;

void dfs(int x, int f){
	s[x]=1;
	for(int y:g[x])if(y!=f){
		dfs(y,x);
		s[x]+=s[y];
	}
}

int main(){
	scanf("%d%d%d",&n,&x,&y);x--;y--;
	fore(_,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	dfs(x,-1);
	int a=s[y];
	dfs(y,-1);
	int b=s[x];
	printf("%lld\n",1LL*n*(n-1)-1LL*a*b);
	return 0;
}
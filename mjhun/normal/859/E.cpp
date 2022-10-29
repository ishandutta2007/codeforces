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

#define MOD 1000000007

int mul(ll a, ll b){return a*b%MOD;}

vector<int> g[200005];
int f[200005];
bool vis[200005];
int n;

int dfs(int x){
	if(vis[x])return 0;
	vis[x]=1;
	int r=1;
	for(int y:g[x])r+=dfs(y);
	return r;
}

int main(){
	mset(f,-1);
	scanf("%d",&n);
	fore(i,0,n){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		f[a]=b;
		g[a].pb(b);g[b].pb(a);
	}
	n*=2;
	ll r=1;
	fore(i,0,n)if(!vis[i]&&f[i]<0)r=mul(r,dfs(i));
	fore(i,0,n)if(!vis[i])dfs(i),r=mul(r,2);
	fore(i,0,n)if(f[i]==i)r=mul(r,(MOD+1)/2);
	printf("%lld\n",r);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1210;
VI e[N];
int d,m,vis[N],q[N],p[N],mark[N];
char s[N];
int dfs(int u) {
	for (auto v:e[u]) if (!vis[v]) {
		vis[v]=1;
		if (p[v]==-1||dfs(p[v])) { p[v]=u; return 1;}
	}
	return 0;
}

int main() {
	scanf("%d%d",&d,&m);
	rep(i,0,m) {
		scanf("%s",s);
		int id=0;
		rep(j,0,d) if (s[j]=='1') id+=(1<<j);
		q[i]=id;
	}
	rep(i,0,m) rep(j,0,m) if (j!=i&&(q[j]&q[i])==q[i]) e[i].pb(j);
	memset(p,-1,sizeof(p));
	per(i,0,d+1) rep(j,0,m) if (__builtin_popcount(q[j])==i)  {
		memset(vis,0,sizeof(vis));
		dfs(j);
	}
	string os;
	bool fs=1;
	per(i,0,d+1) rep(j,0,m) if (__builtin_popcount(q[j])==i&&!mark[j])  {
		VI ch;
		int u=j;
		while (u!=-1) {
			ch.pb(q[u]);
			mark[u]=1;
			u=p[u];
		}
		ch.pb(0);
		reverse(all(ch));
		if (!fs) os.pb('R');
		fs=0;
		rep(i,0,SZ(ch)-1) {
			int u=ch[i+1]^ch[i];
			rep(j,0,d) if (u&(1<<j)) os.pb('0'+j);
		}
	}
	printf("%d\n",SZ(os));
	for (auto x:os) printf("%c ",x);
	puts("");
}
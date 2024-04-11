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

const int N=101000;
int n,u,v,lab[N];
vector<PII> e[N];
int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(mp(v,i));
		e[v].pb(mp(u,i));
	}
	rep(i,1,n) lab[i]=-1;
	rep(u,1,n+1) if (SZ(e[u])>=3) {
		rep(j,0,3) lab[e[u][j].se]=j;
		int z=3;
		rep(j,1,n) if (lab[j]==-1) lab[j]=z++;
		rep(j,1,n) printf("%d\n",lab[j]);
		return 0;
	}
	rep(j,1,n) printf("%d\n",j-1);
}
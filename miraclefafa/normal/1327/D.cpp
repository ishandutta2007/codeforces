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

const int N=201000;
int _,p[N],c[N],vis[N],n;
VI d[N];
int main() {
	for (int i=1;i<=200000;i++) for (int j=i;j<=200000;j+=i)
		d[j].pb(i);
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		rep(i,1,n+1) scanf("%d",p+i);
		rep(i,1,n+1) scanf("%d",c+i),vis[i]=0;
		int ans=n+1;
		rep(i,1,n+1) if (!vis[i]) {
			int u=i;
			VI cyc;
			while (!vis[u]) {
				cyc.pb(c[u]);
				vis[u]=1;
				u=p[u];
			}
			int m=SZ(cyc);
			for (auto k:d[m]) for (int j=0;j<k;j++) {
				bool suc=1;
				for (int r=j;r<m;r+=k) {
					suc&=cyc[r]==cyc[j];
				}
				if (suc) ans=min(ans,k);
			}
		}
		printf("%d\n",ans);
	}
}
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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int n,m,u,v,a[N],b[N];
unordered_set<int> e[N];
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		e[u].insert(v);
		e[v].insert(u);
	}
	rep(i,1,n+1) rep(j,1,n+1) if (i!=j) {
		if (!e[i].count(j)) {
			puts("YES");
			int tot=0;
			rep(k,1,n+1) if (i!=k&&j!=k) {
				++tot;
				a[k]=tot;
				b[k]=tot;
			}
			a[i]=tot+1; a[j]=tot+2;
			b[i]=tot+1; b[j]=tot+1;
			rep(k,1,n+1) printf("%d%c",a[k]," \n"[k==n]);
			rep(k,1,n+1) printf("%d%c",b[k]," \n"[k==n]);
			return 0;
		}
	}
	puts("NO");
}
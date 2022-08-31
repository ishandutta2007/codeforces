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

const int N=10100;
int n,l[N],r[N],a[N],id;
set<int> hs;
map<int,int> rk;
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",l+i);
	rep(i,1,n+1) scanf("%d",r+i);
	rep(i,1,n+1) hs.insert(l[i]+r[i]);
	for (auto p:hs) {
		rk[p]=++id;
	}
	rep(i,1,n+1) {
		a[i]=rk[l[i]+r[i]];
	}
	rep(i,1,n+1) {
		int cl=0,cr=0;
		rep(j,1,i) if (a[i]>a[j]) cl++;
		rep(j,i+1,n+1) if (a[i]>a[j]) cr++;
		if (cl!=l[i]||cr!=r[i]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	rep(i,1,n+1) printf("%d%c",n+1-a[i]," \n"[i==n]);
}
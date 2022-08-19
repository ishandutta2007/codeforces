#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
// head

const int N=101000;
int n,a[N],p[N];
ll s[N],sm[N];
multiset<ll> ss;
set<int> sp;
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i),s[i]=s[i-1]+a[i];
	rep(i,1,n+1) scanf("%d",p+i);
	ss.insert(s[n]);
	sp.insert(n);
	sm[n]=s[n];
	rep(i,1,n+1) {
		int np=*sp.lower_bound(p[i]);
		ss.erase(ss.lower_bound(sm[np]));
		sp.insert(p[i]-1);
		sm[p[i]-1]=sm[np]-(s[np]-s[p[i]-1]);
		sm[np]=s[np]-s[p[i]];
		ss.insert(sm[p[i]-1]);
		ss.insert(sm[np]);
		printf("%lld\n",*ss.rbegin());
	}
}
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
int n,k,a[N];
ll s[N],ret;
set<ll> hs;
map<ll,int> cnt;
int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) {
		scanf("%d",a+i);
		s[i]=s[i-1]+a[i];
	}
	hs.insert(1);
	if (k==-1) hs.insert(-1);
	else if (k!=1) {
		ll x=1;
		while (x*k<=(1ll<<60)&&x*k>=-(1ll<<60)) {
			x*=k;
			hs.insert(x);
		}
	}
	cnt[0]=1;
	rep(i,1,n+1) {
		for (auto p:hs) if (cnt.count(s[i]-p)) ret+=cnt[s[i]-p];
		cnt[s[i]]++;
	}
	printf("%lld\n",ret);
}
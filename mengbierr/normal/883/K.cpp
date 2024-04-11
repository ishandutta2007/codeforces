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

const int N=201000;
int n,s[N],g[N],ret[N],tot[N];
ll ans;
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d",s+i,g+i);
		ret[i]=tot[i]=s[i]+g[i];
	}
	int mv=tot[0];
	rep(i,0,n) {
		mv=min(mv,tot[i]-i);
		ret[i]=min(ret[i],mv+i);
	}
	mv=tot[n-1]+(n-1);
	per(i,0,n) {
		mv=min(mv,tot[i]+i);
		ret[i]=min(ret[i],mv-i);
	}
	rep(i,0,n) {
		if (ret[i]<s[i]) {
			puts("-1"); return 0;
		}
		ans+=ret[i]-s[i];
	}
	printf("%lld\n",ans);
	rep(i,0,n) printf("%d ",ret[i]);
	puts("");
}
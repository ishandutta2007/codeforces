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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=1010000;
int p,k,vis[N],cnt[N];
VI d;
int main() {
	scanf("%d%d",&p,&k);
	if (k==0) {
		printf("%lld\n",powmod(p,p-1));
		return 0;
	}
	rep(i,0,p) if (!vis[i]) {
		ll x=i,l=0;
		while (1) {
			l++; vis[x]=1;
			x=x*k%p;
			if (x==i) break;
		}
		cnt[l]++;
	}
	ll ret=1;
	rep(i,1,p+1) if (cnt[i]!=0) d.pb(i);
	rep(i,0,SZ(d)) {
		int w=0;
		rep(j,0,SZ(d)) if (d[i]%d[j]==0) w+=cnt[d[j]]*d[j];
		ret=ret*powmod(w,cnt[d[i]])%mod;
	}
	printf("%lld\n",ret);
}
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

map<ll,ll> dp;
int q,ty,w;
ll u,v;
int main() {
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d%lld%lld",&ty,&u,&v);
		if (ty==1) {
			scanf("%d",&w);
			while (u!=v) {
				if (u>v) swap(u,v);
				dp[v]+=w; v/=2;
			}
		} else {
			ll s=0;
			while (u!=v) {
				if (u>v) swap(u,v);
				s+=dp[v]; v/=2;
			}
			printf("%lld\n",s);
		}
	}
}
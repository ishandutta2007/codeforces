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

const int N=1010000;
int n,pw[10],pw2[N],x;
ll f0[N],f1[N],f2[N],G[N];
void upd(ll &a,ll b) { a+=b; if (a>=mod) a-=mod; }
int main() {
	scanf("%d",&n);
	pw[0]=1;
	rep(i,1,7) pw[i]=pw[i-1]*10;
	pw2[0]=1;
	rep(i,1,1000001) pw2[i]=pw2[i-1]*2%mod;
	rep(i,0,n) {
		scanf("%d",&x);
		f0[x]+=1;
		f1[x]=(f1[x]+x)%mod;
		f2[x]=(f2[x]+(ll)x*x)%mod;
	}
	rep(k,0,6) {
		per(i,0,1000000) if (i/pw[k]%10) {
			upd(f0[i-pw[k]],f0[i]);
			upd(f1[i-pw[k]],f1[i]);
			upd(f2[i-pw[k]],f2[i]);
		}
	}
	rep(i,0,1000000) {
		if (f0[i]==0) G[i]=0;
		else if (f0[i]==1) G[i]=f2[i];
		else G[i]=((f2[i]*pw2[f0[i]-1])+(f1[i]*f1[i]-f2[i])%mod*pw2[f0[i]-2])%mod;
	}
	rep(k,0,6) {
		rep(i,0,1000000) if (i/pw[k]%10!=9) {
			(G[i]-=G[i+pw[k]])%=mod;
		}
	}
	ll ret=0;
	rep(i,0,1000000) {
		if (G[i]<0) G[i]+=mod;
		ret^=i*G[i];
	}
	printf("%lld\n",ret);
}
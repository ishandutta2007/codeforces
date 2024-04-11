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
//int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=5010000,M=201000;
int n,m,p[M],a[N],rem[N],t[N];
ll s[3];
int main() {
	scanf("%d",&n);
	scanf("%d",&m);
	ll seed = 0, base = 0;
	auto rnd=[&]() {
		ll ret = seed;
		seed = (seed * base + 233) % 1000000007;
		return ret;
	};
	p[0] = 0;
	rep(i,1,m+1) {
		int k;
		scanf("%d%d%lld%lld",&p[i],&k,&seed,&base);
		rep(j,p[i-1]+1,p[i]+1) {
			t[j]=rnd()%2+1;
			a[j]=rnd()%k+1;
			rem[j]=a[j];
			s[t[j]]+=a[j];
		}
	}
	int los=t[1],pos=1;
	if (s[t[1]]>s[3-t[1]]) {
		rem[1]--;
		los=3-t[1];
		rep(i,1,n+1) if (t[i]==3-t[1]) {
			pos=i; break;
		}
	}
	//printf("%d %d\n",los,pos);
	ll c=0;
	rep(i,0,2*n) {
		if (t[pos]==los) {
			c+=rem[pos]; rem[pos]=0;
		} else {
			ll d=min((ll)rem[pos],c);
			rem[pos]-=d; c-=d;
		}
		//printf("%d %d\n",pos,rem[pos]);
		pos=pos%n+1;
	}
	ll ans=1;
	rep(i,1,n+1) {
		//printf("%d\n",a[i]-rem[i]);
		ans=ans*((((a[i]-rem[i])^((ll)i*i))+1)%mod)%mod;
	}
	printf("%lld\n",ans);
}
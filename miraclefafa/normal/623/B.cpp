#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=1010000;
const ll inf=1ll<<60;
VI pr;
ll p1[N],p2[N];
int v[N],n,a,b;
void gao(int x) {
	for (int r=2;r*r<=x;r++) if (x%r==0) {
		pr.pb(r);
		while (x%r==0) x/=r;
	}
	if (x!=1) pr.pb(x);
}
ll solve(int p) {
	p2[n+1]=0;
	per(i,1,n+1) {
		p2[i]=inf;
		if (v[i]%p==0) p2[i]=p2[i+1];
		else if ((v[i]+1)%p==0||(v[i]-1)%p==0) p2[i]=p2[i+1]+b;
	}
	p1[0]=0;
	rep(i,1,n+1) {
		p1[i]=inf;
		if (v[i]%p==0) p1[i]=p1[i-1];
		else if ((v[i]+1)%p==0||(v[i]-1)%p==0) p1[i]=p1[i-1]+b;
	}
	ll mv=-a;
	ll ans=inf;
	rep(j,1,n+1) {
		ans=min(ans,p2[j]+(ll)j*a+mv);
		mv=min(mv,p1[j]-(ll)(j+1)*a);
	}
	rep(i,1,n+1) {
		ans=min(ans,p1[i]+(ll)(n-i)*a);
	}
	return ans;
	// p2
}
int main() {
	scanf("%d%d%d",&n,&a,&b);
	rep(i,1,n+1) scanf("%d",v+i);
	gao(v[1]);
	gao(v[1]-1);
	gao(v[1]+1);
	gao(v[n]);
	gao(v[n]-1);
	gao(v[n]+1);
	ll ans=inf;
	for (auto p:pr) ans=min(ans,solve(p));
	printf("%I64d\n",ans);
}
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
#define mp ma1ke_pair
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

const ll N=10000000;
int pr[N/5],p[N+100],tot,mu[N+100],phi[N+100],n;

void init() {
	mu[1]=1;
	p[1]=1;
	phi[1]=1;
	rep(i,2,N+1) {
		if (!p[i]) p[i]=i,pr[++tot]=i,mu[i]=-1,phi[i]=i-1;;
		for (int j=1;j<=tot&&pr[j]*i<=N;j++) {
			p[i*pr[j]]=pr[j];
			if (p[i]==pr[j]) {
				phi[i*pr[j]]=phi[i]*pr[j];
				break;
			} else {
				mu[i*pr[j]]=-mu[i];
				phi[i*pr[j]]=phi[i]*(pr[j]-1);
			}
		}
	}
}
ll calc1() {
	ll ret=0;
	rep(i,2,n+1) ret+=i-phi[i]-1;
	return ret;
}
ll calc0() {
	ll ret=0,u=0;
	rep(i,1,n+1) {
		if (i==1||(2*i>n&&p[i]==i)) {
			ret+=i-1;
			u++;
		} else {
			ret+=u;
		}
	}
	return ret;
}
int cnt[N+100];
ll calc2() {
	ll sm=0;
	rep(d,1,n+1) if (mu[d]) {
		ll ret=0;
		if (n/d>=100000) {
			int mv=0;
			for (int i=d;i<=n;i+=d) mv=max(mv,p[i]);
			rep(i,1,mv+1) cnt[i]=0;
			for (int i=d;i<=n;i+=d) cnt[p[i]]++;
			rep(i,1,mv+1) cnt[i]+=cnt[i-1];
			rep(i,1,mv+1) if (cnt[i]!=cnt[i-1]) ret+=(ll)(cnt[i]-cnt[i-1])*cnt[min(mv,n/i)];
		} else {
			tot=0;
			for (int i=d;i<=n;i+=d) cnt[tot++]=p[i];
			sort(cnt,cnt+tot);
			int r=tot-1;
			rep(i,0,tot) {
				while (r>=0&&(ll)cnt[i]*cnt[r]>n) --r;
				ret+=r+1;
			}
		}
		sm+=mu[d]*ret;
	}
	return (sm+1)/2-n;
}
int main() {
	init();
	scanf("%d",&n);
	ll tot=(ll)n*(n-1)/2;
	ll t1=calc1();
	ll t0=calc0();
	ll t2=calc2();
	ll t3=tot-t1-t0-t2;
	printf("%lld\n",t1+t2*2+t3*3);
}
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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const ll N=1000000;
int pr[N/5],p[N+100],tot,phi[N+100];
int n,k;
void init() {
	phi[1]=1;p[1]=1;
	rep(i,2,N+1) {
		if (!p[i]) p[i]=i,pr[++tot]=i,phi[i]=i-1;
		for (int j=1;j<=tot&&pr[j]*i<=N;j++) {
			p[i*pr[j]]=pr[j];
			if (p[i]==pr[j]) {
				phi[i*pr[j]]=phi[i]*pr[j];
				break;
			} else {
				phi[i*pr[j]]=phi[i]*(pr[j]-1);
			}
		}
	}
}


int main() {
	scanf("%d%d",&n,&k);
	init();
	VI v; ll ans=1;
	rep(i,3,n+1) v.pb(phi[i]);
	sort(all(v));
	rep(i,0,k) ans+=v[i];
	if (k>=2) ans++;
	printf("%lld\n",ans);
}
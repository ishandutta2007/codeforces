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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010000;
int n,C,m;
ll c[N],d[N],h[N],pv[N],md[N];
int main() {
	scanf("%d%d",&n,&C);
	rep(i,0,n) {
		scanf("%lld%lld%lld",c+i,d+i,h+i);
		pv[c[i]]=max(pv[c[i]],d[i]*h[i]);
	}
	rep(i,1,C+1) {
		for (int j=i;j<=C;j+=i) {
			md[j]=max(md[j],(j/i)*pv[i]-1);
		}
	}
	rep(j,1,C+1) md[j]=max(md[j],md[j-1]);
	scanf("%d",&m);
	rep(i,0,m) {
		ll D,H;
		scanf("%lld%lld",&D,&H);
		ll v=D*H;
		int ans=lower_bound(md,md+C+1,v)-md;
		if (ans>C) puts("-1");
		else printf("%d\n",ans);
	}
}
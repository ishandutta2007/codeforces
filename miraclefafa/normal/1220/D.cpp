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

const int N=201000;
int n;
ll b[N];
vector<ll> vs[70];
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%lld",b+i);
		int cnt=0;
		ll x=b[i];
		while (x%2==0) x/=2,cnt++;
		vs[cnt].pb(b[i]);
	}
	int mx=0;
	rep(i,0,61) mx=max(mx,SZ(vs[i]));
	rep(i,0,61) if (mx==SZ(vs[i])) {
		printf("%d\n",n-mx);
		rep(j,0,61) if (j!=i) for (auto v:vs[j]) printf("%lld ",v);
		puts("");
		break;
	}
}
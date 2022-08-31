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

int n,x;
map<PII,int> cnt;
int main() {
	scanf("%d",&n);
	cnt[mp(0,0)]++;
	int s=0;
	rep(i,1,n+1) {
		scanf("%d",&x);
		s^=x;
		cnt[mp(i%2,s)]++;
	}
	ll ans=0;
	for (auto p:cnt) ans=ans+1ll*p.se*(p.se-1)/2;
	printf("%lld\n",ans);
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
int n,sa,sb;
int a[3][N],b[3][N];
int main() {
	scanf("%d",&n);
	rep(i,0,2) rep(j,0,n) scanf("%d",&a[i][j]),sa+=a[i][j];
	rep(i,0,2) rep(j,0,n) scanf("%d",&b[i][j]),sb+=b[i][j];
	if (sa!=sb) {
		puts("-1");
		return 0;
	}
	ll f1=0,f2=0,ans=0;
	rep(i,0,n) {
		f1+=a[0][i]-b[0][i];
		f2+=a[1][i]-b[1][i];
		ans+=abs(f1+f2);
		ll d=min(abs(f1),abs(f2));
		if (f1>0&&f2<0) {
			f1-=d; f2+=d;
			ans+=d;
		} else if (f1<0&&f2>0) {
			f1+=d; f2-=d;
			ans+=d;
		}
	}
	printf("%lld\n",ans);
}
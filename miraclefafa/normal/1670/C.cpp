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

const int N=501000;
int n,f[N],a[N],b[N],v[N],sz[N];
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
void solve() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) f[i]=i,v[i]=0,sz[i]=0;;
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n+1) scanf("%d",b+i);
	rep(i,1,n+1) f[find(a[i])]=find(b[i]);
	rep(i,1,n+1) {
		int c;
		scanf("%d",&c);
		v[find(c)]=1;
	}
	rep(i,1,n+1) sz[find(i)]++;
	int ans=1;
	rep(i,1,n+1) if (find(i)==i&&(sz[i]>=2&&v[i]==0))
		ans=ans*2%mod;
	printf("%d\n",ans);
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
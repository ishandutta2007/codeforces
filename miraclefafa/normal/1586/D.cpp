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
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=110;
int n,a[N];
int main() {
	scanf("%d",&n);
	for (int i=-n+1;i<=n-1;i++) if (i!=0) {
		VI o(n-1,n+i);
		o.pb(n);
		int z=*min_element(all(o));
		for (auto &x:o) x=x-z+1;
		printf("?");
		rep(j,0,n) printf(" %d",o[j]);
		puts("");
		fflush(stdout);
		int y;
		scanf("%d",&y);
		a[y]=-i;
	}
	int z=*min_element(a+1,a+n+1);
	rep(i,1,n+1) a[i]=a[i]-z+1;
	printf("!");
	rep(i,1,n+1) printf(" %d",a[i]);
	puts("");
}
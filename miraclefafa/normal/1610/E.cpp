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

const int N=201000;
int n,a[N],_;

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	int nxt=a[n]+1,ans=0;
	per(i,1,n+1) {
		if (i!=n&&a[i+1]!=a[i]) nxt=a[i+1];
		int d=upper_bound(a+1,a+n+1,a[i])-lower_bound(a+1,a+n+1,a[i]);
		int x=nxt;
		while (1) {
			int y=lower_bound(a+1,a+n+1,x)-a;
			if (y==n+1) break;
			d++;
			x=2*a[y]-a[i];
		}
		ans=max(ans,d);
	}
	printf("%d\n",n-ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
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
int n,a[N],b[N],_;
bool check(int m) {
	int cnt=0;
	rep(i,1,n+1) {
		if (cnt<=b[i]&&m-1-cnt<=a[i]) cnt++;
	}
	return cnt>=m;
}

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d%d",a+i,b+i);	
	int l=0,r=n+1;
	while (l+1<r) {
		int m=(l+r)>>1;
		if (check(m)) l=m; else r=m;
	}
	printf("%d\n",l);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
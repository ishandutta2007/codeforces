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
int _,n;
bool check(int l,int r) {
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int cnt=0;
	for (int i=0;i<r-l+1;i++) {
		int x;
		scanf("%d",&x);
		cnt+=x>=l&&x<=r;
	}
	return cnt%2==1;
}
void solve() {
	scanf("%d",&n);
	int l=0,r=n;
	while (l+1<r) {
		int md=(l+r)>>1;
		if (check(1,md)) r=md; else l=md;
	}
	printf("! %d\n",r);
	fflush(stdout);
}
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
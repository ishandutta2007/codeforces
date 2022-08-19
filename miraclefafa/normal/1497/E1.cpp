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
int n,k,a[N],_;

void solve() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
		scanf("%d",a+i);
		for (int k=2;k*k<=a[i];k++) while (a[i]%(k*k)==0) {
			a[i]/=k*k;
		}
	}
	set<int> hs;
	int cnt=1;
	for (int i=0;i<n;i++) {
		if (hs.count(a[i])) {
			cnt++;
			hs.clear();
		}
		hs.insert(a[i]);
	}
	printf("%d\n",cnt);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
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
int _,a[N],n;
bool check(int x) {
	int l=0,r=n-1;
	while (l<r) {
		if (a[l]==a[r]) l++,r--;
		else if (a[l]==x) l++;
		else if (a[r]==x) r--;
		else return 0;
	}
	return 1;
}

bool solve() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	rep(i,0,n) if (a[i]!=a[n-1-i]) {
		if (check(a[i])||check(a[n-1-i])) return 1;
		else return 0;
	}
	return 1;
}

int main() {
	for (scanf("%d",&_);_;_--) {
		puts(solve()?"YES":"NO");
	}
}
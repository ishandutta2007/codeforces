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

bool isprime(int x) {
	for (int i=2;i*i<=x;i++) if (x%i==0) return false;
	return true;
}

const int N=101000;
int n,a[N],_;

void solve() {
	scanf("%d",&n);
	int s=0;
	for (int i=0;i<n;i++) {
		scanf("%d",a+i);
		s+=a[i];
	}
	if (!isprime(s)) {
		printf("%d\n",n);
		rep(i,1,n+1) printf("%d ",i);
		puts("");
		return;
	}
	int ans=-1,ansid=-1;
	rep(i,0,n) {
		if (!isprime(s-a[i])) {
			if (s-a[i]>ans) ans=s-a[i],ansid=i;
		}
	}
	printf("%d\n",n-1);
	rep(i,1,n+1) if (i!=ansid+1) printf("%d ",i); puts("");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
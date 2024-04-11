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

const int N=10100;
int _;
int n,p[N];
int query(int x) {
	printf("? %d\n",x);
	fflush(stdout);
	int y;
	scanf("%d",&y);
	return y;
}
void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) p[i]=-1;
	rep(i,1,n+1) if (p[i]==-1) {
		int x=query(i);
		while (1) {
			int y=query(i);
			p[x]=y;
			x=y;
			if (p[x]!=-1) break;
		}
	}
	printf("!");
	rep(i,1,n+1) printf(" %d",p[i]); puts("");
	fflush(stdout);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();

	}
}
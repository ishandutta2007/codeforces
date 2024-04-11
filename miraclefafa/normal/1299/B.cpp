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

const int N=101000;

int n,x[N],y[N];
PII p[N];
set<PII> hs;
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d",x+i,y+i);
	}
	rep(i,0,n) {
		int qx=x[(i+1)%n],qy=y[(i+1)%n];
		p[i]=mp(qx-x[i],qy-y[i]);
		hs.insert(p[i]);
	}
	rep(i,0,n) if (!hs.count(mp(-p[i].fi,-p[i].se))) {
		puts("No");
		return 0;
	}
	puts("Yes");
}
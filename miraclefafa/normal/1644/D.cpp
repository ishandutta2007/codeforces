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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
int n,m,k,q,row[N],col[N],x[N],y[N];
void solve() {
	scanf("%d%d%d%d",&n,&m,&k,&q);
	set<int> row,col;
	rep(i,0,q) {
		scanf("%d%d",x+i,y+i);
	}
	ll ans=1;
	per(i,0,q) {
		if ((!row.count(x[i])&&SZ(col)!=m)||
			(!col.count(y[i])&&SZ(row)!=n)) ans=ans*k%mod;
		row.insert(x[i]);
		col.insert(y[i]);
	}
	printf("%lld\n",ans);
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
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
int n,m,cnt[N],cs[N],_;
VI v[N];
void solve() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) cnt[i]=0;
	rep(i,0,m) {
		int k;
		scanf("%d",&k);
		v[i].clear();
		rep(j,0,k) {
			int x;
			scanf("%d",&x);
			v[i].pb(x);
		}
		cnt[v[i][0]]++;
		cs[i]=v[i][0];
	}
	int maj=-1,del=0;
	rep(i,1,n+1) if (cnt[i]>(m+1)/2) {
		maj=i;
		del=cnt[i]-(m+1)/2;
	}
	if (maj!=-1) {
		rep(i,0,m) if (cs[i]==maj&&SZ(v[i])>1&&del) {
			cs[i]=v[i][1];
			del--;
		}
	}
	if (del) {
		puts("NO");
	} else {
		puts("YES");
		rep(i,0,m) printf("%d ",cs[i]);
		puts("");
	}
}
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
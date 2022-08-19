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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
int n,s,_;
int pos[N],a[N],vis[N],vis2[N];
void solve() {
	scanf("%d%d",&n,&s);
	rep(i,1,n+1) {
		scanf("%d",&pos[i]);
		a[pos[i]]=i;
		vis[i]=vis2[i]=0;
	}
	bool val=1;
	rep(i,1,n+1) {
		int x;
		scanf("%d",&x);
		//if (x!=-1) b[x]=i;
		vis[x]=1;
		if (x!=-1) {
			if (pos[i]-x>s) val=0;
			// i->x
			vis2[i]=1;
		}
	}
	if (!val) { puts("0"); return; }
	int pos=0;
	for (int i=n;i>=n-s+1;i--) 
		pos+=!vis[i];
	ll ans=1;
	per(i,1,n+1) {
		if (i-s>=1) pos+=!vis[i-s];
		if (!vis2[a[i]]) {
			ans=ans*pos%mod;
			pos--;
		}
	}
	printf("%lld\n",ans);
}
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
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
int _,n,m,c[N];
char s[N],t[N];
queue<int> q[110];

void modify(int x) {
	for (;x<=n;x+=x&-x) c[x]++;
}
int query(int x) {
	int s=0;
	for (;x;x-=x&-x) s+=c[x];
	return s;
}
void solve() {
	scanf("%d",&n);
	scanf("%s%s",s,t);
	rep(i,0,26) q[i]=queue<int>();
	rep(i,0,n) q[s[i]-'a'].push(i+1);
	rep(i,1,n+1) c[i]=0;
	ll cnt=0,ans=1ll<<60;
	rep(i,0,n) {
		int p=n+1;
		rep(j,0,t[i]-'a') if (!q[j].empty()) p=min(p,q[j].front());
		if (p<=n) ans=min(ans,cnt+p-1-query(p-1));
		int w=t[i]-'a';
		if (q[w].empty()) break;
		p=q[w].front(); q[w].pop();
		cnt+=p-1-query(p-1);
		modify(p);
	}
	if (ans<(1ll<<50)) printf("%lld\n",ans);
	else puts("-1");
}
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
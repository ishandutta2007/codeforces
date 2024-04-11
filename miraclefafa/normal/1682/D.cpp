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
int n,_;
char s[N];
void solve() {
	scanf("%d",&n);
	scanf("%s",s);
	VI pos,pos0;
	rep(i,0,n) {
		if (s[i]=='1') pos.pb(i);
		else pos0.pb(i);
	}
	if (SZ(pos)==0||SZ(pos)%2==1) {
		puts("NO");
		return;
	}
	puts("YES");
	if (SZ(pos0)==0) {
		rep(i,2,n+1) printf("1 %d\n",i);
		return;
	}
	int r=-1;
	rep(i,0,n) if (s[i]=='1'&&s[(i+1)%n]=='0') {
		r=(i+1)%n;
		break;
	}
	int pr=r;
	vector<PII> ans;
	rep(i,0,SZ(pos)) {
		VI x;
		pr=(pr+1)%n;
		x.pb(pr);
		while (s[pr]!='1') {
			pr=(pr+1)%n;
			x.pb(pr);
		}
		ans.pb({r,x[0]});
		rep(i,0,SZ(x)-1) ans.pb({x[i],x[i+1]});
	}
	rep(i,0,SZ(ans)) printf("%d %d\n",ans[i].fi+1,ans[i].se+1);
}
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
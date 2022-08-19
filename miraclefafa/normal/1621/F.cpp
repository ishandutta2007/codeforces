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
int n;
ll a,b,c;
char s[N];
void solve() {
	scanf("%d%lld%lld%lld",&n,&a,&b,&c);
	scanf("%s",s);
	if (c>=b) {
		int c0=0,c1=0;
		rep(i,0,n-1) {
			if (s[i]=='0'&&s[i+1]=='0') c0++;
			if (s[i]=='1'&&s[i+1]=='1') c1++;
		}
		printf("%lld\n",a*min(c0,c1+1)+b*min(c1,c0+1));
		return;
	}
	int c1=0,t1=0;
	rep(i,0,n) if (s[i]=='1') t1++;
	rep(i,0,n-1) {
		if (s[i]=='1'&&s[i+1]=='1') c1++;
	}
	if (t1==n&&n!=1) {
		printf("%lld\n",b);
		return;
	}
	int msg0=0,esg0=0;
	VI ml,el;
	rep(i,0,n) if (s[i]=='0'&&(i==0||s[i-1]!='0')) {
		int r=i;
		while (r<n&&s[r]=='0') r++;
		if (i!=0&&r!=n) {
			if (r-i==1) msg0++;
			else ml.pb(r-i-1);
		} else {
			if (r-i==1) esg0++;
			else el.pb(r-i-1);
		}
	}
	auto solve=[](int msg0,int esg0,VI ml,VI el,int c1) {
		ll ans=0;
		priority_queue<int,VI,greater<int>> md,eg;
		for (auto l:ml) md.push(l);
		for (auto l:el) eg.push(l);
		while (1) {
			if (md.empty()&&eg.empty()) break;
			if (c1==0) break;
			ans+=a;
			if (!md.empty()) {
				int u=md.top(); md.pop(); --u;
				if (u) md.push(u); else msg0++;
			} else {
				int u=eg.top(); eg.pop(); --u;
				if (u) eg.push(u); else esg0++;
			}
			--c1; ans+=b;
		}
		//printf("zz %lld %d\n",ans,msg0);
		if (c1==0) {
			ans+=msg0*(b-c);
			if (!md.empty()||!eg.empty()) {
				ans+=a;
			}
			return ans;
		}
		while (1) {
			if (msg0) {
				msg0--;
				ans+=(b-c);
			} else if (esg0) {
				if (c1) {
					esg0--; c1--;
					ans+=(b-c);
				} else {
					break;
				}
			} else break;
		}
		return ans;
	};
	ll ans=solve(msg0,esg0,ml,el,c1);
	if (c1>=1) {
		ans=max(ans,solve(msg0,esg0,ml,el,c1-1)+b);
	}
	printf("%lld\n",ans);
}

int _;
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
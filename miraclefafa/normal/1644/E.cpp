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
int n,_;
char s[N];

ll solve(int n,char *s,int m) {
	int c=0,fr=m;
	rep(i,0,m) if (s[i]=='R') fr=min(fr,i);
	ll ans=0;
	per(i,0,m) {
		if (s[i]=='R') {
			if (i==fr) c=n-1; else c++;
		} else ans+=c;
	}
	return ans;
}

void solve() {
	scanf("%d",&n);
	scanf("%s",s);
	bool as=1;
	int m=strlen(s);
	rep(i,1,m) as&=s[i]==s[0];
	if (as) {
		printf("%d\n",n);
		return;
	}
	ll ans=1ll*n*n;
	ans-=solve(n,s,m);
	rep(i,0,m) if (s[i]=='R') s[i]='D'; else s[i]='R';
	ans-=solve(n,s,m);
	printf("%lld\n",ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
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

const int N=401000;
int n,x,m,_;
int cnt[N];
void solve() {
	scanf("%d",&n);
	map<int,int> hs;
	rep(i,0,n) {
		scanf("%d",&x);
		hs[x]++;
	}
	m=0;
	for (auto p:hs) {
		cnt[m++]=p.se;
	}
	reverse(cnt,cnt+m);
	rep(i,1,m) cnt[i]+=cnt[i-1];
	VI ans{0,0,0,0};
	rep(i,0,m) {
		// g  cnt[i]
		int a=lower_bound(cnt,cnt+m,2*cnt[i]+1)-cnt;
		if (a==m) continue;
		int f1=cnt[a]-cnt[i];
		int b=upper_bound(cnt,cnt+m,n/2)-cnt-1;
		int f2=cnt[b]-f1-cnt[i];
		if (f1>cnt[i]&&f2>cnt[i]) {
			ans=max(ans,VI{cnt[i]+f1+f2,cnt[i],f1,f2});
		}
		// b 2*cnt[i]+1
	}
	printf("%d %d %d\n",ans[1],ans[2],ans[3]);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=2010;
int n,a[N],cnt[N];
int ans;
int main() {
	scanf("%d",&n);
	ans=n;
	VI v;
	rep(i,0,n) {
		scanf("%d",a+i);
		v.pb(a[i]);
	}
	sort(all(v)); v.erase(unique(all(v)),v.end());
	int m=SZ(v);
	rep(i,0,n) {
		a[i]=lower_bound(all(v),a[i])-v.begin()+1;
	}
	rep(i,0,n) cnt[a[i]]++;
	int ms=0;
	rep(i,1,m+1) ms=max(ms,cnt[i]);
	if (ms<=1) {
		puts("0");
		return 0;
	}
	rep(l,0,n+1) {
		rep(i,1,m+1) cnt[i]=0;
		int ms=0;
		rep(i,0,l) {
			cnt[a[i]]++;
			ms=max(ms,cnt[a[i]]);
		}
		if (ms<=1) ans=min(ans,n-l);
		per(j,l,n) {
			cnt[a[j]]++;
			ms=max(ms,cnt[a[j]]);
			if (ms<=1) ans=min(ans,j-l);
		}
	}
	printf("%d\n",ans);
}
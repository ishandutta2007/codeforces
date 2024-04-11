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

int n,pr[501000],cnt[501000],ans[501000];
int main() {
	scanf("%d",&n);
	for (int i=2;i<=n;i++) if (!pr[i]) {
		for (int j=i;j<=n;j+=i) if (pr[j]==0) pr[j]=j/i;
	}
	pr[1]=1;
	rep(i,1,n+1) cnt[pr[i]]++;
	int x=0;
	rep(i,1,n+1) {
		rep(j,0,cnt[i]) ans[++x]=i;
	}
	rep(i,2,n+1) printf("%d ",ans[i]); puts("");
}
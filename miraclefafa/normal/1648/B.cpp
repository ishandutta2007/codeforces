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

const int N=1010000;
int n,c,vis[N],a[N],cnt[N];
bool solve() {
	scanf("%d%d",&n,&c);
	rep(i,1,c+1) vis[i]=0,cnt[i]=0;
	rep(i,0,n) {
		scanf("%d",a+i);
		vis[a[i]]=1;
		cnt[a[i]]=1;
	}
	rep(i,1,c+1) vis[i]+=vis[i-1];
	if (!vis[1]) {
		return 0;
	}
	rep(i,1,c+1) {
		for (int j=i;j<=c;j+=i) {
			int r=min(j+i-1,c);
			if (vis[r]-vis[j-1]) {
				if (!cnt[j/i]&&cnt[i]) return 0;
			}
		}
	}
	return 1;
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		puts(solve()?"Yes":"No");
	}
}
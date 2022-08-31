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
int a[N],_,n,m;
void solve() {
	map<int,int> cnt;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		scanf("%d",a+i);
		cnt[a[i]%m]++;
	}
	int ans=0;
	for (int i=0;i*2<=m;i++) {
		if (i==0||i*2==m) {
			if (cnt[i]) ans+=1;
			continue;
		}
		int x=cnt[i],y=cnt[m-i];
		if (x==0&&y==0) continue;
		ans+=max(1,abs(x-y));
	}
	printf("%d\n",ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}
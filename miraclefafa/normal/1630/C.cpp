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
int n,a[N],lst[N];;
VI pos[N];
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",a+i);
		pos[a[i]].pb(i);
	}
	rep(i,1,n+1) if (!pos[i].empty()) {
		for (auto x:pos[i]) lst[x]=pos[i].back();
	}
	int rt=0,prt=0;
	int ans=n;
	rep(i,1,n+1) {
		if (i>prt) ans--,prt=rt=lst[i];
		else if (i==prt) {
			ans--;
			prt=rt;
		} else {
			rt=max(rt,lst[i]);
		}
	}
	printf("%d\n",ans);
}
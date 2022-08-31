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

int n,m,k;
vector<pair<int,string>> ans,pans;

int main() {
	scanf("%d%d%d",&n,&m,&k);
	if (k>4*n*m-2*n-2*m) {
		puts("NO");
		return 0;
	}
	ans.pb(mp(m-1,"R"));
	rep(j,0,n-1) {
		ans.pb(mp(1,"D"));
		ans.pb(mp(m-1,"LUD"));
		ans.pb(mp(m-1,"R"));
	}
	ans.pb(mp(n-1,"U"));
	ans.pb(mp(m-1,"L"));
	for (auto x:ans) {
		if (k>=SZ(x.se)*x.fi) {
			k-=SZ(x.se)*x.fi;
			if (x.fi) pans.pb(x);
		} else {
			int l=SZ(x.se);
			if (k/l) pans.pb(mp(k/l,x.se));
			if (k%l) pans.pb(mp(1,x.se.substr(0,k%l)));
			k=0;
		}
	}
	puts("YES");
	printf("%d\n",SZ(pans));
	for (auto x:pans) printf("%d %s\n",x.fi,x.se.c_str());
}
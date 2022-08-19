#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int n,m;
vector<PII> e;
void add(int u,int v) {
	e.pb(mp(u,v));
}
void fail() { puts("-1"); exit(0); }
int main() {
	scanf("%d%d",&n,&m);
	if (m==1||m>=4) fail();
	if (n<=3) fail();
	if (m==2) {
		if (n==4) fail();
		rep(i,1,n) add(i,i+1);
	} else if (m==3) {
		add(1,2); add(2,3); add(3,4);
		rep(i,5,n+1) add(2,i),add(3,i);
	}
	printf("%d\n",SZ(e));
	for (auto p:e) printf("%d %d\n",p.fi,p.se);
}
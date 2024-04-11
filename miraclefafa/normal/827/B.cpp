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

int n,k;
vector<PII> e;
multiset<PII> st;
int main() {
	scanf("%d%d",&n,&k);
	rep(i,0,k) st.insert(mp(0,1));
	rep(i,2,n+1) {
		auto it=st.begin();
		e.pb(mp(i,it->se));
		st.insert(mp(it->fi+1,i));
		st.erase(it);
	}
	auto it=(--st.end()),pit=it; --pit;
	printf("%d\n",(it->fi)+(pit->fi));
	rep(i,0,n-1) {
		printf("%d %d\n",e[i].fi,e[i].se);
	}
}
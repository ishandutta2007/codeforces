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

const int N=101000;
int n,c[N],x;
set<PII> hs;
ll ret;
int query(int x) { int s=0; for (;x;x-=x&-x) s+=c[x]; return s;}
void modify(int x,int s) { for (;x<=n;x+=x&-x) c[x]+=s; }
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&x),hs.insert(mp(x,i));
	rep(i,1,n+1) modify(i,1);
	PII pos=mp(0,0);
	rep(i,1,n+1) {
		pos.fi=hs.begin()->fi;
		auto it=hs.lower_bound(pos);
		if (it->fi==hs.begin()->fi) {
			ret+=query(it->se)-query(pos.se);
		} else {
			it=hs.begin();
			ret+=query(n)-query(pos.se)+query(it->se);
		}
//		printf("%d %d %lld\n",it->fi,it->se,ret);
		modify(it->se,-1);
		pos=*it; hs.erase(it);
	}
	printf("%lld\n",ret);
}
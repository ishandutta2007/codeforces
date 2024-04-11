#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <queue>
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

const int N=201000;
vector<PII> vec;
int n,a,b,c,d,cnt[N];
ll ret;
priority_queue<PII> p;
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if (a<=d&&b<=c) continue;
		ret-=b; ret-=d;
		if (a+b<=c+d) {
			if (a>d) ret+=a+b;
			else ret+=c+d; 
		} else vec.pb(mp(a+b,c+d));
	}
	int m=SZ(vec);
	rep(i,0,m) p.push(mp(vec[i].fi,i));
	rep(i,0,m) {
		int r=p.top().se;
		ret+=p.top().fi; p.pop();
		if (cnt[r]==0) p.push(mp(vec[r].se,r)),++cnt[r];
		r=p.top().se; p.pop();
		if (cnt[r]==0) p.push(mp(vec[r].se,r)),++cnt[r];
	}
	printf("%lld\n",ret);
}
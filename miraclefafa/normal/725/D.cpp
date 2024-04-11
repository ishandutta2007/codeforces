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

const int N=301000;
int n;
priority_queue<ll> q;
pair<ll,ll> p[N];
ll t,w;
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%lld%lld",&t,&w);
		p[i]=mp(t,w);
	}
	sort(p+1,p+n);
	reverse(p+1,p+n);
	int r=1;
	while (r<n&&p[r].fi>p[0].fi) {
		q.push(-(p[r].se-p[r].fi+1));
		++r;
	}
	int ret=r,f=0;
	while (!q.empty()) {
		ll c=-q.top(); q.pop();
		p[0].fi-=c;
		if (p[0].fi<0) break;
		f++;
		while (r<n&&p[r].fi>p[0].fi) {
			q.push(-(p[r].se-p[r].fi+1));
			++r;
		}
		ret=min(ret,r-f);
	}
	printf("%d\n",ret);
}
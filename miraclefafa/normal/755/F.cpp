#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
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

const int N=1010000;
int n,k,p[N],vis[N];
map<int,int> s;
bitset<1000001> f;
VI a,b;
int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) scanf("%d",p+i);
	rep(i,1,n+1) if (!vis[i]) {
		int q=i,cnt=1;
		while (1) {
			q=p[q]; vis[q]=1;
			if (q==i) break;
			cnt++;
		}
		s[cnt]++;
		a.pb(cnt);
	}
	b.clear();
	while (!s.empty()) {
		auto p=*s.begin(); s.erase(s.begin());
		if (p.se%2==0) {
			b.pb(p.fi); b.pb(p.fi);
			if (p.se!=2) s[p.fi+p.fi]+=(p.se-2)/2;
		} else {
			b.pb(p.fi);
			if (p.se!=1) s[p.fi+p.fi]+=(p.se-1)/2;
		}
	}
	f[0]=1;
	for (auto p:b) f|=f<<p;
	if (f[k]) printf("%d ",k); else printf("%d ",k+1);
	int r=0,t=0;
	for (auto p:a) {
		r+=p/2; t+=p%2;
	}
	if (k<=r) printf("%d\n",2*k); else printf("%d\n",min(2*r+(k-r),n));
}
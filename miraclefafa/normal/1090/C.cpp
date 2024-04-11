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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int n,m,x,y,tot,req[N],p[N];
unordered_set<int> e[N],dif;
vector<VI> ans;

int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		scanf("%d",&x);
		tot+=x;
		rep(j,0,x) {
			scanf("%d",&y);
			e[i].insert(y);
		}
		p[i]=i;
	}
	sort(p,p+n,[&](int a,int b) {
		return SZ(e[a])>SZ(e[b]);
	});
	rep(i,0,tot) {
		req[i%n]++;
	}
	int p1=0,p2=n-1;
	dif=e[p[p1]];
//	printf("diff:"); for (auto p:dif) printf(" %d",p); puts("");
	for (auto x:e[p[p2]]) if (dif.count(x)) dif.erase(x);
//	printf("diff:"); for (auto p:dif) printf(" %d",p); puts("");

	while (p1<p2) {
//		printf("%d %d\n",p1,p2);
		if (SZ(e[p[p1]])==req[p1]) {
			// recover
			p1++;
			if (p1>=p2) break;
			dif=e[p[p1]];
			for (auto x:e[p[p1]]) {
				if (e[p[p2]].count(x)) dif.erase(x);
			}
			continue;
		}
		if (SZ(e[p[p2]])==req[p2]) {
			for (auto x:e[p[p2]]) {
				if (e[p[p1]].count(x)) dif.insert(x);
			}
			--p2;
			if (p1>=p2) break;
			for (auto x:e[p[p2]]) {
				if (dif.count(x)) dif.erase(x);
			}
			continue;
		}
		int x=*dif.begin();
		auto movee=[&](int p,int q,int c) {
			assert(!e[q].count(c));
			assert(e[p].count(c));
			assert(dif.count(c));
			e[p].erase(c);
			e[q].insert(c);
			dif.erase(c);
			ans.pb(VI{p,q,c});
		};
		movee(p[p1],p[p2],x);
	}
	printf("%d\n",SZ(ans));
	for (auto p:ans) printf("%d %d %d\n",p[0]+1,p[1]+1,p[2]);
}
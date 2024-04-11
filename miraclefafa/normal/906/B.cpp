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
// head

const int N=101000;
int n,m,p[N],px[N],py[N],q[N];

bool adj(int u,int v) {
	if (u>v) swap(u,v);
	if (px[u]==px[v]&&py[u]+1==py[v]) return 1;
	if (py[u]==py[v]&&px[u]+1==px[v]) return 1;
	return 0;
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n*m) px[i]=i/m,py[i]=i%m;
	while (clock()<=1.9*CLOCKS_PER_SEC) {
		rep(i,0,n*m) p[i]=i;
		random_shuffle(p,p+n*m);
		set<PII> hs;
		rep(i,0,n*m) hs.insert(mp(p[i],i));
		bool val=1;
		rep(i,0,n*m) {
			int x=i/m,y=i%m;
			auto it=hs.begin();
			bool suc=0;
			while (1) {
				suc=1;
				q[i]=it->se;
				if (y&&adj(q[i],q[i-1])) { suc=0; }
				if (x&&adj(q[i],q[i-m])) { suc=0; }
				if (suc) { hs.erase(it); break; }
				it++;
				if (it==hs.end()) break;
			}
			if (suc==0) { val=0; break; }
		}
		if (val) {
			puts("YES");
			rep(i,0,n*m) {
				printf("%d ",q[i]+1);
				if (i%m==m-1) puts("");
			}
			return 0;
		}
	}
	puts("NO");
}
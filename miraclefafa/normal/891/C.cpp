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

const int N=501000;

int n,m,u[N],v[N],w[N],f[N],p[N],mt[N],T,wa[N];
int Q,k,id;
vector<int> eg[N];
vector<PII> qw[N];

int find(int x) {
	if (f[x]!=x) return f[x]=find(f[x]); else return x;
}
int find2(int x) {
	if (mt[x]!=T) mt[x]=T,p[x]=f[x];
	if (p[x]!=x) return p[x]=find2(p[x]); else return x;
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d%d",u+i,v+i,w+i);
		eg[w[i]].pb(i);
	}
	rep(i,1,n+1) f[i]=i;
	scanf("%d",&Q);
	rep(i,0,Q) {
		scanf("%d",&k);
		rep(j,0,k) {
			scanf("%d",&id);
			--id;
			qw[w[id]].pb(mp(i,id));
		}
	}
	rep(i,1,500001) {
		sort(all(qw[i]));
		rep(j,0,SZ(qw[i])) {
			int x=u[qw[i][j].se],y=v[qw[i][j].se];
			find(x); find(y);
		}
		rep(j,0,SZ(qw[i])) {
			if (j==0||qw[i][j].fi!=qw[i][j-1].fi) T++;
			int x=u[qw[i][j].se],y=v[qw[i][j].se];
			if (find2(x)==find2(y))	wa[qw[i][j].fi]=1;
			p[find2(x)]=find2(y);
		}
		for (auto id:eg[i]) {
			int x=u[id],y=v[id];
			f[find(x)]=find(y);
		}
	}
	rep(i,0,Q) puts(wa[i]?"NO":"YES");
}
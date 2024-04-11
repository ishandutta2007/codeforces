#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

typedef pair<PII,PII> PIII;
vector<PII> E,ans;
vector<PIII> ret,ret2;
int e[1010][1010],u,v,n;
void gao(int l,int r,vector<PIII> &res) {
	if (l+1==r) return;
	int md=(l+r)>>1; // [l,md-1] [md+1,r]
	E.clear();
	rep(i,l,md) per(j,md+1,r+1) if (e[i][j]) {
		E.pb(mp(i,j));
	}
	if (!SZ(E)) {
		gao(l,md,res);
		gao(md,r,res);
		return;
	}
	int cu=E[0].fi,cv=E[0].se;
	rep(i,0,SZ(E)) {
		int nv=0;
		if (i==SZ(E)-1) nv=md;
		else if (E[i].fi==E[i+1].fi) nv=E[i+1].se;
		else nv=E[i+1].fi;
		e[cu][cv]=e[cv][cu]=0;
		e[0][nv]=e[nv][0]=1;
		res.pb(mp(mp(cu,cv),mp(0,nv)));
		if (i!=SZ(E)-1) {
			if (E[i].fi==E[i+1].fi) cv=E[i+1].se;
			else cu=E[i+1].fi;
		}
	}
	gao(l,md,res);
	gao(md,r,res);
}
int main() {
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i,0,n-3) {
		scanf("%d%d",&u,&v);
		--u;--v;
		e[u][v]=1;
		e[v][u]=1;
	}
	gao(1,n-1,ret);
	memset(e,0,sizeof(e));
	rep(i,0,n-3) {
		scanf("%d%d",&u,&v);
		--u; --v;
		e[u][v]=1;
		e[v][u]=1;
	}
	gao(1,n-1,ret2);
	for (auto p:ret) ans.pb(p.fi);
	reverse(all(ret2));
	for (auto p:ret2) ans.pb(p.se);
	printf("%d\n",SZ(ans));
	rep(i,0,SZ(ans)) printf("%d %d\n",ans[i].fi+1,ans[i].se+1);
}
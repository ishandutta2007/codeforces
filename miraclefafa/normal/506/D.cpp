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

const int N=101000;
int n,m,a,b,c,q;
vector<PII> e[N];
unordered_map<int,int> pp[N];
VI vec;
int u[N],v[N],ret[N],f[N],vis[N],rt[N];
int find(int x) { return f[x]==x?x:f[x]=find(f[x]);}
int main() {
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d%d",&a,&b,&c);
		e[c].pb(mp(a,b));
	}
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d%d",u+i,v+i);
		rt[i]=-1;
		if (pp[u[i]].count(v[i])) rt[i]=pp[u[i]][v[i]];
		else pp[u[i]][v[i]]=pp[v[i]][u[i]]=i;
	}
	int lim=sqrt(m);
	rep(i,1,m+1) {
		vec.clear();
		rep(j,0,SZ(e[i])) {
			vis[e[i][j].fi]=vis[e[i][j].se]=i;
			vec.pb(e[i][j].fi); vec.pb(e[i][j].se);
		}
		sort(all(vec));
		vec.erase(unique(all(vec)),vec.end());
		rep(j,0,SZ(vec)) f[vec[j]]=vec[j];
		rep(j,0,SZ(e[i])) {
			a=e[i][j].fi; b=e[i][j].se;
			f[find(a)]=find(b);
		}
		if (SZ(e[i])<=lim) {
			rep(j,0,SZ(vec)) rep(k,j+1,SZ(vec)) {
				a=vec[j],b=vec[k];
				if (find(a)==find(b)&&pp[a].count(b)) ret[pp[a][b]]++;
			}
		} else {
			rep(j,0,q) {
				a=u[j],b=v[j];
				if (vis[a]==i&&vis[b]==i&&find(a)==find(b)) ret[j]++;
			}
		}
	}
	rep(i,0,q) {
		if (rt[i]!=-1) ret[i]=ret[rt[i]];
		printf("%d\n",ret[i]);
	}
}
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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=1010000;
int n,m,mr[N],mc[N];
pair<int,PII> p[N];
int val[N],dp[N],f[N];
VI num[N],e[N];
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) rep(j,0,m) {
		scanf("%d",&p[i*m+j].fi);
		p[i*m+j].se=mp(i,j);
		val[i*m+j]=p[i*m+j].fi;
		f[i*m+j]=i*m+j;
	}
	sort(p,p+n*m);
	rep(i,0,n) mr[i]=-1;
	rep(i,0,m) mc[i]=-1;
	rep(i,0,n*m) {
		int r=p[i].se.fi,c=p[i].se.se;
		if (mr[r]!=-1) {
			if (val[mr[r]]==p[i].fi) f[find(r*m+c)]=find(mr[r]);
			else e[r*m+c].pb(mr[r]);
		}
		if (mc[c]!=-1) {
			if (val[mc[c]]==p[i].fi) f[find(r*m+c)]=find(mc[c]);
			else e[r*m+c].pb(mc[c]);
		}
		mr[r]=r*m+c; mc[c]=r*m+c;
	}
	rep(i,0,n*m) num[find(i)].pb(i);
	rep(i,0,n*m) {
		int r=p[i].se.fi,c=p[i].se.se,id=r*m+c;
		if (find(id)==id) {
			int ret=0;
			for (auto u:num[id]) for (auto v:e[u]) ret=max(ret,dp[v]);
			for (auto u:num[id]) dp[u]=ret+1;
		}
	}
	rep(i,0,n) {
		rep(j,0,m) printf("%d ",dp[i*m+j]);
		puts("");
	}
}
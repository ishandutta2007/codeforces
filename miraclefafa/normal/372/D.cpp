#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
//#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<(int)n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ACCU accumulate
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=acos(0)*2;
ll powmod(ll a,ll b) {ll res=1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int N=201000;
set<int> mp;
int dep[N],f[N],F[N][20],id[N],cnt[N];
int y[N],nxt[N],fst[N],tot,ans,n,k,u,v;

void add(int u,int v) {tot++;y[tot]=v;nxt[tot]=fst[u];fst[u]=tot;}
void dfs(int u,int p) { f[u]=p;id[cnt[u]=++tot]=u;
	for (int j=fst[u];j;j=nxt[j]) if (y[j]!=p) dep[y[j]]=dep[u]+1,dfs(y[j],u);}
int LCA(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	for (int k=dep[v]-dep[u],j=17;j>=0;j--) if ((k>>j)&1) v=F[v][j],k^=(1<<j);
	if (u==v) return u;
	for (int k=17;f[u]!=f[v];u=F[u][k],v=F[v][k]) for (;k && F[u][k]==F[v][k];k--);
	return f[u];
}
void modify(char ch,int u) {
	typeof(mp.begin()) it=mp.lower_bound(cnt[u]);
	if (*it==cnt[u]) mp.erase(cnt[u]),it=mp.lower_bound(cnt[u]);
	if (!mp.size()) {if (ch=='+') mp.insert(cnt[u]);return;}
	int q=id[(it==mp.end())?*mp.begin():*it],p=id[(it--==mp.begin())?*(--mp.end()):*it];
	int dt=dep[u]-dep[LCA(p,u)]-dep[LCA(q,u)]+dep[LCA(p,q)];
	if (ch=='+') ans+=dt,mp.insert(cnt[u]); else ans-=dt;	
}
bool check(int v) {
	ans=0;
	mp.clear();
	rep(i,1,v) modify('+',i);
	rep(i,v,n+1) {
		modify('+',i);
		if (ans+1<=k) return 1;
		modify('-',i+1-v);
	}
	return 0;
} 
int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%d%d",&u,&v),add(u,v),add(v,u);
	tot=0;dfs(1,0);id[n+1]=n+1;
	rep(i,1,n+1) F[i][0]=f[i];
	rep(j,1,18) rep(i,1,n+1) F[i+1][j]=F[F[i+1][j-1]][j-1];
	int l=1,r=n+1;
	while (l+1<r) {
		int md=(l+r)>>1;
		if (check(md)) l=md; else r=md;
	}
	printf("%d\n",l);
	return 0;
}
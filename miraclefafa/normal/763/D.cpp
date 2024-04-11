#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef vector<int> VI;
// head
typedef unsigned long long ull;

const int N=101000;
ull seed[2*N],hv[N],hv2[N];
map<ull,int> hp;
int ansv,ansp,n,u,v,tot,hd[N],hd2[N],hs[N*2],cnt;
VI e[N];
void dfs(int u,int f) {
	hv[u]=seed[0];
	for (auto v:e[u]) {
		if (v==f) continue;
		dfs(v,u);
		hv[u]+=seed[hd[v]];
	}
	if (!hp.count(hv[u])) hp[hv[u]]=++tot;
	hd[u]=hp[hv[u]];
}
void dfs2(int u,int f) {
	ull h0=hv[u];
	if (f!=0) h0+=seed[hd2[u]];
	for (auto v:e[u]) {
		if (v==f) continue;
		hv2[v]=h0-seed[hd[v]];
		if (!hp.count(hv2[v])) hp[hv2[v]]=++tot;
		hd2[v]=hp[hv2[v]];
	}
	for (auto v:e[u]) {
		if (v==f) continue;
		dfs2(v,u);
	}
}

void dfs3(int u,int f) {
	if (cnt>ansv) {
		ansv=cnt; ansp=u;
	}
	for (auto v:e[u]) {
		if (v==f) continue;
		cnt-=!(--hs[hd[v]]);
		cnt+=!(hs[hd2[v]]++);
		dfs3(v,u);
		cnt-=!(--hs[hd2[v]]);
		cnt+=!(hs[hd[v]]++);
	}
}
int main() {
	scanf("%d",&n);
	rep(i,0,2*n+2) seed[i]=((ull)rand()<<40)+((ull)rand()<<20)+(ull)rand();
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	dfs(1,0);
	dfs2(1,0);
	rep(i,2,n+1) cnt+=!(hs[hd[i]]++);
	ansp=1; ansv=cnt;
	dfs3(1,0);
	printf("%d\n",ansp);
}
#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MOD=1000000007;

int n,nq;
int fst[100000]; // n->de
int nxt[200000]; // de->de
int to[200000]; // de->n
int len[100000]; // e->val

int par[100000];
ll d[100000];
ll upcnt[100000],upsum[100000],upsum2[100000];
ll dncnt[100000],dnsum[100000],dnsum2[100000];

int nid,sid[100000],tid[100000];
int up[100000][21];

void dfs(int at) {
	sid[at]=nid++;
	dncnt[at]=1; dnsum[at]=0; dnsum2[at]=0;
	for(int x=fst[at];x!=-1;x=nxt[x]) {
		if(to[x]==par[at]) continue;
		par[to[x]]=at;
		d[to[x]]=d[at]+len[x/2];
		dfs(to[x]);
		dncnt[at]+=dncnt[to[x]];
		dnsum[at]+=dncnt[to[x]]*len[x/2]+dnsum[to[x]]; dnsum[at]%=MOD;
		dnsum2[at]+=dncnt[to[x]]*((ll)len[x/2]*len[x/2]%MOD)+2*dnsum[to[x]]*len[x/2]+dnsum2[to[x]]; dnsum2[at]%=MOD;
	}
	tid[at]=nid++;
}
void dfs2(int at) {
	for(int x=fst[at];x!=-1;x=nxt[x]) {
		if(to[x]==par[at]) continue;
		upcnt[to[x]]=upcnt[at]+dncnt[at]-dncnt[to[x]];
		upsum[to[x]]=upsum[at]+dnsum[at]-dncnt[to[x]]*len[x/2]-dnsum[to[x]]+upcnt[to[x]]*len[x/2]; upsum[to[x]]%=MOD; if(upsum[to[x]]<0) upsum[to[x]]+=MOD;
		upsum2[to[x]]=upsum2[at]+dnsum2[at]-dncnt[to[x]]*((ll)len[x/2]*len[x/2]%MOD)-2*dnsum[to[x]]*len[x/2]-dnsum2[to[x]]-upcnt[to[x]]*((ll)len[x/2]*len[x/2]%MOD)+2*upsum[to[x]]*len[x/2]; upsum2[to[x]]%=MOD; if(upsum2[to[x]]<0) upsum2[to[x]]+=MOD;
		dfs2(to[x]);
	}
}
bool isancestor(int u,int v) { return sid[u]<=sid[v]&&sid[v]<=tid[u]; }
int getlca(int u,int v) {
	if(isancestor(u,v)) return u;
	if(isancestor(v,u)) return v;
	for(int k=20;k>=0;--k) {
//		printf("%d -> %d %c\n",u,up[u][k],isancestor(up[u][k],v)?'X':'V');
		if(!isancestor(up[u][k],v)) u=up[u][k];
	}
	return par[u];
}


void run() {
	scanf("%d",&n);
	REP(i,n) fst[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d%d",&a,&b,&len[i]); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}

	nid=0; par[0]=-1; d[0]=0; dfs(0);
	upcnt[0]=0; upsum[0]=0; upsum2[0]=0; dfs2(0);
	//REP(i,n) printf("%d: d=%lld, up=(%lld,%lld,%lld) dn=(%lld,%lld,%lld)\n",i,d[i],upcnt[i],upsum[i],upsum2[i],dncnt[i],dnsum[i],dnsum2[i]);
	REP(j,n) up[j][0]=par[j]==-1?j:par[j];
	REP(i,20) REP(j,n) up[j][i+1]=up[up[j][i]][i];


	scanf("%d",&nq);
	REP(qi,nq) {
		int u,v; scanf("%d%d",&u,&v); --u,--v;
		if(isancestor(v,u)) {
			ll ret=upsum2[u]+dnsum2[u];
			ll plen=(d[u]-d[v])%MOD,cnt=upcnt[v],sum=upsum[v],sum2=upsum2[v];
			ret-=2*(cnt*(plen*plen%MOD)+2*plen*sum+sum2);
			ret%=MOD; if(ret<0) ret+=MOD;
			cout<<ret<<endl;
		} else {
			int w=getlca(u,v);
			ll ret=-upsum2[u]-dnsum2[u];
			ll plen=(d[v]+d[u]-2*d[w])%MOD,cnt=dncnt[v],sum=dnsum[v],sum2=dnsum2[v];
			ret+=2*(cnt*(plen*plen%MOD)+2*plen*sum+sum2);
			ret%=MOD; if(ret<0) ret+=MOD;
			cout<<ret<<endl;
		}
	}
}

int main() {
	run();
	return 0;
}
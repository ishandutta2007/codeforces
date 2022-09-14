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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MAXM=100000;

int n,m,nq;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];

int nc;
int comp[MAXN];
int diam[MAXN];
int off[MAXN+1];
int lst[MAXN];
int val[MAXN];
ll sumval[MAXN+1];
int cnt[MAXN];
int dmx[MAXN],dvia[MAXN],dmx2[MAXN];


void dfs(int at,int par,int c) {
	//printf("dfs(%d,%d,%d)\n",at,par,c);
	comp[at]=c; dmx[at]=dmx2[at]=0; dvia[at]=-1; lst[off[c+1]++]=at;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		dfs(to,at,c);
		int d=dmx[to]+1;
		if(d>dmx[at]) dmx2[at]=dmx[at],dmx[at]=d,dvia[at]=to; else if(d>dmx2[at]) dmx2[at]=d;
	}
}
void dfs2(int at,int par) {
	if(par!=-1) {
		int d=1+(dvia[par]!=at?dmx[par]:dmx2[par]);
		if(d>dmx[at]) dmx2[at]=dmx[at],dmx[at]=d,dvia[at]=par; else if(d>dmx2[at]) dmx2[at]=d;
	}
	//printf("%d: dmx=%d dvia=%d dmx2=%d\n",at,dmx[at],dvia[at],dmx2[at]);
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		dfs2(to,at);
	}
}

void makecomp(int s) {
	int c=nc++;
	off[c+1]=off[c];
	dfs(s,-1,c);
	dfs2(s,-1);
	FOR(i,off[c],off[c+1]) val[i]=dmx[lst[i]]; sort(val+off[c],val+off[c+1]);
	diam[c]=val[off[c+1]-1];
	cnt[c]=off[c+1]-off[c];
	//printf("%d [diam=%d cnt=%d]:",c,diam[c],cnt[c]); FOR(i,off[c],off[c+1]) printf(" %d",val[i]); puts("");
}

map<pair<int,int>,double> mem;

double solve(int a,int b) {
	if(cnt[a]>cnt[b]) swap(a,b);
	int have=max(diam[a],diam[b]);
	//printf("a:"); REP(i,cnt[a]) printf(" %d",val[off[a]+i]); printf(" [%d]\n",diam[a]);
	//printf("b:"); REP(i,cnt[b]) printf(" %d",val[off[b]+i]); printf(" [%d]\n",diam[b]);
	double sum=0;
	REP(i,cnt[a]) {
		int j=lower_bound(val+off[b],val+off[b+1],have-val[off[a]+i]-1)-(val+off[b]);
		//printf("\t%d: %d times %d, %d times %d, sum of b=%lld\n",val[off[a]+i],j,have,cnt[b]-j,1+val[off[a]+i],sumval[off[b+1]]-sumval[off[b]+j]);
		sum+=(ll)j*have;
		sum+=(ll)(cnt[b]-j)*(1+val[off[a]+i]);
		sum+=sumval[off[b+1]]-sumval[off[b]+j];
	}
	return sum/cnt[a]/cnt[b];
}


void run() {
	scanf("%d%d%d",&n,&m,&nq);
	REP(i,n) ghead[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a;
	}

	REP(i,n) comp[i]=-1; off[0]=0;
	REP(i,n) if(comp[i]==-1) makecomp(i);
	sumval[0]=0; REP(i,off[nc]) sumval[i+1]=sumval[i]+val[i];

	mem.clear();
	REP(i,nq) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		a=comp[a],b=comp[b]; if(a>b) swap(a,b);
		if(a==b) { printf("-1\n"); continue; }
		if(mem.count(MP(a,b))) { printf("%.9lf\n",mem[MP(a,b)]); continue; }
		double ans=solve(a,b);
		mem[MP(a,b)]=ans;
		printf("%.9lf\n",ans);
	}
}

int main() {
	run();
	return 0;
}
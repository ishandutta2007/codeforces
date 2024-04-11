#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MOD=1000000007;
const int MAXCYC=42;
const int MAXBITS=17;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { if((a-=b)<0) a+=MOD; }
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int n,m;
vector<pair<int,int>> adj[MAXN];

int preidx[MAXN],npre;
int par[MAXN],parlen[MAXN];

vector<int> cyc[MAXCYC]; int ncyc;

void dfs(int at) {
	preidx[at]=npre++;
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first,len=adj[at][i].second; if(to==par[at]) continue;
		if(preidx[to]!=-1) {
			if(preidx[to]<preidx[at]) { assert(ncyc<MAXCYC); cyc[ncyc].clear(); cyc[ncyc].PB(len); for(int x=at;x!=to;x=par[x]) cyc[ncyc].PB(parlen[x]); ++ncyc; }
			continue;
		} else {
			par[to]=at,parlen[to]=len;
			dfs(to);
		}
	}
}

void whtmod(int *a,int nbits) {
	REP(bit,nbits) for(int off=0;off<(1<<nbits);off+=2<<bit) REP(i,1<<bit) { int x=a[off+i],y=a[off+(1<<bit)+i]; a[off+i]=a[off+(1<<bit)+i]=x; inc(a[off+i],y); dec(a[off+(1<<bit)+i],y); }
}
void whtll(ll *a,int nbits) {
	REP(bit,nbits) for(int off=0;off<(1<<nbits);off+=2<<bit) REP(i,1<<bit) { ll x=a[off+i],y=a[off+(1<<bit)+i]; a[off+i]=a[off+(1<<bit)+i]=x; a[off+i]+=y; a[off+(1<<bit)+i]-=y; }
}

ll acan[1<<MAXBITS];
int aways[1<<MAXBITS];

ll bcan[1<<MAXBITS];
int bways[1<<MAXBITS];

pair<int,int> solve() {
	npre=0; REP(i,n) preidx[i]=-1;
	ncyc=0; par[0]=-1,parlen[0]=0; dfs(0);
	//REP(i,ncyc) { printf("cyc%d:",i); REPSZ(j,cyc[i]) printf(" %d",cyc[i][j]); puts(""); }
	
	int sum=0; REP(at,n) REPSZ(i,adj[at]) { int to=adj[at][i].first,len=adj[at][i].second; if(at<to) sum^=len; }
	//printf("sum=%d\n",sum);
	
	memset(acan,0,sizeof(acan)); acan[sum]=1;
	memset(aways,0,sizeof(aways)); inc(aways[sum],1);
	whtmod(aways,MAXBITS);
	REP(i,ncyc) {
		memset(bcan,0,sizeof(bcan)); REPSZ(j,cyc[i]) bcan[cyc[i][j]]=1;
		memset(bways,0,sizeof(bways)); REPSZ(j,cyc[i]) inc(bways[cyc[i][j]],1);
		whtll(acan,MAXBITS);
		whtll(bcan,MAXBITS);
		REP(k,1<<MAXBITS) acan[k]*=bcan[k];
		whtll(acan,MAXBITS);
		REP(k,1<<MAXBITS) acan[k]=acan[k]!=0?1:0;
		whtmod(bways,MAXBITS);
		REP(k,1<<MAXBITS) aways[k]=(ll)aways[k]*bways[k]%MOD;
	}
	whtmod(aways,MAXBITS);
	int mlt=pw(1<<MAXBITS,MOD-2);
	REP(k,1<<MAXBITS) aways[k]=(ll)aways[k]*mlt%MOD;
	REP(k,1<<MAXBITS) if(acan[k]) return MP(k,aways[k]);
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; adj[a].PB(MP(b,c)); adj[b].PB(MP(a,c)); }
	pair<int,int> ans=solve();
	printf("%d %d\n",ans.first,ans.second);
}

int main() {
	run();
	return 0;
}
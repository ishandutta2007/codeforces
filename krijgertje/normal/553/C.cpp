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
const int MOD=1000000007;

int n,m;
int par[MAXN];
int rnk[MAXN];
int lovepar[MAXN];

int combine(int a,int b) { return a==0&&b==0||a==1&&b==1?1:0; }
void compress(int x) {
	if(par[x]==x) return;
	compress(par[x]);
	lovepar[x]=combine(lovepar[x],lovepar[par[x]]);
	par[x]=par[par[x]];
}

bool unite(int x,int y,int love) {
	compress(x); compress(y);
	if(par[x]==par[y]) return combine(lovepar[x],lovepar[y])==love;
	if(rnk[par[x]]<rnk[par[y]]) swap(x,y);
	lovepar[par[y]]=combine(lovepar[x],combine(lovepar[y],love));
	par[par[y]]=par[x];
	if(rnk[par[x]]==rnk[par[y]]) ++rnk[par[x]];
	return true;
}


void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) par[i]=i,rnk[i]=0,lovepar[i]=1;
	bool ok=true;
	REP(i,m) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b;
		if(!unite(a,b,c)) ok=false;
		//REP(j,n) printf("%d: par=%d, lovepar=%d\n",j,par[j],lovepar[j]);
	}
	if(!ok) { printf("0\n"); return; }
	int cnt=0; REP(i,n) if(par[i]==i) ++cnt;
	int ret=1; REP(i,cnt-1) ret=2*ret%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
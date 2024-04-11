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

const int MAXN=200000;

int n,nparts;
int a[MAXN];
int ans[MAXN+1];

int par[MAXN+1];

bool solve() {
	par[0]=0; REP(i,n) par[i+1]=(par[i]^(a[i]&1));
	if(par[n]!=(nparts&1)) return false;
	//printf("par:"); REPE(i,n) printf(" %d",par[i]); puts("");
	int nans=0;
	REP(i,n) if(par[i]==(nans&1)&&nans<nparts) ans[nans++]=i;
	ans[nans]=n;
	return nans>=nparts;
}

void run() {
	scanf("%d%d",&n,&nparts);
	REP(i,n) scanf("%d",&a[i]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	FORE(i,1,nparts) { if(i!=1) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}
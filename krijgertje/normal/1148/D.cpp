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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=300000;

int n;
int a[MAXN],b[MAXN];
int nans;
int ans[MAXN];

int ncur;
int cur[MAXN];
int nopt;
pair<int,int> opt[MAXN];

void solve() {
	nans=0;

	nopt=0; REP(i,n) if(a[i]<b[i]) opt[nopt++]=MP(-b[i],i);
	sort(opt,opt+nopt);
	ncur=nopt; REP(i,nopt) cur[i]=opt[i].second;
	if(ncur>nans) { nans=ncur; REP(i,ncur) ans[i]=cur[i]; }

	nopt=0; REP(i,n) if(a[i]>b[i]) opt[nopt++]=MP(b[i],i);
	sort(opt,opt+nopt);
	ncur=nopt; REP(i,nopt) cur[i]=opt[i].second;
	if(ncur>nans) { nans=ncur; REP(i,ncur) ans[i]=cur[i]; }
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&a[i],&b[i]);
	solve();
	printf("%d\n",nans);
	REP(i,nans) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}
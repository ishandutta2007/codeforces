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

const int MAXN=200000;
const int MAXRET=100000;

int n; ll tdrink;
int len[MAXN];
int tmx[MAXN];

ll nret,ret[MAXRET];

bool solve() {
	nret=0;
	ll t=0; ll rem=0;
	REP(i,n) {
		if(tmx[i]<len[i]) return false;
		if(rem>=len[i]) { t+=len[i]; rem-=len[i]; continue; }
		if(rem+2*(len[i]-rem)<=tmx[i]) { t+=rem+2*(len[i]-rem); rem=0; continue; }
		int exceed=rem+2*(len[i]-rem)-tmx[i];
		int nfull=exceed/tdrink,nlast=exceed%tdrink;
		for(int j=0;j<nfull&&nret+j<MAXRET;++j) ret[nret+j]=t+rem+tdrink*j; nret+=nfull;
		if(nlast!=0) { if(nret<MAXRET) ret[nret]=t+tmx[i]-nlast; ++nret; rem=tdrink-nlast; } else rem=0;
		t+=tmx[i];
	}
	return true;
}

void run() {
	scanf("%d%lld",&n,&tdrink);
	REP(i,n) scanf("%d",&len[i]);
	REP(i,n) scanf("%d",&tmx[i]);

	if(!solve()) { printf("-1\n"); return; }
	printf("%lld\n",nret);
	if(nret<=MAXRET) { REP(i,nret) { if(i!=0) printf(" "); printf("%lld",ret[i]); } puts(""); }
}


int main() {
	run();
	return 0;
}
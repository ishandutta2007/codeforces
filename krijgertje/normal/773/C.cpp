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

const int MAXLG=40;
const int MAXN=100000;

int n;
int have[MAXLG+1];
int opt[MAXLG+1];

int ret[MAXN],nret;

void run() {
	scanf("%d",&n);
	memset(have,0,sizeof(have)); memset(opt,0,sizeof(opt));
	int cnt=0;
	REP(i,n) {
		ll x; scanf("%lld",&x);
		int p=0; while((2LL<<p)<=x) ++p;
		if((1LL<<p)==x) {
			++have[p];
		} else {
			REPE(j,p) --have[j]; ++opt[p+1]; ++cnt;
		}
	}
	nret=0;
	REPE(i,have[0]) {
		int a=i,b=0; bool ok=true; int need=0;
		REPE(j,MAXLG) {
			//printf("%d: a=%d b=%d need=%d\n",j,a,b,need);
			if(have[j]<0) { ok=false; break; }
			int na=min(a,have[j]);
			int da=a-na;
			need=max(0,need-da);
			int nb=min(b+opt[j],have[j]-na);
			need+=have[j]-na-nb;
			a=na,b=nb;
		}
		if(need>a) ok=false;
		if(ok) ret[nret++]=cnt+i;
	}
	if(nret==0) printf("-1\n"); else { REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts(""); }
}

int main() {
	run();
	return 0;
}
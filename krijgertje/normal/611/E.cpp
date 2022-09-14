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

int n;
int a,b,c;
int x[MAXN];

void run() {
	// at least c needed -> use c (possibly including either a or b if necessary)
	// c cannot do on his own -> use a+b
	// -> c can do everything on his own

	scanf("%d%d%d%d",&n,&a,&b,&c); if(a>b) swap(a,b); if(b>c) swap(b,c); if(a>b) swap(a,b);
	REP(i,n) scanf("%d",&x[i]);
	int na=0,nb=0,naborc=0,nab=0,nc=0,nac=0,nbc=0,nabc=0;
	REP(i,n) {
		if(a>=x[i]) ++na;
		else if(b>=x[i]) ++nb;
		else if(c>=x[i]&&a+b>=x[i]) ++naborc;
		else if(a+b>=x[i]) ++nab;
		else if(c>=x[i]) ++nc;
		else if(a+c>=x[i]) ++nac;
		else if(b+c>=x[i]) ++nbc;
		else if(a+b+c>=x[i]) ++nabc;
		else { printf("-1\n"); return; }
	}
	int ret=0,xa=0,xb=0,xab=0,xc=0;
	ret+=nabc; nabc=0;
	ret+=nbc; xa+=nbc; nbc=0;
	ret+=nac; xb+=nac; nac=0;
	ret+=nc; xab+=nc; nc=0;
	{ int cur=min(nab,xab); nab-=cur; xab-=cur; }
	ret+=nab; xc+=nab; nab=0;
	{ int cur=min(naborc,xc); naborc-=cur; xc-=cur; }
	{ int cur=min(nb,xc); nb-=cur; xc-=cur; }
	{ int cur=min(na,xc); na-=cur; xc-=cur; }
	{ int cur=min(na,xa); na-=cur; xa-=cur; }
	{ int cur=min(nb,xb); nb-=cur; xb-=cur; }
	{ int cur=min(na,xb); na-=cur; xb-=cur; }
	int best=INT_MAX;
	REPE(i,naborc) {
		int extra=i,la=na,lb=nb,laborc=naborc-i,yab=xab+i,ya=xa,yb=xb,yc=xc;
		{ int cur=min(laborc,yab); laborc-=cur; yab-=cur; }
		{ int cur=laborc; extra+=cur; yab+=cur; yc+=cur; }
		{ int cur=min(laborc,yab); laborc-=cur; yab-=cur; }
		yb+=yc; yc=0; ya+=yab; yb+=yab; yab=0;
		{ int cur=min(lb,yb); lb-=cur; yb-=cur; }
		{ int cur=(lb+1)/2; extra+=cur; ya+=cur; yb+=2*cur; }
		{ int cur=min(lb,yb); lb-=cur; yb-=cur; }
		ya+=yb; yb=0;
		{ int cur=min(la,ya); la-=cur; ya-=cur; }
		{ int cur=(la+2)/3; extra+=cur; la+=3*cur; }
		{ int cur=min(la,ya); la-=cur; ya-=cur; }
		if(extra<best) best=extra;
	}
	ret+=best;
	printf("%d\n",ret);
}


int main() {
	run();
	return 0;
}
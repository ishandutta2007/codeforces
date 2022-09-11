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

int n,sz,reps;
int a[MAXN];

pair<int,int> b[MAXN]; int nb;

void run() {
	scanf("%d%d%d",&n,&sz,&reps); REP(i,n) scanf("%d",&a[i]);

	nb=0;
	REP(i,n) {
		if(nb>0&&b[nb-1].first==a[i]) ++b[nb-1].second; else b[nb++]=MP(a[i],1);
		if(nb>0&&b[nb-1].second==sz) --nb;
	}
	int matchcnt=0,matchsum=0; while(matchcnt<nb&&b[matchcnt].first==b[nb-matchcnt-1].first&&b[matchcnt].second+b[nb-matchcnt-1].second==sz) ++matchcnt,matchsum+=sz;
	int bsum=0; REP(i,nb) bsum+=b[i].second;

	if(reps==1) { printf("%d\n",bsum); return; }
	if(matchcnt==nb) { printf("%d\n",(reps%2)*bsum); return; }
	assert(2*matchcnt<nb);
	if(2*matchcnt+1==nb) { int bmid=(ll)reps*b[matchcnt].second%sz; printf("%d\n",bmid==0?0:bmid+matchsum); return; }
	if(b[matchcnt].first==b[nb-matchcnt-1].first&&b[matchcnt].second+b[nb-matchcnt-1].second>=sz) matchsum+=sz;
	printf("%lld\n",(ll)reps*bsum-(ll)(reps-1)*matchsum);
}

int main() {
	run();
	return 0;
}
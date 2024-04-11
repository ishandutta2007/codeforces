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
typedef struct R { int cost,val; } R;
bool operator<(const R &a,const R &b) { if(a.cost!=b.cost) return a.cost<b.cost; return a.val<b.val; }

int n,havea,haveb;
R a[MAXN]; int na;
R b[MAXN]; int nb;

void run() {
	scanf("%d%d%d",&n,&havea,&haveb);
	na=nb=0; REP(i,n) { int val,cost; char tp; scanf("%d%d %c",&val,&cost,&tp); if(tp=='C') a[na].cost=cost,a[na].val=val,++na; if(tp=='D') b[nb].cost=cost,b[nb].val=val,++nb; }
	int ret=0;
	sort(a,a+na); while(na>0&&a[na-1].cost>havea) --na; 
	sort(b,b+nb); while(nb>0&&b[nb-1].cost>haveb) --nb; 
	int nna=0,ai=-1; REP(i,na) { while(ai>=0&&a[ai].cost+a[i].cost>havea) --ai; if(ai>=0) ret=max(ret,a[ai].val+a[i].val); if(nna==0||a[i].val>a[nna-1].val) a[nna++]=a[i],++ai; } na=nna;
	int nnb=0,bi=-1; REP(i,nb) { while(bi>=0&&b[bi].cost+b[i].cost>haveb) --bi; if(bi>=0) ret=max(ret,b[bi].val+b[i].val); if(nnb==0||b[i].val>b[nnb-1].val) b[nnb++]=b[i],++bi; } nb=nnb;
	if(na>=1&&nb>=1) ret=max(ret,a[na-1].val+b[nb-1].val);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
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

const int MAXN=100;
typedef struct P { int x,cnt; } P;
bool operator<(const P &a,const P &b) { return a.x<b.x; }

int n;
P a[MAXN]; int na;
P b[MAXN]; int nb;

void run() {
	scanf("%d",&n);
	na=nb=0; REP(i,n) { P p; scanf("%d%d",&p.x,&p.cnt); if(p.x>0) a[na++]=p; else p.x=-p.x,b[nb++]=p; }
	sort(a,a+na); sort(b,b+nb);
	int ret;
	if(na>nb) { ret=a[0].cnt; REP(i,nb) ret+=b[i].cnt+a[i+1].cnt; }
	if(nb>na) { ret=b[0].cnt; REP(i,na) ret+=a[i].cnt+b[i+1].cnt; }
	if(na==nb) { ret=0; REP(i,na) ret+=a[i].cnt+b[i].cnt; }
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
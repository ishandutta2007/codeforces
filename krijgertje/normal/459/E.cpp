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

const int MAXN=300000;
const int MAXM=300000;

typedef struct X { int a,b,c; } X;
bool operator<(const X &p,const X &q) { return p.c<q.c; }

int n,m;
X x[MAXM];

int cur[MAXN],prv[MAXN];
int lst[MAXN];


void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; x[i].a=a,x[i].b=b,x[i].c=c; }
	sort(x,x+m);

	REP(i,n) cur[i]=prv[i]=lst[i]=0;
	REP(i,m) {
		int a=x[i].a,b=x[i].b,c=x[i].c;
		int now=lst[a]<c?cur[a]+1:prv[a]+1;
		if(now>cur[b]) { if(c>lst[b]) prv[b]=cur[b]; cur[b]=now; lst[b]=c; }
	}
	int ret=0; REP(i,n) if(cur[i]>ret) ret=cur[i];
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
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

const int MAXN=400;
const int MAXX=2*MAXN*(2*MAXN-1)/2;

typedef struct X { int s,a,b; } X;
bool operator<(const X &p,const X &q)  { return p.s>q.s; } 

int n;
X x[MAXX]; int nx;
int match[2*MAXN];


void run() {
	scanf("%d",&n);
	nx=0;
	REP(i,2*n) REP(j,i) { scanf("%d",&x[nx].s); x[nx].a=i,x[nx].b=j,++nx; }
	sort(x,x+nx);

	REP(i,2*n) match[i]=-1;
	REP(i,nx) if(match[x[i].a]==-1&&match[x[i].b]==-1) { match[x[i].a]=x[i].b; match[x[i].b]=x[i].a; }

	REP(i,2*n) { if(i!=0) printf(" "); printf("%d",match[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}
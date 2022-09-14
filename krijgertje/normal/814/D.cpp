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

const int MAXN=1000;
const double MYPI=acos(-1.0);
typedef struct C { int x,y,r; } C;
bool operator<(const C &a,const C &b) { return a.r<b.r; }

int n;
C c[MAXN];
int par[MAXN];
int chead[MAXN],cnxt[MAXN];

bool inside(const C &a,const C &b) {
	int dx=a.x-b.x,dy=a.y-b.y;
	return (ll)dx*dx+(ll)dy*dy<=(ll)b.r*b.r;
}

double dfs(int at,int odd) {
	double ret=0,area=MYPI*c[at].r*c[at].r;
	if(odd<2) ret+=area; else ret-=area;
	for(int to=chead[at];to!=-1;to=cnxt[to]) {
		int nodd=odd==2?odd-1:odd+1;
		ret+=dfs(to,nodd);
	}
	return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].r); sort(c,c+n);
	REP(i,n) { par[i]=-1; FOR(j,i+1,n) if(inside(c[i],c[j])) { par[i]=j; break; } }
	REP(i,n) chead[i]=-1; REP(i,n) if(par[i]!=-1) cnxt[i]=chead[par[i]],chead[par[i]]=i;
	double ret=0; REP(i,n) if(par[i]==-1) ret+=dfs(i,0); printf("%.18lf\n",ret);
}

int main() {
	run();
	return 0;
}
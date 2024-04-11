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
typedef struct P { int x,w; } P;
bool operator<(const P &a,const P &b) { return a.x+a.w<b.x+b.w; }

int n;
P p[MAXN];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].w);
	sort(p,p+n);
	int ret=1,at=p[0].x+p[0].w;
	FOR(i,1,n) {
		if(p[i].x-p[i].w<at) continue;
		++ret; at=p[i].x+p[i].w;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
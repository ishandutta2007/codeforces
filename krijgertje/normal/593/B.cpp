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
typedef struct L { int a,b; } L;

int n;
int lx,hx;
L line[MAXN];

bool operator<(const L &p,const L &q) {
	ll py=(ll)p.a*lx+p.b,qy=(ll)q.a*lx+q.b;
	if(py!=qy) return py<qy;
	return p.a<q.a;
}

void run() {
	scanf("%d",&n);
	scanf("%d%d",&lx,&hx);
	REP(i,n) scanf("%d%d",&line[i].a,&line[i].b);
	sort(line,line+n);
	bool ret=false;
	REP(i,n-1) {
		const L &p=line[i],&q=line[i+1];
		ll py=(ll)p.a*hx+p.b,qy=(ll)q.a*hx+q.b;
		if(py>qy) ret=true;
	}
	printf("%s\n",ret?"YES":"NO");
}

int main() {
	run();
	return 0;
}
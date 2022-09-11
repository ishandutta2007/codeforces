#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }


int n,diam,mxdeg;

vector<pair<int,int>> e;

void rec(int at,int dep,int &nxt) {
	if(nxt>=n||dep==0) return;
	REP(i,mxdeg-1) if(nxt<n) {
		int to=nxt++;
		e.PB(MP(at,to));
		rec(to,dep-1,nxt);
	}
}

bool solve() {
	e.clear();
	if(diam>n-1) return false;
	if(n==1) return true;
	if(n>2&&mxdeg<2) return false;

	REP(i,diam) e.PB(MP(i,i+1));
	int nxt=diam+1;
	FORE(i,1,diam-1) if(nxt<n) REP(j,mxdeg-2) if(nxt<n) {
		int at=nxt++;
		e.PB(MP(i,at));
		rec(at,min(i,diam-i)-1,nxt);
	}
	return nxt==n;
}

void run() {
	scanf("%d%d%d",&n,&diam,&mxdeg);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n"); REPSZ(i,e) printf("%d %d\n",e[i].first+1,e[i].second+1);
}

int main() {
	run();
	return 0;
}
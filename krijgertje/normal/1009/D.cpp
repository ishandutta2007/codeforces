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

const int MAXM=100000;

int n,m;

pair<int,int> e[MAXM];

bool solve() {
	if(m<n-1) return false;
	int at=0; FORE(i,2,n) e[at++]=MP(1,i);
	FORE(i,2,n) FORE(j,i+1,n) { if(at>=m) break; if(gcd(i,j)!=1) continue; e[at++]=MP(i,j); }
	return at==m;
}

void run() {
	scanf("%d%d",&n,&m);
	if(!solve()) { printf("Impossible\n"); return; }
	printf("Possible\n");
	REP(i,m) printf("%d %d\n",e[i].first,e[i].second);

}

int main() {
	run();
	return 0;
}
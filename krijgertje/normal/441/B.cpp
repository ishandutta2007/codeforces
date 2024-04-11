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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

typedef struct Tree { int t,cnt; } Tree;
bool operator<(const Tree &a,const Tree &b) { return a.t<b.t; }

int ntrees,cap;
Tree trees[3000];

void run() {
	scanf("%d%d",&ntrees,&cap);
	REP(i,ntrees) scanf("%d%d",&trees[i].t,&trees[i].cnt);
	sort(trees,trees+ntrees);
	int ret=0;
	int t=-1,ccap=0;
	int at=0;
	while(at<ntrees) {
		if(ccap==0) { ++t; ccap=cap; }
		if(t<trees[at].t) { t=trees[at].t; ccap=cap; }
		if(t>trees[at].t+1) { ++at; continue; }
		if(trees[at].cnt==0) { ++at; continue; }
		int cur=min(ccap,trees[at].cnt);
		ret+=cur; ccap-=cur; trees[at].cnt-=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
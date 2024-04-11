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

const int MAXN=100;

int n,dst;
int x[MAXN];

void run() {
	scanf("%d%d",&n,&dst);
	REP(i,n) scanf("%d",&x[i]);

	int ret=2;
	REP(i,n-1) {
		int cur=x[i+1]-x[i];
		if(cur>=2*dst) ++ret;
		if(cur>2*dst) ++ret;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
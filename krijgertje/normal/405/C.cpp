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

int n;
int a[1000][1000];
int x[1000];

void run() {
	scanf("%d",&n);
	REP(i,n) REP(j,n) scanf("%d",&a[i][j]);

	REP(i,n) x[i]=a[i][i];
	int ret=0; REP(i,n) ret+=x[i];

	int nq; scanf("%d",&nq);
	REP(q,nq) {
		int type; scanf("%d",&type);
		if(type==1||type==2) { int pos; scanf("%d",&pos); if(x[pos]) --ret; else ++ret; x[pos]=1-x[pos]; continue; }
		printf("%d",ret%2);
	}
	puts("");

}

int main() {
	run();
	return 0;
}
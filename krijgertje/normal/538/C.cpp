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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXNOTES=100000;

int ndays,nnotes;
int d[MAXNOTES],h[MAXNOTES];

int calc() {
	int ret=max(h[0]+d[0],h[nnotes-1]+ndays-d[nnotes-1]-1);
	FOR(i,1,nnotes) {
		int dh=abs(h[i]-h[i-1]),dd=d[i]-d[i-1];
		if(dh>dd) return -1;
		int cur=max(h[i],h[i-1])+(dd-dh)/2;
		if(cur>ret) ret=cur;
	}
	return ret;
}

void run() {
	scanf("%d%d",&ndays,&nnotes);
	REP(i,nnotes) scanf("%d%d",&d[i],&h[i]),--d[i];
	
	int ret=calc();
	if(ret==-1) printf("IMPOSSIBLE\n"); else printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
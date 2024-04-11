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

int n;
int x[2000];

int ret[1000];


void run() {
	scanf("%d",&n);
	REP(i,n) { char c; scanf(" %c",&c); x[i]=c-'0'; }
	REP(i,n) x[n+i]=x[i];

	REP(i,n) ret[i]=x[i];
	REP(i,10) {
		REP(i,n) {
			int cmp=0;
			REP(j,n) if(x[i+j]!=ret[j]) { cmp=x[i+j]<ret[j]?-1:+1; break; }
			if(cmp==-1) { REP(j,n) ret[j]=x[i+j]; }
		}
		REP(i,2*n) if(++x[i]>=10) x[i]-=10;
	}
	REP(i,n) printf("%d",ret[i]); puts("");
}

int main() {
	run();
	return 0;
}
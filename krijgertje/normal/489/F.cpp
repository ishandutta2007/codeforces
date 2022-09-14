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

int n,have,MOD;
int rem[500];

int mem[501][501];
int go(int one,int two) {
	if(one==0&&two==0) return 1;
	int &ret=mem[one][two];
	if(ret==-1) {
		ret=0;
		if(one>=1&&two>=1) ret=(ret+(ll)one*two%MOD*go(one,two-1))%MOD;
		if(two>=2) ret=(ret+(ll)two*(two-1)/2%MOD*go(one+2,two-2))%MOD;
		if(one>=2) ret=(ret+(ll)one*(one-1)/2%MOD*go(one-2,two))%MOD;
		//printf("%d %d = %d\n",one,two,ret);
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&n,&have,&MOD);
	REP(i,n) rem[i]=2; REP(i,have) REP(j,n) { char c; scanf(" %c",&c); if(c=='1') --rem[j]; }
	int one=0,two=0; REP(i,n) if(rem[i]==1) ++one; else if(rem[i]==2) ++two;
	memset(mem,-1,sizeof(mem));
	int ret=go(one,two);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
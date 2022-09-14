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


int x[4][4];

bool solve() {
	REP(i,4) if(x[i][3]==1) {
		if(x[(i+3)%4][2]==1) return true;
		if(x[(i+2)%4][1]==1) return true;
		if(x[(i+1)%4][0]==1) return true;
		if(x[i][0]==1||x[i][1]==1||x[i][2]==1) return true;
	}
	return false;
}

void run() {
	REP(i,4) REP(j,4) scanf("%d",&x[i][j]);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}
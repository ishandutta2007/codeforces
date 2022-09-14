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

const int MAXM=1000;

int n,m;
bool can[2][MAXM];

void run() {
	scanf("%d%d",&n,&m);

	int at=0; REP(j,m) can[at][j]=false;
	REP(i,n) {
		int x; scanf("%d",&x); x%=m;
		REP(j,m) can[1-at][j]=can[at][j];
		can[1-at][x]=true;
		REP(j,m) if(j<x&&can[at][j-x+m]||j>=x&&can[at][j-x]) can[1-at][j]=true;
		at=1-at;
		//REP(j,m) printf("%c",can[at][j]?'V':'.'); puts("");
		if(can[at][0]) break;
	}
	printf("%s\n",can[at][0]?"YES":"NO");
}

int main() {
	run();
	return 0;
}
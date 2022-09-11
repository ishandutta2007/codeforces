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

const int MAXN=3;
const int MAXMAKE=999;

int n;
int x[MAXN][6];

bool can[MAXMAKE+2];

void go(int have,int used) {
	if(have!=0) can[have]=true;
	REP(i,n) {
		if(used&(1<<i)) continue;
		REP(j,6) {
			if(have==0&&x[i][j]==0) continue;
			go(10*have+x[i][j],used|(1<<i));
		}
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) REP(j,6) scanf("%d",&x[i][j]);
	memset(can,false,sizeof(can));
	go(0,0);
	int ret=0; while(can[ret+1]) ++ret; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
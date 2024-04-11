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

const int N=1000;
const int MAXRET=2005;

int ret[MAXRET],nret;

//int at;
//bool can[2][N];

void shoot(int x) {
	ret[nret++]=x+1;
	//REP(i,N) can[1-at][i]=false;
	//REP(i,N) if(can[at][i]&&x!=i) for(int dx=-1;dx<=+1;dx+=2) if(0<=i+dx&&i+dx<N) can[1-at][i+dx]=true;
	//at=1-at;
}

void run() {
	nret=0;
	//at=0; REP(i,N) can[at][i]=true;
	FOR(i,1,N) shoot(i);
	FOR(i,1,N) shoot(i);
	//REP(i,N) assert(!can[at][i]);
	printf("%d\n",nret);
	REP(i,nret) printf("%d %d %d %d\n",ret[i],1,ret[i],2);
}

int main() {
	run();
	return 0;
}
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

const int MAXCITY=100;
const int MAXCAND=100;

int ncand,ncity;
int x[MAXCITY][MAXCAND];

int wincity[MAXCITY];
int wincnt[MAXCAND];
int winall;

void run() {
	scanf("%d%d",&ncand,&ncity);
	REP(i,ncity) REP(j,ncand) scanf("%d",&x[i][j]);
	memset(wincnt,0,sizeof(wincnt));
	REP(i,ncity) { wincity[i]=0; FOR(j,1,ncand) if(x[i][j]>x[i][wincity[i]]) wincity[i]=j; ++wincnt[wincity[i]]; }
	winall=0; FOR(j,1,ncand) if(wincnt[j]>wincnt[winall]) winall=j;
	printf("%d\n",winall+1);
}


int main() {
	run();
	return 0;
}
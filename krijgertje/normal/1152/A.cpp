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
#include <bitset>
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

const int MAXCHEST=100000;
const int MAXKEY=100000;

int nchest,nkey;
int a[MAXCHEST];
int b[MAXKEY];

int have[2],lim[2];

int solve() {
	REP(i,2) have[i]=lim[i]=0;
	REP(i,nchest) ++have[a[i]%2];
	REP(i,nkey) ++lim[1-b[i]%2];
	int ret=0; REP(i,2) ret+=min(have[i],lim[i]); return ret;
}

void run() {
	scanf("%d%d",&nchest,&nkey);
	REP(i,nchest) scanf("%d",&a[i]);
	REP(i,nkey) scanf("%d",&b[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
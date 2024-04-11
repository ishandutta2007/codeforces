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

const int MAXN=100;
const int MAXLEN=10;

int n;
char s[MAXLEN+1];
int nsoft,nhard;

set<string> have;

bool ok(int sz) {
	int nsquare=sz*sz,na=nsquare/2,nb=nsquare-na;
	return nsoft<=na&&nhard<=nb||nsoft<=nb&&nhard<=na;
}

void run() {
	scanf("%d",&n);
	nsoft=nhard=0;
	REP(i,n) {
		scanf("%s",s); assert(have.count(s)==0); have.insert(s);
		scanf("%s",s); if(strcmp(s,"soft")==0) ++nsoft; else if(strcmp(s,"hard")==0) ++nhard; else assert(false);
	}
	int ret=1;
	while(!ok(ret)) ++ret;
	printf("%d\n",ret);

}

int main() {
	run();
	return 0;
}
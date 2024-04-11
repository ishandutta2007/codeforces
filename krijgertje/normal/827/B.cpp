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

const int MAXN=200000;

int n,nleaf;

void run() {
	scanf("%d%d",&n,&nleaf);
	int nrem=n-nleaf-1;
	int each=nrem/nleaf; nrem-=each*nleaf;
	printf("%d\n",2*(each+1)+min(nrem,2));
	int rt=1,at=2;
	REP(i,nleaf) {
		int prv=rt,len=each+1+(i<nrem?1:0);
		REP(j,len) { printf("%d %d\n",prv,at); prv=at++; }
	}
}

int main() {
	run();
	return 0;
}
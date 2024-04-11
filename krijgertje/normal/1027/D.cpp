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

const int MAXN=200000;

int n;
int cost[MAXN];
int nxt[MAXN];

int state[MAXN];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&cost[i]);
	REP(i,n) scanf("%d",&nxt[i]),--nxt[i];

	ll ret=0;
	REP(i,n) state[i]=0;
	REP(i,n) if(state[i]==0) {
		int at=i; while(state[at]==0) { state[at]=1; at=nxt[at]; }
		if(state[at]==1) {
			int cur=INT_MAX;
			while(state[at]==1) { cur=min(cur,cost[at]); state[at]=2; at=nxt[at]; }
			ret+=cur;
		}
		at=i; while(state[at]==1) { state[at]=2; at=nxt[at]; }
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}
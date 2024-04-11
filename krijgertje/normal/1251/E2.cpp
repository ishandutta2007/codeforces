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
#include <chrono>
#include <chrono>
#include <random>
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

int n;
int need[MAXN],cost[MAXN];

vector<int> who[MAXN];
int delta[MAXN+1];
priority_queue<int> pq;

ll solve() {
	REP(i,n) who[need[i]].PB(i);
	delta[0]=0; FORE(i,1,n) delta[i]=SZ(who[i-1])+delta[i-1];
	REPE(i,n) delta[i]-=i;
	//printf("delta:"); REPE(i,n) printf(" %d",delta[i]); puts("");
	pq=priority_queue<int>();
	int have=0;
	ll ret=0;
	for(int i=n;i>=0;--i) {
		if(i<n) REPSZ(j,who[i]) pq.push(-cost[who[i][j]]);
		while(delta[i]<-have) {
			assert(SZ(pq)>0);
			int cur=-pq.top(); pq.pop();
			ret+=cur,++have;
		}
	}
	return ret;
}
void cleanup() {
	REP(i,n) who[i].clear();
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&need[i],&cost[i]);
	printf("%lld\n",solve());
	cleanup();
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}
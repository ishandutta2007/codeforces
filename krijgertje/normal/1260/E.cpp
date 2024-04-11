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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 1 << 18;

int n;
int a[MAXN];

ll solve() {
	int me = -1; REP(i, n) if (a[i] == -1) { assert(me == -1); me = i; } assert(me != -1);
	int myrank = n - me;
	vector<int> need;
	int sum = 0, rem = n;
	for (int i = 0;; ++i) {
		int cnt = 1 + sum;
		if (myrank <= cnt) break;
		need.PB(cnt);
		rem /= 2; sum += rem;
	}
	//printf("need:"); REPSZ(i, need) printf(" %d", need[i]); puts("");
	priority_queue<int> pq;
	int have = 0;
	ll ret = 0;
	REPSZ(i, need) {
		while (have < need[i]) pq.push(-a[n - have - 1]), ++have;
		int best = -pq.top(); pq.pop();
		ret += best; 
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}
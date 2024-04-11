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

const int MAXN = 100;
const int MAXSUMCOST = 10000;

int n, randcost;
int cost[MAXN];

double ways[MAXN + 1][MAXSUMCOST + 1];

double solve() {
	int sumcost = 0;
	ways[0][0] = 1;
	REP(x, n) {
		for (int i = x + 1; i >= 0; --i) REPE(j, sumcost + cost[x]) {
			if (i > x || j > sumcost) ways[i][j] = 0;
			if (i - 1 >= 0 && j - cost[x] >= 0) ways[i][j] += ways[i - 1][j - cost[x]];
		}
		sumcost += cost[x];
	}
	double ret = 0;
	REP(i, n) {
		double sumways = 0; REPE(j, sumcost) sumways += ways[i][j];
		REPE(j, sumcost) if (ways[i][j] > 0) {
			// E=i/n*(E+randcost/2)+(n-i)/n*randcost -> E*(1-i/n)=randcost*(1-i/2n) -> E=randcost/2*(1+n/(n-i))
			double a = 1.0*(sumcost - j) / (n - i);
			double b = 0.5*randcost*(1 + 1.0*n / (n - i));
			double p = ways[i][j] / sumways;
			//printf("(%d,%d): %lf -> %lf vs %lf (p=%lf)\n", i, j, ways[i][j], a, b, p);
			ret += p*min(a, b);
		}
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &randcost);
	REP(i, n) scanf("%d", &cost[i]);
	printf("%.15lf\n", solve());
}

int main() {
	run();
	return 0;
}
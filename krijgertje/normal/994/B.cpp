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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 100000;

int n, mxkill;
int p[MAXN];
int c[MAXN];

pair<int, int> o[MAXN];
priority_queue<int> pq; ll pqsum;
ll ans[MAXN];

void run() {
	scanf("%d%d", &n, &mxkill); REP(i, n) scanf("%d", &p[i]); REP(i, n) scanf("%d", &c[i]);

	REP(i, n) o[i] = MP(p[i], i);
	sort(o, o + n);
	pq = priority_queue<int>(); pqsum = 0;
	REP(i, n) {
		int at = o[i].second;
		ans[at] = c[at] + pqsum;
		pqsum += c[at]; pq.push(-c[at]);
		while (SZ(pq) > mxkill) {
			int rem = -pq.top(); pq.pop(); pqsum -= rem;
		}
	}
	REP(i, n) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}
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

const int MAXN = 500000;

int want, n;
int t[MAXN];

int l[MAXN], r[MAXN], c[MAXN];
priority_queue<pair<int, pair<int,int> > > pq;


void run() {
	scanf("%d%d", &want, &n); REP(i, n) scanf("%d", &t[i]);

	sort(t, t + n);
	REP(i, n) l[i] = i == 0 ? -1 : i - 1;
	REP(i, n) r[i] = i == n - 1 ? -1 : i + 1;
	pq = priority_queue<pair<int, pair<int, int> > >(); REP(i, n) if (r[i] != -1) c[i] = t[r[i]] - t[i], pq.push(MP(-c[i], MP(i, r[i])));
	int ret = 0;
	REP(k, want) {
		while (!pq.empty() && r[pq.top().second.first] != pq.top().second.second) pq.pop();
		assert(!pq.empty());
		int cur = -pq.top().first, a = pq.top().second.first, b = pq.top().second.second; pq.pop();
		ret += cur;
		int aa = l[a], bb = r[b]; if (aa != -1) l[a] = r[aa] = -1; if (bb != -1) r[b] = l[bb] = -1;
		if (aa == -1 || bb == -1) continue;
		int cc = c[aa] + c[b] - cur; r[aa] = bb, l[bb] = aa, c[aa] = cc; pq.push(MP(-cc, MP(aa, bb)));
	}
	printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}
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

const int MAXHOUSE = 200000;
const int MAXCAR = 200000;
const int MAXREQ = 200000;
struct Car { int id; ll tdone; Car() {} Car(int id, ll tdone) :id(id), tdone(tdone) {} };
bool operator<(const Car &a, const Car &b) {
	if (a.tdone != b.tdone) return a.tdone < b.tdone;
	return a.id < b.id;
}

int nhouse, ncar, nreq;
int sx[MAXCAR];
ll qt[MAXREQ]; int qa[MAXREQ], qb[MAXREQ];
pair<int, ll> ans[MAXREQ];

set<int> waitpos;
set<Car> waitat[MAXHOUSE];

priority_queue<pair<ll, pair<int,int> > > arrive;
queue<int> q;

bool doride(int reqidx, ll t) {
	int a = qa[reqidx], b = qb[reqidx]; ll treq = qt[reqidx];
	auto it = waitpos.lower_bound(a);
	int a1 = -1, a2 = -1;
	if (it != waitpos.end()) a2 = *it;
	if (it != waitpos.begin()) { --it; a1 = *it; }
	if (a1 == -1 && a2 == -1) return false;
	int ax = a1 != -1 && (a2 == -1 || abs(a - a1) < abs(a - a2) || abs(a - a1) == abs(a - a2) && *waitat[a1].begin() < *waitat[a2].begin()) ? a1 : a2;
	Car cur = *waitat[ax].begin(); waitat[ax].erase(waitat[ax].begin()); if (SZ(waitat[ax]) == 0) waitpos.erase(ax);
	ll tdone = t + abs(ax - a) + abs(b - a);
	arrive.push(MP(-tdone, MP(cur.id, b)));
	ans[reqidx] = MP(cur.id, t + abs(ax - a) - treq);
	return true;
}

void run() {
	scanf("%d%d%d", &nhouse, &ncar, &nreq);
	REP(i, ncar) scanf("%d", &sx[i]), --sx[i];
	REP(i, nreq) scanf("%lld%d%d", &qt[i], &qa[i], &qb[i]), --qa[i], --qb[i];

	REP(i, ncar) waitpos.insert(sx[i]), waitat[sx[i]].insert(Car(i, 0));
	int atreq = 0;
	while (atreq < nreq || !arrive.empty() || !q.empty()) {
		ll treq = atreq < nreq ? qt[atreq] : LLONG_MAX;
		ll tarrive = !arrive.empty() ? -arrive.top().first : LLONG_MAX;
		if (tarrive <= treq) {
			while (!arrive.empty() && -arrive.top().first == tarrive) {
				int id = arrive.top().second.first, pos = arrive.top().second.second; arrive.pop();
				waitpos.insert(pos); waitat[pos].insert(Car(id, tarrive));
			}
			while (!q.empty()) {
				if (!doride(q.front(), tarrive)) break; else q.pop();
			}
		} else {
			ll t = qt[atreq]; ++atreq;
			if (!doride(atreq - 1, treq)) q.push(atreq - 1);
		}
	}

	REP(i, nreq) printf("%d %lld\n", ans[i].first + 1, ans[i].second);
}

int main() {
	run();
	return 0;
}
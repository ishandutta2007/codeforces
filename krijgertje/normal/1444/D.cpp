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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };

int nhor;
vector<int> hor;
int nver;
vector<int> ver;
vector<P> ans;

bool split(vector<int> a, vector<int>& b, vector<int>& c) {
	int asum = 0; REPSZ(i, a) asum += a[i];
	if (asum % 2 != 0) return false;
	int want = asum / 2;
	vector<int> can(want + 1, -2);
	can[0] = -1;
	REPSZ(i, a) for (int j = want - a[i]; j >= 0; --j) if (can[j] != -2 && can[j + a[i]] == -2) can[j + a[i]] = i;
	if (can[want] == -2) return false;
	vector<bool> inb(SZ(a), false);
	for (int x = want; x != 0; x -= a[can[x]]) inb[can[x]] = true;
	b.clear();
	c.clear();
	REPSZ(i, a) if (inb[i]) b.PB(a[i]); else c.PB(a[i]);
	return true;
}

bool solve() {
	if (nhor != nver) return false;
	
	vector<int> lft, rgt;
	if (!split(hor, lft, rgt)) return false;
	if (SZ(rgt) > SZ(lft)) swap(lft, rgt);
	//printf("lft:"); REPSZ(i, lft) printf(" %d", lft[i]); puts("");
	//printf("rgt:"); REPSZ(i, rgt) printf(" %d", rgt[i]); puts("");

	vector<int> up, dn;
	if (!split(ver, up, dn)) return false;
	if (SZ(dn) > SZ(up)) swap(up, dn);
	//printf("up:"); REPSZ(i, up) printf(" %d", up[i]); puts("");
	//printf("dn:"); REPSZ(i, dn) printf(" %d", dn[i]); puts("");

	int acnt = SZ(rgt);
	assert(SZ(up) >= acnt);
	int ccnt = SZ(dn);
	assert(SZ(lft) >= ccnt);
	int bcnt = nhor - acnt - ccnt;

	vector<int> ahor(acnt), aver(acnt); REP(i, acnt) ahor[i] = rgt[i], aver[i] = up[i];
	vector<int> bhor(bcnt), bver(bcnt); REP(i, bcnt) bhor[i] = lft[i], bver[i] = up[acnt + i];
	vector<int> chor(ccnt), cver(ccnt); REP(i, ccnt) chor[i] = lft[bcnt + i], cver[i] = dn[i];
	sort(ahor.begin(), ahor.end()); reverse(ahor.begin(), ahor.end()); sort(aver.begin(), aver.end());
	sort(chor.begin(), chor.end()); reverse(chor.begin(), chor.end()); sort(cver.begin(), cver.end());
	/*printf("ahor:"); REPSZ(i, ahor) printf(" %d", ahor[i]); puts("");
	printf("aver:"); REPSZ(i, aver) printf(" %d", aver[i]); puts("");
	printf("bhor:"); REPSZ(i, bhor) printf(" %d", bhor[i]); puts("");
	printf("bver:"); REPSZ(i, bver) printf(" %d", bver[i]); puts("");
	printf("chor:"); REPSZ(i, chor) printf(" %d", chor[i]); puts("");
	printf("cver:"); REPSZ(i, cver) printf(" %d", cver[i]); puts("");*/

	ans.clear();
	ans.PB(P(0, 0));
	auto append = [&](int dx, int dy) { P p(ans.back().x + dx, ans.back().y + dy); ans.PB(p); };
	REP(i, acnt) append(+ahor[i], 0), append(0, +aver[i]);
	REP(i, bcnt) append(-bhor[i], 0), append(0, +bver[i]);
	REP(i, ccnt) append(-chor[i], 0), append(0, -cver[i]);
	assert(ans.back().x == 0 && ans.back().y == 0);
	ans.pop_back();
	return true;
}

void run() {
	scanf("%d", &nhor);
	hor = vector<int>(nhor); REP(i, nhor) scanf("%d", &hor[i]);
	scanf("%d", &nver);
	ver = vector<int>(nver); REP(i, nver) scanf("%d", &ver[i]);
	if (!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	REPSZ(i, ans) printf("%d %d\n", ans[i].x, ans[i].y);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}
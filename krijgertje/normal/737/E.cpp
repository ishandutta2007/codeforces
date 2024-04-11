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

const int MAXCHILD = 40;
const int MAXMACHINE = 10;
const int MAXN = MAXCHILD + 2 * MAXMACHINE;
typedef struct Ass { int ch, ma, t, len; Ass() {} Ass(int ch, int ma, int t, int len) :ch(ch), ma(ma), t(t), len(len) {} } Ass;

int nchild, omachine, nmachine, budget;
int cost[MAXMACHINE];

int A[MAXCHILD][2 * MAXMACHINE];
int childsum[MAXCHILD], machinesum[2 * MAXMACHINE]; bool machinerented[MAXMACHINE];
int mp[2 * MAXMACHINE];

int n;
int B[MAXN][MAXN];

void makeb(int sum) {
	n = nchild + nmachine;
	memset(B, 0, sizeof(B));
	REP(i, nchild) REP(j, nmachine) B[i][j] = A[i][j];
	REP(i, nchild) B[i][nmachine + i] = sum - childsum[i];
	REP(i, nmachine) B[nchild + i][i] = sum - machinesum[i];
	int ch = 0, ma = 0, chrem = childsum[ch], marem = machinesum[ma];
	while (ch < nchild || ma < nmachine) {
		int cur = min(chrem, marem);
		if (cur != 0) B[nchild + ma][nmachine + ch] = cur; chrem -= cur; marem -= cur;
		if (ch < nchild&&chrem == 0) ++ch, chrem = ch >= nchild ? 0 : childsum[ch];
		if (ma < nmachine&&marem == 0) ++ma, marem = ma >= nmachine ? 0 : machinesum[ma];
	}
	assert(ch == nchild&&ma == nmachine);
}

vector<Ass> ass;
bool done[MAXN]; int match[MAXN];
bool augment(int at) {
	if (done[at]) return false; else done[at] = true;
	REP(to, n) if (B[at][to] > 0 && (match[to] == -1 || augment(match[to]))) { match[to] = at; return true; }
	return false;
}
void makeassignments() {
	int t = 0; ass.clear();
	while (true) {
		//printf("B\n"); REP(i, n) { printf("%d:", i); REP(j, n) printf(" %2d", B[i][j]); puts(""); }
		int left = 0; REP(i, n) REP(j, n) left += B[i][j]; if (left == 0) break;
		REP(j, n) done[j] = false, match[j] = -1;
		REP(i, n) {
			assert(augment(i));
			REP(j, n) done[j] = false;
		}
		int len = INT_MAX; REP(i, n) len = min(len, B[match[i]][i]);
		REP(i, n) B[match[i]][i] -= len;
		REP(i, n) if (i < nmachine&&match[i] < nchild) ass.PB(Ass(match[i], mp[i], t, len));
		t+=len;
	}
}


void run() {
	scanf("%d%d%d", &nchild, &nmachine, &budget);
	REP(i, nmachine) scanf("%d", &cost[i]);
	memset(A, 0, sizeof(A));
	REP(i, nchild) {
		int cnt; scanf("%d", &cnt);
		REP(j, cnt) {
			int kind, len; scanf("%d%d", &kind, &len); --kind;
			A[i][kind] += len;
		}
	}

	REP(i, nchild) childsum[i] = 0; REP(i, nmachine) machinesum[i] = 0, machinerented[i] = false, mp[i] = i; int left = budget; omachine = nmachine;
	REP(i, nchild) REP(j, nmachine) childsum[i] += A[i][j], machinesum[j] += A[i][j];
	while (true) {
		int idx = -1; REP(i, nmachine) if (!machinerented[mp[i]] && cost[mp[i]] <= left && (idx == -1 || machinesum[i] > machinesum[idx]))  idx = i;
		if (idx == -1) break;
		machinerented[idx] = true; left -= cost[mp[idx]]; int nidx = nmachine++; machinesum[nidx] = 0; mp[nidx] = mp[idx];
		int rem = machinesum[idx] / 2; REP(i, nchild) { int cur = min(rem, A[i][idx]); A[i][idx] -= cur; A[i][nidx] += cur; machinesum[idx] -= cur; machinesum[nidx] += cur; rem -= cur; }
	}
	int ret = 0; REP(i, nchild) ret = max(ret, childsum[i]); REP(i, nmachine) ret = max(ret, machinesum[i]); printf("%d\n", ret); REP(i, omachine) printf("%d", machinerented[i] ? 1 : 0); puts("");
	//printf("A\n"); REP(i, nchild) { printf("%d:", i); REP(j, nmachine) printf(" %d", A[i][j]); puts(""); }

	makeb(ret);
	//printf("B\n"); REP(i, nchild + nmachine) { printf("%d:", i); REP(j, nchild + nmachine) printf(" %2d", B[i][j]); puts(""); }

	makeassignments();
	printf("%d\n", SZ(ass));
	REPSZ(i, ass) printf("%d %d %d %d\n", ass[i].ch + 1, ass[i].ma + 1, ass[i].t, ass[i].len);
}

int main() {
	run();
	return 0;
}
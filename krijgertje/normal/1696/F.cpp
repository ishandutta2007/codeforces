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
#include <functional>
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

const int MAXN = 100;

int n;
bool samediff[MAXN][MAXN][MAXN];

vector<pair<int, int>> ans;
int d[MAXN][MAXN];
vector<vector<int>> adj;

bool rec(vector<int> lst) {
	//printf("rec:"); for (int at : lst) printf(" %d", at + 1); puts("");
	vector<bool> inlst(n, false);
	for (int at : lst) inlst[at] = true;

	REPSZ(i, lst) FORSZ(j, i + 1, lst) {
		int a = lst[i], b = lst[j];
		vector<int> mid;
		vector<int> oth;
		for (int c : lst) if (samediff[a][b][c]) mid.PB(c); else oth.PB(c);
		if (SZ(mid) >= 2) {
			if (SZ(mid) == SZ(lst)) return false;
			if (!rec(mid)) return false;
			//printf("mid:"); for (int at : mid) printf(" %d", at + 1); printf(" ->"); for (const auto& e : ans) printf(" %d-%d", e.first + 1, e.second + 1); puts("");
			REPSZ(ii, oth) FORSZ(jj, ii + 1, oth) {
				int aa = oth[ii], bb = oth[jj];
				bool ok = true;
				for (int cc : mid) if (!samediff[aa][bb][cc]) { ok = false; break; }
				if (!ok) continue;
				for (int cc : mid) {
					if (!samediff[aa][cc][bb] || !samediff[bb][cc][aa]) continue;
					vector<bool> inmid(n, false); for (int at : mid) inmid[at] = true;
					for (const auto& e : ans) {
						if (e.first != cc && e.second != cc) continue;
						int cent = e.first ^ e.second ^ cc;
						if (!inmid[cent]) continue;
						if (!samediff[aa][cc][cent] || !samediff[bb][cc][cent]) continue;
						//printf("! aa=%d bb=%d cc=%d cent=%d\n", aa + 1, bb + 1, cc + 1, cent + 1);
						oth.PB(cent);
						if (SZ(oth) == SZ(lst)) return false;
						return rec(oth);
					}
				}
			}

			return false;
		}
	}
	// line
	while (SZ(lst) >= 4) {
		bool found = false;
		for (int leaf : lst) {
			bool ok = true;
			REPSZ(i, lst) FORSZ(j, i + 1, lst) {
				int a = lst[i], b = lst[j];
				if (samediff[a][b][leaf]) { ok = false; break; }
			}
			if (!ok) continue;
			for (int conn : lst) {
				if (conn == leaf) continue;
				ok = true;
				REPSZ(i, lst) FORSZ(j, i + 1, lst) {
					int a = lst[i], b = lst[j];
					if (a == leaf || b == leaf) continue;
					if(samediff[a][b][conn]) { ok = false; break; }
				}
				if (!ok) continue;
				ok = false;
				REPSZ(i, lst) {
					int a = lst[i];
					if (a == leaf || a == conn) continue;
					if (samediff[leaf][a][conn]) { ok = true; break; }
				}
				if (!ok) continue;
				found = true;
				ans.PB(MP(leaf, conn));
				int idx = -1; REPSZ(i, lst) if (lst[i] == leaf) { idx = i; break; } assert(idx != -1);
				lst.erase(lst.begin() + idx);
				break;
			}
			if (!found) return false;
			break;
		}
		if (!found) return false;
	}
	if (SZ(lst) == 0) return true;
	if (SZ(lst) == 1) return true;
	if (SZ(lst) == 2) {
		ans.PB(MP(lst[0], lst[1]));
		return true;
	}
	if (SZ(lst) == 3) {
		for (int cent : lst) { 
			REPSZ(i, lst) FORSZ(j, i + 1, lst) { 
				int a = lst[i], b = lst[j]; 
				if (a == cent || b == cent) continue; 
				if (!samediff[a][b][cent]) continue;
				ans.PB(MP(a, cent));
				ans.PB(MP(b, cent));
				return true;
			} 
		} 
		return false;
	}
	assert(false); return false;
}

bool solve() {
	ans.clear();
	vector<int> all(n); REP(i, n) all[i] = i;
	if (!rec(all)) return false;
	adj = vector<vector<int>>(n);
	for (const auto& e : ans) { int a = e.first, b = e.second; adj[a].PB(b); adj[b].PB(a); }
	if (SZ(ans) != n - 1) return false;
	//printf("testing:"); for (const auto& e : ans) { int a = e.first, b = e.second; printf(" %d-%d", a + 1, b + 1); } puts("");
	REP(s, n) {
		REP(t, n) d[s][t] = INT_MAX;
		queue<int> q;
		d[s][s] = 0, q.push(s);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			for (int to : adj[at]) {
				if (d[s][to] != INT_MAX) continue;
				d[s][to] = d[s][at] + 1, q.push(to);
			}
		}
		//printf("d%d:", s + 1); REP(t, n) printf(" %d", d[s][t]); puts("");
		REP(t, n) if (d[s][t] == INT_MAX) return false;
	}
	REP(i, n) REP(j, n) REP(k, n) if (samediff[i][j][k] != (d[i][k] == d[j][k])) return false;
	return true;
}

void run() {
	scanf("%d", &n);
	char buff[MAXN + 1];
	REP(i, n) REP(k, n) samediff[i][i][k] = true;
	REP(i, n) FOR(j, i + 1, n) { scanf("%s", buff); REP(k, n) samediff[i][j][k] = samediff[j][i][k] = buff[k] == '1'; }
	if (!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	for (const auto& e : ans) { int a = e.first, b = e.second; printf("%d %d\n", a + 1, b + 1); }
}

void stress() {
	int mxn = 100;
	REP(rep, 10000) {
		n = rnd() % mxn + 1;
		vector<vector<int>> adj(n);
		vector<int> col(n); REP(i, n) col[i] = i;
		REP(i, n - 1) while (true) { int a = rnd() % n, b = rnd() % n; if (col[a] == col[b]) continue; int ocol = col[b]; REP(j, n) if (col[j] == ocol) col[j] = col[a]; adj[a].PB(b); adj[b].PB(a); break; }
		vector<vector<int>> d(n, vector<int>(n, INT_MAX));
		REP(s, n) {
			queue<int> q;
			d[s][s] = 0, q.push(s);
			while (!q.empty()) {
				int at = q.front(); q.pop();
				for (int to : adj[at]) {
					if (d[s][to] != INT_MAX) continue;
					d[s][to] = d[s][at] + 1, q.push(to);
				}
			}
			//printf("d%d:", s + 1); REP(t, n) printf(" %d", d[s][t]); puts("");
			REP(t, n) assert(d[s][t] != INT_MAX);
		}
		REP(i, n) REP(j, n) REP(k, n) samediff[i][j][k] = (d[i][k] == d[j][k]);
		bool have = solve();
		if (have) { printf("."); continue; }
		printf("err rep=%d\n", rep); mxn = n - 1;
		printf("e:"); REP(at, n) for (int to : adj[at]) if (at < to) printf(" %d-%d", at + 1, to + 1); puts("");
		printf("%d\n", n); REP(i, n - 1) { FOR(j, i + 1, n) { if (j != i + 1) printf(" "); REP(k, n) printf("%c", samediff[i][j][k] ? '1' : '0'); } puts(""); }
		break;
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}
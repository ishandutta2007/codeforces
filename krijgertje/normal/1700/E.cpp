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

const int DX[] = { 0,+1,0,-1 }, DY[] = { +1,0,-1,0 };

int h, w, n;
vector<vector<int>> g;
int answays;

bool valid(const vector<vector<int>>& g) {
	vector<pair<int, int>> pos(n);
	REP(x, h) REP(y, w) pos[g[x][y]] = MP(x, y);
	vector<vector<bool>> visited(h, vector<bool>(w, false));
	visited[pos[0].first][pos[0].second] = true;
	FOR(i, 1, n) {
		int x = pos[i].first, y = pos[i].second;
		bool ok = false;
		REP(k, 4) {
			int nx = x + DX[k], ny = y + DY[k];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w && visited[nx][ny]) ok = true;
		}
		if (!ok) return false;
		visited[x][y] = true;
	}
	return true;
}

int solve() {
	// check if 0 swaps ok
	// check moving 1 (try all options)
	// see how far we get without moving anything, let v be first number we can't get to

	if (valid(g)) return 0;

	answays = 0;

	vector<pair<int, int>> pos(n);
	REP(x, h) REP(y, w) pos[g[x][y]] = MP(x, y);

	REP(k, 4) {
		int xa = pos[0].first, ya = pos[0].second;
		int xb = pos[1].first + DX[k], yb = pos[1].second + DY[k];
		if (xb < 0 || xb >= h || yb < 0 || yb >= w) continue;
		if (xa == xb && ya == yb) continue;
		swap(g[xa][ya], g[xb][yb]);
		if (valid(g)) {
			//printf("option 0: ok to swap %d and %d\n", g[xa][ya] + 1, g[xb][yb] + 1);
			++answays;
		}
		swap(g[xa][ya], g[xb][yb]);
	}

	pair<int, int> UNREACHABLE = MP(-1, -1);
	pair<int, int> MULTIPLEWAYSREACHABLE = MP(-2, -2);
	auto visit1 = [&](int x, int y, vector<vector<bool>>& visited, vector<vector<pair<int, int>>>& state,vector<vector<int>> &reachedby) {
		visited[x][y] = true;
		REP(k, 4) {
			int nx = x + DX[k], ny = y + DY[k];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (reachedby[nx][ny] == -1) reachedby[nx][ny] = g[x][y];
			if (state[nx][ny] == UNREACHABLE) state[nx][ny] = MP(x, y); else state[nx][ny] = MULTIPLEWAYSREACHABLE;
		}
	};
	auto visit = [&](int x, int y, vector<vector<bool>>& visited, vector<vector<pair<int, int>>>& state) {
		visited[x][y] = true;
		REP(k, 4) {
			int nx = x + DX[k], ny = y + DY[k];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (state[nx][ny] == UNREACHABLE) state[nx][ny] = MP(x, y); else state[nx][ny] = MULTIPLEWAYSREACHABLE;
		}
	};
	vector<vector<bool>> visited(h, vector<bool>(w, false));
	vector<vector<pair<int,int>>> state(h, vector<pair<int,int>>(w, UNREACHABLE));
	vector<vector<int>> reachedby(h, vector<int>(w, -1));
	visit1(pos[0].first, pos[0].second, visited, state, reachedby);
	vector<bool> essential(n, false); int cntessential = 0;
	int a = 1;
	while (true) {
		assert(a < n);
		int x = pos[a].first, y = pos[a].second;
		if (state[x][y] == UNREACHABLE) break;
		if (state[x][y] != MULTIPLEWAYSREACHABLE) { int need = g[state[x][y].first][state[x][y].second]; if (!essential[need]) essential[need] = true, ++cntessential; }
		visit1(x, y, visited, state, reachedby);
		++a;
	}
	//printf("a=%d\n", a + 1);

	// option 1) move something so we can reach a
	// * try all positions b to move something to
	// * continue the search, assuming position b is visited and value b can be visited for free
	// * if we don't reach the end -> error
	// * otherwise, the thing we move should already be visited before reaching a, but not "essential"
	// * (every time we can reach a cell only from one other cell before visiting b, mark that cell as essential)
	int ax = pos[a].first, ay = pos[a].second;
	REP(k, 4) {
		int bx = ax + DX[k], by = ay + DY[k];
		if (bx < 0 || bx >= h || by < 0 || by >= w || state[bx][by] == UNREACHABLE) continue;
		vector<vector<bool>> visited2 = visited;
		vector<vector<pair<int, int>>> state2 = state;
		vector<bool> essential2 = essential; int cntessential2 = cntessential;
		if (state2[bx][by] != MULTIPLEWAYSREACHABLE) { int need = g[state2[bx][by].first][state2[bx][by].second]; if (!essential2[need]) essential2[need] = true, ++cntessential2; }
		visit(bx, by, visited2, state2);
		visit(ax, ay, visited2, state2);
		int at = a + 1;
		while (at < n) {
			if (at == g[bx][by]) { ++at; continue; }
			int x = pos[at].first, y = pos[at].second;
			if (state2[x][y] == UNREACHABLE) break;
			visit(x, y, visited2, state2);
			if (at < g[bx][by] && state2[x][y] != MULTIPLEWAYSREACHABLE) { int need = g[state2[x][y].first][state2[x][y].second]; if (need < a && !essential2[need]) essential2[need] = true, ++cntessential2; }
			++at;
		}
		if (at != n) continue;
		FORE(c, reachedby[bx][by] + 1, a - 1) if (!essential2[c]) {
			//printf("option 1: ok to swap %d and %d\n", g[bx][by] + 1, c + 1);
			++answays;
		}
		//answays += a - cntessential2;
		set<int> seen;
		REP(kk, 4) REP(kkk, 4) {
			int cx = bx + DX[kk], cy = by + DY[kk];
			if (cx < 0 || cx >= h || cy < 0 || cy >= w) continue;
			int dx = cx + DX[k], dy = cy + DY[k];
			if (dx < 0 || dx >= h || dy < 0 || dy >= w) continue;
			if (!essential[g[dx][dy]] || seen.count(g[dx][dy]) || g[dx][dy] == 0 || dx == bx && dy == by) continue;
			swap(g[bx][by], g[dx][dy]);
			if (valid(g)) {
				//printf("option 1b: ok to swap %d and %d\n", g[bx][by] + 1, g[dx][dy] + 1);
				seen.insert(g[bx][by]);
			}
			swap(g[bx][by], g[dx][dy]);
		}
		answays += SZ(seen);

	}

	// option 2) move a
	// * must be to a cell we haven't visited yet, and is currently reachable
	// * continue search, assuming position a is blocked
	// * 2a) if we finish the search, any option is fine, as long as it is not needed before position a becomes reachable
	// * 2b) otherwise, let b be first number we can't get to
	//   * 2b1) a can move to a cell adjacent to b, that makes b reachable (try all options consitent with earlier restrictions)
	//   * 2b2) b might be accessable through the blocked position a (all options consitent with earlier restrictions are fine, continue search with position a unblocked)
	{
		vector<vector<bool>> visited2 = visited;
		vector<vector<pair<int, int>>> state2 = state;
		int b = a + 1;
		int treach = -1;
		while (b < n) {
			int x = pos[b].first, y = pos[b].second;
			if (state2[x][y] == UNREACHABLE) break;
			visit(x, y, visited2, state2);
			if (treach == -1 && state2[ax][ay] != UNREACHABLE) treach = b;
			++b;
		}
		if (b == n) {
			REP(x, h) REP(y, w) if (!visited[x][y] && state[x][y] != UNREACHABLE && (g[x][y] > treach || abs(ax - x) + abs(ay - y) == 1)) {
				//printf("option 2a: ok to swap %d and %d\n", g[ax][ay] + 1, g[x][y] + 1);
				++answays;
			}
		} else {
			int bx = pos[b].first, by = pos[b].second;
			set<int> seen;
			REP(k, 4) {
				int cx = bx + DX[k], cy = by + DY[k];
				if (cx < 0 || cx >= h || cy < 0 || cy >= w) continue;
				if (g[cx][cy] == 0) continue;
				if (cx != ax || cy != ay) {
					swap(g[ax][ay], g[cx][cy]);
					if (valid(g)) {
						//printf("option 2b1x: ok to swap %d and %d\n", g[ax][ay] + 1, g[cx][cy] + 1);
						seen.insert(g[ax][ay]);
					}
					swap(g[ax][ay], g[cx][cy]);
				} else {
					REP(kk, 4) {
						int dx = ax + DX[k], dy = ay + DY[k];
						if (dx < 0 || dx >= h || dy < 0 || dy >= w) continue;
						if (g[dx][dy] == 0) continue;
						swap(g[ax][ay], g[dx][dy]);
						if (!seen.count(g[ax][ay]) && valid(g)) {
							//printf("option 2b1y: ok to swap %d and %d\n", g[ax][ay] + 1, g[dx][dy] + 1);
							seen.insert(g[ax][ay]);
						}
						swap(g[ax][ay], g[dx][dy]);
					}
				}
			}
			answays += SZ(seen);
			if (treach != -1) {
				int tlim = b;
				visit(ax, ay, visited2, state2);
				int at = b;
				while (at < n) {
					int x = pos[at].first, y = pos[at].second;
					if (state2[x][y] == UNREACHABLE) break;
					visit(x, y, visited2, state2);
					++at;
				}
				if (at == n) {
					REP(x, h) REP(y, w) if (!visited[x][y] && state[x][y] != UNREACHABLE && (g[x][y] > treach || abs(ax-x)+abs(ay-y)==1) && g[x][y]<tlim && !seen.count(g[x][y])) {
						//printf("option 2b2: ok to swap %d and %d\n", g[ax][ay] + 1, g[x][y] + 1);
						++answays;
					}
				}
			}
		}
	}

	if (answays != 0) return 1; else return 2;
}

void run() {
	scanf("%d%d", &h, &w); n = h * w;
	g = vector<vector<int>>(h, vector<int>(w));
	REP(x, h) REP(y, w) scanf("%d", &g[x][y]), --g[x][y];
	int ans = solve();
	if (ans != 1) printf("%d\n", ans); else printf("%d %d\n", ans, answays);
}

pair<int, int> solvestupid() {
	if (valid(g)) return MP(0, -1);
	int cnt = 0;
	REP(x, h) REP(y, w) FOR(xx, x, h) FOR(yy, xx == x ? y + 1 : 0, w) {
		swap(g[x][y], g[xx][yy]);
		if (valid(g)) ++cnt; // , printf("stupid swaps %d and %d\n", g[x][y] + 1, g[xx][yy] + 1);
		swap(g[x][y], g[xx][yy]);
	}
	if (cnt != 0) return MP(1, cnt);
	return MP(2, -1);
}

void stress() {
	std::mt19937 rnd(12312);
	int mxdim = 20;
	REP(rep, 10000) {
		h = rnd() % mxdim + 1, w = rnd() % mxdim + 1, n = h * w;
		g = vector<vector<int>>(h, vector<int>(w));
		vector<int> perm(n); REPSZ(i, perm) { perm[i] = i; int idx = rnd() % (i + 1); swap(perm[i], perm[idx]); }
		//printf("perm:"); REPSZ(i, perm) printf(" %d", perm[i]); puts("");
		REP(x, h) REP(y, w) g[x][y] = perm[w * x + y];
		int havecnt = solve(); pair<int, int> have = MP(havecnt, havecnt == 1 ? answays : -1);
		pair<int, int> want = solvestupid();
		if (have == want) { printf("."); continue; }
		printf("err rep=%d have=(%d,%d) want=(%d,%d)\n", rep, have.first, have.second, want.first, want.second);
		printf("%d %d\n", h, w); REP(x, h) { REP(y, w) { if (y != 0) printf(" "); printf("%d", g[x][y] + 1); } puts(""); }
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}
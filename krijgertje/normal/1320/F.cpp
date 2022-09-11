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

const int MAXN = 200000;
const int DX[6] = { +1,-1,0,0,0,0 }, DY[6] = { 0,0,+1,-1,0,0 }, DZ[6] = { 0,0,0,0,+1,-1 };
struct Laser { int x, y, z, dir, want; Laser() {} Laser(int x, int y, int z, int dir, int want) :x(x), y(y), z(z), dir(dir), want(want) {} void step() { x += DX[dir]; y += DY[dir]; z += DZ[dir]; } };

int na, nb, nc;
Laser laser[6 * MAXN]; int nlaser;
int ans[MAXN];

vector<int> who[MAXN];
queue<int> q;

bool solve() {
	REP(i, na*nb*nc) ans[i] = -1, who[i].clear();
	q = queue<int>();
	REP(i, nlaser) q.push(i);
	while (!q.empty()) {
		int at = q.front(); q.pop();
		int x = laser[at].x, y = laser[at].y, z = laser[at].z, want = laser[at].want;
		//printf("processing laser %d, currently aiming at (%d,%d,%d), wanting %d, seeing %d\n", at, x, y, z, want, x < 0 || x >= na || y < 0 || y >= nb || z < 0 || z >= nc ? -2 : ans[x*nb*nc + y*nc + z]);
		//REP(i, na) { if (i != 0) puts(""); REP(j, nb) { REP(k, nc) { if (k != 0) printf(" "); printf("%d", ans[i*nb*nc + j*nc + k]); } puts(""); } }
		if (x < 0 || x >= na || y < 0 || y >= nb || z < 0 || z >= nc) {
			if (want != 0) return false;
		} else {
			int target = x*nb*nc + y*nc + z;
			if (want == 0) {
				REPSZ(i, who[target]) {
					int to = who[target][i];
					laser[to].step(); q.push(to);
				}
				who[target].clear(); ans[target] = 0; laser[at].step(); q.push(at);
			} else {
				if (ans[target] == -1) ans[target] = want;
				if (ans[target] != want) {
					REPSZ(i, who[target]) {
						int to = who[target][i];
						laser[to].step(); q.push(to);
					}
					who[target].clear(); ans[target] = 0; laser[at].step(); q.push(at);
				} else {
					who[target].PB(at);
				}
			}
		}
	}
	REP(i, na*nb*nc) if (ans[i] == -1) ans[i] = 0;
	return true;
}

void read(int x, int y, int z, int dir) { int want; scanf("%d", &want); laser[nlaser++] = Laser(x, y, z, dir, want); }
void run() {
	scanf("%d%d%d", &na, &nb, &nc);
	nlaser = 0;
	REP(i, nb) REP(j, nc) read(0, i, j, 0);
	REP(i, nb) REP(j, nc) read(na - 1, i, j, 1);
	REP(i, na) REP(j, nc) read(i, 0, j, 2);
	REP(i, na) REP(j, nc) read(i, nb - 1, j, 3);
	REP(i, na) REP(j, nb) read(i, j, 0, 4);
	REP(i, na) REP(j, nb) read(i, j, nc - 1, 5);
	if (!solve()) { printf("-1\n"); return; }
	REP(i, na) { if (i != 0) puts(""); REP(j, nb) { REP(k, nc) { if (k != 0) printf(" "); printf("%d", ans[i*nb*nc + j*nc + k]); } puts(""); } }
}

int main() {
	run();
	return 0;
}
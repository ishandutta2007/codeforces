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

const int MAXCOL = 50;
const int MAXCAR = 2 * MAXCOL;

int ncol, ncar;
int g[4][MAXCOL];

pair<int, int> pos[MAXCAR + 1];
vector<pair<int,pair<int,int> > > ans;

void run() {
	scanf("%d%d", &ncol, &ncar);
	REP(x, 4) REP(y, ncol) scanf("%d", &g[x][y]);

	FORE(x, 1, 2) REP(y, ncol) if (g[x][y] != 0) pos[g[x][y]] = MP(x, y);
	int rem = ncar;
	while (rem>0) {
		bool any = false;
		FORE(i, 1, ncar) {
			int x = pos[i].first, y = pos[i].second;
			if (x == 0 || x == 3) continue;
			if (x == 1 && g[0][y] == i) { ans.PB(MP(i, MP(0, y))); g[x][y] = g[0][y] = 0; pos[i] = MP(0, y), --rem; any = true; continue; }
			if (x == 2 && g[3][y] == i) { ans.PB(MP(i, MP(3, y))); g[x][y] = g[3][y] = 0; pos[i] = MP(3, y), --rem; any = true; continue; }
			int nx, ny;
			if (x == 1 && y != ncol - 1) nx = x, ny = y + 1;
			else if (x == 1) nx = 2, ny = y;
			else if (y != 0) nx = x, ny = y - 1;
			else nx = 1, ny = y;
			if (g[nx][ny] != 0) continue;
			ans.PB(MP(i, MP(nx, ny))); g[x][y] = 0, g[nx][ny] = i, pos[i] = MP(nx, ny); any = true;
		}
		if(!any) break;
	}
	if (rem != 0) { printf("%d\n", -1); return; }
	printf("%d\n", SZ(ans)); REPSZ(i, ans) printf("%d %d %d\n", ans[i].first, ans[i].second.first + 1, ans[i].second.second + 1);
}

int main() {
	run();
	return 0;
}
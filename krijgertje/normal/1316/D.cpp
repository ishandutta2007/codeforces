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

const int MAXN = 1000;
const int DX[] = { -1,0,+1,0 }, DY[] = { 0,+1,0,-1 }; const char DC[] = { 'U','R','D','L' };

int n;
int tx[MAXN][MAXN], ty[MAXN][MAXN];
char ans[MAXN][MAXN + 1];

int qx[MAXN*MAXN], qy[MAXN*MAXN], qhead, qtail;

bool solve() {
	REP(x, n) REP(y, n) ans[x][y] = '?'; REP(x, n) ans[x][n] = '\0';
	REP(sx, n) REP(sy, n) if (tx[sx][sy] == sx && ty[sx][sy] == sy) {
		qhead = qtail = 0;
		assert(ans[sx][sy] == '?'); ans[sx][sy] = 'X'; qx[qhead] = sx, qy[qhead] = sy, ++qhead;
		while (qtail < qhead) {
			int x = qx[qtail], y = qy[qtail]; ++qtail;
			REP(k, 4) {
				int nx = x - DX[k], ny = y - DY[k]; if (nx < 0 || nx >= n || ny < 0 || ny >= n || tx[nx][ny] != sx || ty[nx][ny] != sy || ans[nx][ny] != '?') continue;
				ans[nx][ny] = DC[k], qx[qhead] = nx, qy[qhead] = ny, ++qhead;
			}
		}
	}
	REP(x, n) REP(y, n) if (tx[x][y] == -1 && ty[x][y] == -1) {
		REP(k, 4) {
			int nx = x + DX[k], ny = y + DY[k]; if (nx < 0 || nx >= n || ny < 0 || ny >= n || tx[nx][ny] != -1 || ty[nx][ny] != -1) continue;
			if (ans[x][y] == '?') ans[x][y] = DC[k];
		}
	}
	REP(x, n) REP(y, n) if (ans[x][y] == '?') return false;
	return true;
}

void run() {
	scanf("%d", &n);
	REP(x, n) REP(y, n) { scanf("%d%d", &tx[x][y], &ty[x][y]); if (tx[x][y] != -1) --tx[x][y]; if (ty[x][y] != -1) --ty[x][y]; }
	if (!solve()) { printf("INVALID\n"); return; }
	printf("VALID\n");
	REP(x, n) printf("%s\n", ans[x]);
}

int main() {
	run();
	return 0;
}
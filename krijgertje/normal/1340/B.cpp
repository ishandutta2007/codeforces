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

const int MAXN = 2000;
const int MAXBROKEN = 2000;
const int DIGITSEGMENTS = 7;
const char DIGITSTR[10][DIGITSEGMENTS + 1] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
int digitmask[10];
int bitcount[1 << DIGITSEGMENTS];

int n, nbroken;
char statestr[MAXN][DIGITSEGMENTS + 1];
int statemask[MAXN];
int ansdigit[MAXN];

pair<int, int> prv[MAXN + 1][MAXBROKEN + 1];

int parse(const char* s) { int ret = 0; REP(i, DIGITSEGMENTS) if (s[i] == '1') ret |= 1 << i; return ret; }

bool solve() {
	REP(i, 10) digitmask[i] = parse(DIGITSTR[i]);
	REP(i, n) statemask[i] = parse(statestr[i]);
	bitcount[0] = 0; FOR(mask, 1, 1 << DIGITSEGMENTS) bitcount[mask] = bitcount[mask >> 1] + (mask & 1);

	REPE(i, n) REPE(j, nbroken) prv[i][j] = MP(-2, -2);
	vector<int> order; 
	prv[0][0] = MP(-1, -1), order.PB(0);
	REP(i, n) {
		vector<int> norder;
		REPSZ(_, order) {
			int j = order[_];
			for (int k = 9; k >= 0; --k) {
				if ((statemask[i] & digitmask[k]) != statemask[i]) continue;
				int mnbroke = bitcount[digitmask[k] ^ statemask[i]];
				int mxbroke = mnbroke; // +bitcount[(1 << DIGITSEGMENTS) - 1 - digitmask[k]];
				//printf("k=%d -> %d..%d\n", k, mnbroke, mxbroke);
				FORE(x, mnbroke, mxbroke) {
					int ni = i + 1, nj = j + x;
					if (nj > nbroken) continue;
					if (prv[ni][nj] != MP(-2, -2)) continue;
					prv[ni][nj] = MP(j, k), norder.PB(nj);
				}
			}
		}
		swap(order, norder);
	}
	if (prv[n][nbroken] == MP(-2, -2)) return false;
	{
		int i = n, j = nbroken;
		while (prv[i][j] != MP(-1, -1)) {
			int ni = i - 1, nj = prv[i][j].first, k = prv[i][j].second;
			ansdigit[ni] = k;
			i = ni, j = nj;
		}
	}
	return true;
}


void run() {
	scanf("%d%d", &n, &nbroken);
	REP(i, n) scanf("%s", statestr[i]);
	if (!solve()) { printf("-1\n"); return; }
	REP(i, n) printf("%d", ansdigit[i]); puts("");
}

int main() {
	run();
	return 0;
}
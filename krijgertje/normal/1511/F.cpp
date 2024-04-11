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

const int MAXN = 8;
const int MAXLEN = 5;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n, chainlen;
char s[MAXN][MAXLEN + 1];

int nstate;
vector<pair<string, int>> states;
map<pair<string, int>, int> statemp;
vector<vector<int>> trans;

int ensurestate(const string& a, int b) {
	pair<string, int> key = MP(a, b);
	if (statemp.count(key)) return statemp[key];
	int ret = nstate++;
	states.PB(key);
	statemp[key] = ret;
	trans.PB(vector<int>());
	return ret;
}

const ll MODUNDOOVERFLOW = (1ULL << 63) / MOD * MOD;
vector<vector<int>> mmult(const vector<vector<int>>& a, const vector<vector<int>>& b) {
	int nrow = SZ(a), nmid = SZ(a[0]), ncol = SZ(b[0]); vector<vector<int>> ret(nrow, vector<int>(ncol));
	REP(i, nrow) REP(j, ncol) { ll sum = 0; REP(k, nmid) { sum += (ll)a[i][k] * b[k][j]; if (sum < 0) sum -= MODUNDOOVERFLOW; } ret[i][j] = sum % MOD; } return ret;
}
vector<vector<int>> mexp(vector<vector<int>> x, ll n) {
	int dim = SZ(x); vector<vector<int>> ret(dim, vector<int>(dim, 0)); REP(i, dim) ret[i][i] = 1;
	while (true) { if (n & 1) ret = mmult(ret, x); if ((n >>= 1) == 0) return ret; x = mmult(x, x); }
}

int solve() {
	nstate = 0;
	states.clear();
	statemp.clear();
	trans.clear();
	int startstate = ensurestate("", 0);
	REP(at, nstate) {
		if (states[at].second > 0) {
			int to = ensurestate(states[at].first, states[at].second - 1);
			trans[at].PB(to);
		} else if (SZ(states[at].first) > 0) {
			REP(j, n) {
				string a = states[at].first;
				string b = s[j];
				if (SZ(a) < SZ(b)) swap(a, b);
				bool ok = true;
				REPSZ(k, b) if (a[k] != b[k]) ok = false;
				if (!ok) continue;
				int to = ensurestate(a.substr(SZ(b)), SZ(b) - 1);
				trans[at].PB(to);
			}
		} else {
			REP(j1, n) REP(j2, n) {
				string a = s[j1];
				string b = s[j2];
				if (SZ(a) < SZ(b)) swap(a, b);
				bool ok = true;
				REPSZ(k, b) if (a[k] != b[k]) ok = false;
				if (!ok) continue;
				int to = ensurestate(a.substr(SZ(b)), SZ(b) - 1);
				trans[at].PB(to);
			}
		}
	}
	//REP(at, nstate) for (int to : trans[at]) printf("(%s,%d)->(%s,%d)\n", states[at].first.c_str(), states[at].second, states[to].first.c_str(), states[to].second);

	vector<vector<int>> A(nstate, vector<int>(nstate, 0));
	REP(at, nstate) for (int to : trans[at]) inc(A[at][to], 1);
	vector<vector<int>> B = mexp(A, chainlen);
	return B[0][0];
}

void run() {
	scanf("%d%d", &n, &chainlen);
	REP(i, n) scanf("%s", s[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}
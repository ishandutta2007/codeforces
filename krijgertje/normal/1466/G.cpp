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

const int MAXSONG = 100000;
const int MAXQ = 100000;
const int MOD = 1000000007;
const int INV2 = (MOD + 1) / 2;
const int ALPH = 26;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int nsong, nq;
string s;
string t;
int qsong[MAXQ]; string qname[MAXQ]; int qans[MAXQ];

int p2[MAXSONG + 1];
int ip2[MAXSONG + 1];
int suff[ALPH][MAXSONG + 1];

int calc(int at, int lim, const string& name, int offset, int step) {
	int len = (SZ(name) - offset + step - 1) / step;
	assert(len >= 1);
	//printf("calc(%d/%d:", at + 1, lim + 1); for (int i = offset; i < SZ(name); i += step) printf("%c", name[i]); printf(") [%d]\n", len);
	if (len == 1) {
		int ret = 0;
		//FORE(i, at, lim) if (t[i] == name[offset]) inc(ret, (ll)p2[nsong - i]); // TODO: optimize
		int x = name[offset] - 'a';
		ret = suff[x][at] - suff[x][lim + 1];
		if (ret < 0) ret += MOD;
		ret = (ll)ret * ip2[nsong - lim] % MOD;
		return ret;
	}
	if (at == lim) {
		return 0;
	}
	vector<bool> same(2, true);
	REP(j, 2) for (int k = offset + j * step + 2 * step; k < SZ(name); k += 2 * step) if (name[k] != name[k - 2 * step]) same[j] = false;
	int ret = 0;
	REP(j, 2) if (same[1 - j] && name[offset + (1 - j) * step] == t[at]) inc(ret, calc(at + 1, lim, name, offset + j * step, 2 * step));
	return ret;
}

void solve() {
	int period = SZ(s) + 1;
	p2[0] = 1; FORE(i, 1, nsong) p2[i] = (ll)p2[i - 1] * 2 % MOD;
	ip2[0] = 1; FORE(i, 1, nsong) ip2[i] = (ll)ip2[i - 1] * INV2 % MOD;
	REP(k, ALPH) { suff[k][nsong] = 0; for (int i = nsong - 1; i >= 0; --i) suff[k][i] = (suff[k][i + 1] + (t[i] == 'a' + k ? p2[nsong - i] : 0)) % MOD; }
	REP(i, nq) {
		string name = qname[i];
		//cout << name << endl;
		qans[i] = 0;
		vector<bool> same(period + 1, true);
		REP(j, period) for (int k = j + period; k < SZ(name); k += period) if (name[k] != name[k - period]) same[j] = false;
		int nsame = 0; REP(j, period) if (same[j]) ++nsame;
		if (nsame == period - 1) {
			REP(j, period) if (!same[j]) {
				bool ok = true;
				REP(k, period) if (k < SZ(name) && k != j) {
					if (name[k] != s[(k - (j + 1) + period) % period]) ok = false; // j+1 -> 0
				}
				if (!ok) continue;
				inc(qans[i], calc(0, qsong[i] - 1, name, j, period));
			}
		} else if (nsame == period) {
			REP(j, period) { // name[0] -> s[j]
				// name[0..alen)==s[j..j+alen)
				// name[alen+1..alen+1+blen)==s[0..blen)
				int alen = min(period - 1 - j, SZ(name));
				int blen = min(j, SZ(name) - alen - 1);
				bool ok = true;
				if (ok) REP(k, alen) if (name[k] != s[j + k]) { ok = false; break; } // TODO: optimize
				if (ok) REP(k, blen) if (name[alen + 1 + k] != s[k]) { ok = false; break; } // TODO: optimize
				if (!ok) continue;
				int idx = period - 1 - j;
				if (idx < SZ(name)) inc(qans[i], calc(0, qsong[i] - 1, name, idx, period)); else inc(qans[i], p2[qsong[i]]);
			}
		}

	}
}

void run() {
	cin >> nsong >> nq;
	cin >> s;
	cin >> t;
	REP(i, nq) cin >> qsong[i] >> qname[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	run();
	return 0;
}
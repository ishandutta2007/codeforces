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

const int MAXN = 800;

bool local = false;
int localval[MAXN];

bool query(const vector<int> &q) {
	assert(SZ(q) >= 1);
	if (!local) {
		printf("? %d", SZ(q)); REPSZ(i, q) printf(" %d", q[i] + 1); puts(""); fflush(stdout);
		int ret; scanf("%d", &ret); if (ret == -1) exit(0); return ret;
	} else {
		int sum = 0; REPSZ(i, q) sum += localval[q[i]]; return sum%SZ(q) == 0;
	}
}

int n;

int val[MAXN], pos[MAXN + 1];
int mod2[MAXN], mod3[MAXN], mod4[MAXN], mod5[MAXN], mod7[MAXN], mod8[MAXN];

int neg(int x, int mod) {
	int ret = (-x) % mod; if (ret < 0) ret += mod; return ret;
}

void solve() {
	// Init
	REP(i, n) val[i] = mod2[i] = mod3[i] = mod4[i] = mod5[i] = mod7[i] = mod8[i] = -1;
	FORE(i, 1, n) pos[i] = -1;

	// Determine 1 and n
	{
		vector<int> found;
		REP(i, n) { vector<int> q; REP(j, n) if (j != i) q.PB(j); if (query(q)) found.PB(i); }
		assert(SZ(found) == 2);
		int a = found[0], b = found[1];
		val[a] = 1, val[b] = n, pos[val[a]] = a, pos[val[b]] = b;
	}

	// Determine mod 2: 1+x
	REP(i, n) {
		if (val[i] != -1) { mod2[i] = val[i] % 2; continue; }
		vector<int> q; q.PB(pos[1]); q.PB(i); mod2[i] = query(q) ? 1 : 0;
	}

	// Determine 2 and n-1
	if (n >= 4) {
		vector<int> found;
		REP(i, n) if (val[i] == -1) { vector<int> q; REP(j, n) if (j != i&&val[j] == -1) q.PB(j); if (query(q)) found.PB(i); }
		assert(SZ(found) == 2);
		int a = found[0], b = found[1]; assert(mod2[a] != mod2[b]);
		val[a] = mod2[a] == 0 ? 2 : n - 1, val[b] = mod2[b] == 0 ? 2 : n - 1, pos[val[a]] = a, pos[val[b]] = b;
	}

	// Determine mod 3: 1+(n-1)+x / 1+n+x
	REP(i, n) {
		if (val[i] != -1) { mod3[i] = val[i] % 3; continue; }
		vector<int> q1; q1.PB(pos[1]); q1.PB(pos[n - 1]); q1.PB(i); if (query(q1)) { mod3[i] = neg(1 + n - 1, 3); continue; } // 1+n-1+x=0 mod 3
		vector<int> q2; q2.PB(pos[1]); q2.PB(pos[n]); q2.PB(i); if (query(q2)) { mod3[i] = neg(1 + n, 3); continue; } // 1+n+x=0 mod 3
		mod3[i] = neg(1 + n - 2, 3);
	}

	// Determine mod 4: 1+2+(n-1)+x / 1+2+n+x
	REP(i, n) {
		if (val[i] != -1) { mod4[i] = val[i] % 4; continue; }
		FORE(z, n - 1, n) if ((1 + 2 + z + mod2[i]) % 2 == 0) {
			vector<int> q; q.PB(pos[1]); q.PB(pos[2]); q.PB(pos[z]); q.PB(i); mod4[i] = query(q) ? neg(1 + 2 + z, 4) : neg(1 + 2 + z + 2, 4);
		}
	}

	// Determine 3 and n-2
	if (n >= 6) {
		vector<int> found;
		REP(i, n) if (val[i] == -1 && (mod3[i] == 3 % 3 && mod4[i] == 3 % 4 || mod3[i] == (n - 2) % 3 && mod4[i] == (n - 2) % 4)) {
			vector<int> q; REP(j, n) if (j != i && val[j] == -1) q.PB(j); if (query(q)) found.PB(i);
		}
		assert(SZ(found) == 2);
		int a = found[0], b = found[1]; assert(mod2[a] != mod2[b]);
		val[a] = mod2[a] == 0 ? n - 2 : 3, val[b] = mod2[b] == 0 ? n - 2 : 3, pos[val[a]] = a, pos[val[b]] = b;
	}

	// Determine mod 5: 1+2+(n-2)+(n-1)+x / 1+2+(n-2)+n+x / 1+2+(n-1)+n+x / 1+3+(n-1)+n+x
	REP(i, n) {
		if (val[i] != -1) { mod5[i] = val[i] % 5; continue; }
		vector<int> q1; q1.PB(pos[1]); q1.PB(pos[2]); q1.PB(pos[n - 2]); q1.PB(pos[n - 1]); q1.PB(i); if (query(q1)) { mod5[i] = neg(1 + 2 + n - 2 + n - 1, 5); continue; }
		vector<int> q2; q2.PB(pos[1]); q2.PB(pos[2]); q2.PB(pos[n - 2]); q2.PB(pos[n]); q2.PB(i); if (query(q2)) { mod5[i] = neg(1 + 2 + n - 2 + n, 5); continue; }
		vector<int> q3; q3.PB(pos[1]); q3.PB(pos[2]); q3.PB(pos[n - 1]); q3.PB(pos[n]); q3.PB(i); if (query(q3)) { mod5[i] = neg(1 + 2 + n - 1 + n, 5); continue; }
		vector<int> q4; q4.PB(pos[1]); q4.PB(pos[3]); q4.PB(pos[n - 1]); q4.PB(pos[n]); q4.PB(i); if (query(q4)) { mod5[i] = neg(1 + 3 + n - 1 + n, 5); continue; }
		mod5[i] = neg(2 + 3 + n - 1 + n, 5);
	}

	// Determine 4 and n-3
	if (n >= 8) {
		vector<int> found;
		REP(i, n) if (val[i] == -1 && (mod3[i] == 4 % 3 && mod4[i] == 4 % 4 && mod5[i] == 4 % 5 || mod3[i] == (n - 3) % 3 || mod4[i] == (n - 3) % 4 || mod5[i] == (n - 3) % 5)) {
			vector<int> q; REP(j, n) if (j != i && val[j] == -1) q.PB(j); if (query(q)) found.PB(i);
		}
		assert(SZ(found) == 2);
		int a = found[0], b = found[1]; assert(mod2[a] != mod2[b]);
		val[a] = mod2[a] == 0 ? 4 : n - 3, val[b] = mod2[b] == 0 ? 4 : n - 3, pos[val[a]] = a, pos[val[b]] = b;
	}

	// Determine mod 7: 1+2+3+(n-3)+(n-2)+(n-1)+x / 1+2+3+(n-3)+(n-2)+n+x / 1+2+3+(n-3)+(n-1)+n+x / 1+2+3+(n-2)+(n-1)+n+x / 1+2+4+(n-2)+(n-1)+n+x / 1+3+4+(n-2)+(n-1)+n+x
	REP(i, n) {
		if (val[i] != -1) { mod7[i] = val[i] % 7; continue; }
		vector<int> q1; q1.PB(pos[1]); q1.PB(pos[2]); q1.PB(pos[3]); q1.PB(pos[n - 3]); q1.PB(pos[n - 2]); q1.PB(pos[n - 1]); q1.PB(i); if (query(q1)) { mod7[i] = neg(1 + 2 + 3 + n - 3 + n - 2 + n - 1, 7); continue; }
		vector<int> q2; q2.PB(pos[1]); q2.PB(pos[2]); q2.PB(pos[3]); q2.PB(pos[n - 3]); q2.PB(pos[n - 2]); q2.PB(pos[n]); q2.PB(i); if (query(q2)) { mod7[i] = neg(1 + 2 + 3 + n - 3 + n - 2 + n, 7); continue; }
		vector<int> q3; q3.PB(pos[1]); q3.PB(pos[2]); q3.PB(pos[3]); q3.PB(pos[n - 3]); q3.PB(pos[n - 1]); q3.PB(pos[n]); q3.PB(i); if (query(q3)) { mod7[i] = neg(1 + 2 + 3 + n - 3 + n - 1 + n, 7); continue; }
		vector<int> q4; q4.PB(pos[1]); q4.PB(pos[2]); q4.PB(pos[3]); q4.PB(pos[n - 2]); q4.PB(pos[n - 1]); q4.PB(pos[n]); q4.PB(i); if (query(q4)) { mod7[i] = neg(1 + 2 + 3 + n - 2 + n - 1 + n, 7); continue; }
		vector<int> q5; q5.PB(pos[1]); q5.PB(pos[2]); q5.PB(pos[4]); q5.PB(pos[n - 2]); q5.PB(pos[n - 1]); q5.PB(pos[n]); q5.PB(i); if (query(q5)) { mod7[i] = neg(1 + 2 + 4 + n - 2 + n - 1 + n, 7); continue; }
		vector<int> q6; q6.PB(pos[1]); q6.PB(pos[3]); q6.PB(pos[4]); q6.PB(pos[n - 2]); q6.PB(pos[n - 1]); q6.PB(pos[n]); q6.PB(i); if (query(q6)) { mod7[i] = neg(1 + 3 + 4 + n - 2 + n - 1 + n, 7); continue; }
		mod7[i] = neg(2 + 3 + 4 + n - 2 + n - 1 + n, 7);
	}

	// Determine mod 8: 1+2+3+4+(n-3)+(n-2)+(n-1)+x / 1+2+3+4+(n-3)+(n-2)+n+x / 1+2+3+4+(n-3)+(n-1)+n+x / 1+2+3+4+(n-2)+(n-1)+n+x
	REP(i, n) {
		if (val[i] != -1) { mod8[i] = val[i] % 8; continue; }
		FORE(z, n - 3, n) if ((1 + 2 + 3 + 4 + n - 3 + n - 2 + n - 1 + n - z + mod4[i]) % 4 == 0) {
			vector<int> q; q.PB(pos[1]); q.PB(pos[2]); q.PB(pos[3]); q.PB(pos[4]); FORE(y, n - 3, n) if (y != z) q.PB(pos[y]); q.PB(i); mod8[i] = query(q) ? neg(1 + 2 + 3 + 4 + (n - 3) + (n - 2) + (n - 1) + n - z, 8) : neg(1 + 2 + 3 + 4 + (n - 3) + (n - 2) + (n - 1) + n - z + 4, 8);
		}
	}

	//REP(i, n) printf("%d: %d %d %d %d\n", i, mod3[i], mod5[i], mod7[i], mod8[i]);

	// Determine all numbers (mod 3*5*7*8=840)
	REP(i, n) {
		int found = -1; FORE(v, 1, n) if (v % 3 == mod3[i] && v % 5 == mod5[i] && v % 7 == mod7[i] && v % 8 == mod8[i]) { assert(found == -1); found = v; } assert(found != -1);
		if (val[i] != -1) { assert(val[i] == found); continue; }
		assert(pos[found] == -1); val[i] = found, pos[found] = i;
	}

	// Possibly invert solution
	if (val[0] > n / 2) REP(i, n) val[i] = n + 1 - val[i];
}

void run() {
	scanf("%d", &n);
	solve();
	printf("!"); REP(i, n) printf(" %d", val[i]); puts(""); fflush(stdout);
}

void stress() {
	for (n = 2; n <= MAXN; n += 2) {
		printf("processing %d: ", n);
		REP(rep, 10) {
			local = true; REP(i, n) localval[i] = i + 1; REP(i, n) { int idx = rand() % (i + 1); swap(localval[i], localval[idx]); }
			if (localval[0] > n / 2) REP(i, n) localval[i] = n + 1 - localval[i];
			solve();
			REP(i, n) assert(val[i] == localval[i]);
			printf(".");
		}
		puts("");
	}
}

int main() {
	run();
	//stress();
	return 0;
}
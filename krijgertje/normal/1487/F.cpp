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

string s;

bool isgreater(const string& a, const string& b) {
	if (SZ(a) != SZ(b)) return SZ(a) > SZ(b);
	return a > b;
}
void sub(string& a, const string& b) {
	int carry = 0;
	for (int i = 0; i < SZ(b) || carry != 0; ++i) {
		assert(i < SZ(a));
		carry += a[SZ(a) - i - 1] - '0';
		if (i < SZ(b)) carry -= b[SZ(b) - i - 1] - '0';
		a[SZ(a) - i - 1] = '0' + (carry % 10 + 10) % 10;
		carry -= a[SZ(a) - i - 1] - '0';
		assert(carry % 10 == 0);
		carry /= 10;
	}
	while (SZ(a) >= 2 && a[0] == '0') a = a.substr(1);
}

int getval(const string& s) { int ret = 0; REPSZ(i, s) { int x = s[i] - '0'; if (ret > (INT_MAX - x) / 10) return INT_MAX; ret = ret * 10 + x; } return ret; }

int solve() {
	vector<string> terms;
	terms.PB("1");
	while (!isgreater(terms.back(), s)) terms.PB("1" + terms.back());

	string curmx = s;
	int dplen = 1;
	vector<int> dppos = { 0 };
	vector<int> dpneg = { SZ(terms.back()) };
	auto relax = [&](int& a, int b) { a = min(a, b); };
	for (int i = SZ(terms) - 2; i >= 0; --i) {
		string curterm = terms[i];
		string prvmx = curmx;
		int times = 0;
		while (!isgreater(curterm, curmx)) ++times, sub(curmx, curterm);
		int ndplen = min(dplen + 1, getval(curterm));
		int prvzero = getval(prvmx);
		int curzero = getval(curmx);
		vector<int> ndppos = vector<int>(ndplen, INT_MAX);
		vector<int> ndpneg = vector<int>(ndplen, INT_MAX);
		// prvmx-j+I[j>prvzero]*prvterm-times*curterm=curmx-to+I[to>curzero]*curterm
		// prvmx-j+I[j>prvzero]*prvterm-prvterm+(10-times-I[to+1==curzero])*curterm=curmx-(to+1)+I[to+1>curzero]*curterm
		int to = 0;
		REP(j, dplen) {
			if (dppos[j] != INT_MAX) relax(ndppos[to], dppos[j] + times * SZ(curterm));
			if (dppos[j] != INT_MAX) relax(ndpneg[to], dppos[j] + (times + 1) * SZ(curterm));
			if (dpneg[j] != INT_MAX) relax(ndpneg[(to + 1) % ndplen], dpneg[j] + abs(9 - times + (to == curzero ? 1 : 0)) * SZ(curterm));
			if (dpneg[j] != INT_MAX) relax(ndppos[(to + 1) % ndplen], dpneg[j] + abs(10 - times + (to == curzero ? 1 : 0)) * SZ(curterm));
			++to;
			if (j == prvzero) times += 10, --to;
			if (to == curzero + 1) --times;
			if (to == ndplen) to = 0;
			assert(times >= 0 && times <= 10 && to >= 0 && to < ndplen);
		}
		dplen = ndplen, dppos = ndppos, dpneg = ndpneg;
		//printf("curmx=%s (%d)\n", curmx.c_str(), times);
		//printf("dppos:"); REPSZ(j, dppos) printf(" %d", dppos[j]); puts("");
		//printf("dpneg:"); REPSZ(j, dpneg) printf(" %d", dpneg[j]); puts("");
	}
	return dppos[0];
}

void run() {
	cin >> s;
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}
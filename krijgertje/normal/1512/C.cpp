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

const int MAXLEN = 200000;

int n0, n1;
char s[MAXLEN + 1];
char ans[MAXLEN + 1];

bool solve() {
	int n = n0 + n1;
	assert(strlen(s) == n);
	REP(i, n) ans[i] = '?'; ans[n] = '\0';
	int rem0 = n0, rem1 = n1;
	REP(i, n) {
		int j = n - i - 1;
		if (i < j) {
			char a = s[i];
			char b = s[j];
			if (a != '?' && b != '?' && a != b) return false;
			if (a == '?' && b == '?') continue;
			if (a == '?') swap(a, b);
			ans[i] = ans[j] = a;
			if (a == '0') rem0 -= 2; else rem1 -= 2;
		} else if (i == j) {
			char a = s[i];
			if(a == '?') continue;
			ans[i] = a;
			if (a == '0') --rem0; else --rem1;
		}
	}
	REP(i, n) {
		int j = n - i - 1;
		if (i < j) {
			char a = s[i];
			char b = s[j];
			if (a != '?' || b != '?') continue;
			if (rem0 >= 2) ans[i] = ans[j] = '0', rem0 -= 2; else if (rem1 >= 2) ans[i] = ans[j] = '1', rem1 -= 2; else return false;
		} else if (i == j) {
			char a = s[i];
			if (a != '?') continue;
			if (rem0 % 2 == 1) ans[i] = '0', --rem0; else if (rem1 % 2 == 1) ans[i] = '1', --rem1; else return false;
		}
	}
	return rem0 == 0 && rem1 == 0;
}

void run() {
	scanf("%d%d", &n0, &n1);
	scanf("%s", s);
	if (!solve()) { printf("-1\n"); return; }
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}
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

const int MAXN = 500000;

int n;
int b[MAXN];
int a[MAXN];

vector<int> subsetsum(vector<int> a) { for (int bit = 0; (1 << bit) < SZ(a); ++bit) REPSZ(i, a) if (i & (1 << bit)) a[i] ^= a[i ^ (1 << bit)]; return a; }
vector<int> supersetsum(vector<int> a) { for (int bit = 0; (1 << bit) < SZ(a); ++bit) REPSZ(i, a) if ((i & (1 << bit)) == 0) a[i] ^= a[i ^ (1 << bit)]; return a; }
vector<int> fix_subsetsuff_change_pref(vector<int> a, vector<int> want) {
	reverse(want.begin(), want.end());
	want = subsetsum(want);
	a = supersetsum(a);
	REPSZ(i, want) a[i] = want[i];
	a = supersetsum(a);
	return a;
}
void solve() {
	int sz = 1;
	while (sz < n) sz *= 2;
	vector<int> bb(sz, 0);
	REP(i, n) bb[sz - i - 1] = b[i];
	bb = fix_subsetsuff_change_pref(bb, vector<int>(sz - n, 0));
	vector<int> aa = subsetsum(bb);
	REP(i, n) a[n - i - 1] = aa[i];
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &b[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
}

int main() {
	run();
	return 0;
}
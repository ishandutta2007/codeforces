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

const int MAXN = 200000;
const int MAXQ = 200000;

int n;
int vol[MAXN];
int nq;
int qt[MAXQ];
int qans[MAXQ];

void solve() {
	ll sum = 0;
	int need = 0;
	REP(i, n) {
		sum += vol[i];
		need = max(need, (int)((sum + i) / (i + 1)));
	}
	REP(i, nq) {
		int t = qt[i];
		qans[i] = t < need ? -1 : (int)((sum + t - 1) / t);
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &vol[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d", &qt[i]);
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}
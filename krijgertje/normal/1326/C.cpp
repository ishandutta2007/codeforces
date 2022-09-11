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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 200000;
const int MOD = 998244353;

int n, npart;
int a[MAXN];
ll ansmx; int anscnt;

bool used[MAXN];

void solve() {
	int mnuse = n - (npart)+1;
	REP(i, n) used[i] = a[i] >= mnuse;
	ansmx = 0; REP(i, n) if (used[i]) ansmx += a[i];
	anscnt = 1;
	REP(i, n) if (used[i]) {
		int j = i + 1; while (j < n && !used[j]) ++j; if (j >= n) continue;
		int between = j - i - 1;
		anscnt = (ll)anscnt * (between + 1) % MOD;
	}
}

void run() {
	scanf("%d%d", &n, &npart);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	printf("%lld %d\n", ansmx, anscnt);
}

int main() {
	run();
	return 0;
}
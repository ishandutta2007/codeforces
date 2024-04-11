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

const int MAXN = 500;

int n;
int a[MAXN];

bool can[MAXN][MAXN];
int dp[MAXN + 1];

int stck[MAXN], nstck;

void upd(int& a, int b) { a = min(a, b); }
int solve() {
	REP(i, n) {
		nstck = 0;
		FOR(j, i, n) {
			stck[nstck++] = a[j];
			while (nstck >= 2 && stck[nstck - 2] == stck[nstck - 1]) --nstck, ++stck[nstck - 1];
			//printf("[%d..%d]:", i, j); REP(k, nstck) printf(" %d", stck[k]); puts("");
			can[i][j] = nstck == 1;
		}
	}
	//REP(i, n) FORE(j, i, n) if (can[i][j]) printf("[%d..%d]\n", i, j);
	REPE(i, n) dp[i] = INT_MAX;
	dp[0] = 0;
	REP(i, n) FOR(j, i, n) if (can[i][j]) upd(dp[j + 1], dp[i] + 1);
	return dp[n];
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}


int main() {
	run();
	return 0;
}
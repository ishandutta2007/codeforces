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

const int MAXN = 200000;

int n;
int a[MAXN];
int lo[MAXN];
int hi[MAXN];

void solve() {
	REP(rep, 2) {
		deque<int> q;
		int at = 1;
		REP(i, n) {
			if (i == 0 || a[i] != a[i - 1]) {
				(rep == 0 ? lo : hi)[i] = a[i];
				while (at < a[i]) q.push_back(at++);
				at++;
			} else {
				if (rep == 0) {
					lo[i] = q.front(); q.pop_front();
				} else {
					hi[i] = q.back(); q.pop_back();
				}
			}
		}
	}
}


void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", lo[i]); } puts("");
	REP(i, n) { if (i != 0) printf(" "); printf("%d", hi[i]); } puts("");
}


int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}
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
#include <array>
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

int n;
vector<int> a;


void maxi(ll& a, ll b) { a = max(a, b); }
void mini(ll& a, ll b) { a = min(a, b); }
ll solve() {
	array<ll, 6> mx = { 1, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN };
	array<ll, 6> mn = { 1, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX };
	REP(i, n) {
		for (int j = 4; j >= 0; --j) {
			if (mx[j] != LLONG_MIN) maxi(mx[j + 1], mx[j] * a[i]), mini(mn[j + 1], mx[j] * a[i]);
			if (mn[j] != LLONG_MAX) maxi(mx[j + 1], mn[j] * a[i]), mini(mn[j + 1], mn[j] * a[i]);
		}
	}
	return mx[5];
}

void run() {
	scanf("%d", &n);
	a = vector<int>(n); REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}
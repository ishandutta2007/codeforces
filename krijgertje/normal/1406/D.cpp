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

int n;
vector<int> a;
int nq;
vector<int> ql, qr, qx; vector<ll> qans;

vector<ll> d;

ll dvup(ll num, ll den) { if (num >= 0) return (num + den - 1) / den; else return num / den; }
void solve() {
	d = vector<ll>(n); d[0] = a[0]; FOR(i, 1, n) d[i] = a[i] - a[i - 1];
	ll sumpos = 0;
	REP(i, n) if (i == 0 || d[i] > 0) sumpos += d[i];
	REPE(i, nq) {
		qans[i] = dvup(sumpos, 2);
		if (i == nq) break;
		int l = ql[i], r = qr[i], x = qx[i];
		if (true) {
			if (l == 0 || d[l] > 0) sumpos -= d[l];
			d[l] += x;
			if (l == 0 || d[l] > 0) sumpos += d[l];
		}
		if (r != n - 1) {
			if (d[r + 1] > 0) sumpos -= d[r + 1];
			d[r + 1] -= x;
			if (d[r + 1] > 0) sumpos += d[r + 1];
		}
	}
}

void run() {
	scanf("%d", &n);
	a = vector<int>(n); REP(i, n) scanf("%d", &a[i]);
	scanf("%d", &nq);
	ql = qr = qx = vector<int>(nq); REP(i, nq) scanf("%d%d%d", &ql[i], &qr[i], &qx[i]), --ql[i], --qr[i];
	qans = vector<ll>(nq + 1);
	solve();
	REPSZ(i, qans) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}
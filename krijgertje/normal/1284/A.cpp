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

const int MAXN = 20;
const int MAXQ = 2020;

int na, nb;
string a[MAXN];
string b[MAXN];
int nq;
int q[MAXQ]; string qans[MAXQ];

void solve() {
	REP(i, nq) {
		qans[i] = a[q[i] % na] + b[q[i] % nb];
	}
}

void run() {
	scanf("%d%d", &na, &nb);
	REP(i, na) cin >> a[i];
	REP(i, nb) cin >> b[i];
	scanf("%d", &nq);
	REP(i, nq) scanf("%d", &q[i]), --q[i];
	solve();
	REP(i, nq) printf("%s\n", qans[i].c_str());
}

int main() {
	run();
	return 0;
}
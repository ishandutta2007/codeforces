#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 100;

int n;
int a[2 * MAXN];

vector<int> pos[MAXN];

void run() {
	scanf("%d", &n);
	REP(i, 2 * n) scanf("%d", &a[i]), --a[i];

	REP(i, 2 * n) pos[a[i]].PB(i);
	int ret = 0;
	REP(i, n) FOR(j, i + 1, n) {
		int a = pos[i][0], b = pos[i][1], c = pos[j][0], d = pos[j][1];
		if (b < c || d < a) ret += 0;
		else if (a < c && d < b || c < a && b < d) ret += 2;
		else ret += 1;
	}
	printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}
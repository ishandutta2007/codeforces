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

char solve(int x, int y) {
	if (x == y) return '=';
	if (x == 1) return '<';
	if (y == 1) return '>';
	if (x == 2) return y == 3 ? '<' : y == 4 ? '=' : '>';
	if (y == 2) return x == 3 ? '>' : x == 4 ? '=' : '<';
	return x < y ? '>' : '<';
}

void run() {
	int x, y; scanf("%d%d", &x, &y);
	printf("%c", solve(x, y));
}

int main() {
	run();
	return 0;
}
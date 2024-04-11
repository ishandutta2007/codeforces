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

char s[MAXN + 1]; int n;

char ret[MAXN + 1]; int nret;

void run() {
	scanf("%d%s", &n, s); n = strlen(s);
	nret = 0; int at = 0;
	while (at < n) {
		if (at + 2 < n&&s[at] == 'o'&&s[at + 1] == 'g'&&s[at + 2] == 'o') {
			REP(i, 3) ret[nret++] = '*';
			at += 3; while (at + 1 < n&&s[at] == 'g'&&s[at + 1] == 'o') at += 2;
		} else {
			ret[nret++] = s[at++];
		}
	}
	ret[nret] = '\0';
	printf("%s\n", ret);
}

int main() {
	run();
	return 0;
}
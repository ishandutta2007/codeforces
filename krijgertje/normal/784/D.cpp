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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN = 10;
const int rev[10] = { 8,-1,-1,3,6,9,4,7,0,5 };

char s[MAXLEN + 1]; int slen;

bool solve() {
	for (int i = 0; i <= slen - i - 1; ++i) {
		int a = s[i] - '0', b = s[slen - i - 1] - '0';
		if (rev[a] == -1 || rev[a] != b) return false;
	}
	return true;
}

void run() {
	scanf("%s", s); slen = strlen(s);
	printf("%s\n", solve() ? "Yes" : "No");
}

int main() {
	run();
	return 0;
}
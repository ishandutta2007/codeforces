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

const int MAXLEN = 100;

char s[MAXLEN + 1]; int slen;

bool isvow(char c) { return c == 'a' || c == 'o' || c == 'u' || c == 'i' || c == 'e'; }
bool solve() {
	REP(i, slen) if (!isvow(s[i]) && s[i] != 'n' && (i + 1 >= slen || !isvow(s[i + 1]))) return false;
	return true;
}

void run() {
	scanf("%s", s); slen = strlen(s);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}
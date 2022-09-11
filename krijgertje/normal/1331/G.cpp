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

/*
for $next=1..11 {
	$var = readline from STDIN
	$var.trim()
	@seq.push($var)
}

for $next=1..11 {
	$var=@seq.pop()
	$aresult=sqrt(abs($var))
	$bresult=($var^3)*5
	$result=$aresult+$bresult

	if !(400<$result) {
		print "f(%d) = %.2f" ,$var,$result
		println()
	cis
	if (400<$result) {
		print "f(%d) = MAGNA NIMIS!" $var
		println()
	}
}
*/

const int N = 11;
int a[N];

void run() {
	REP(i, N) scanf("%d", &a[i]);
	for (int i = N - 1; i >= 0; --i) {
		double res = sqrt(abs(a[i])) + 5 * pow(a[i], 3);
		if (res <= 400) printf("f(%d) = %.2lf\n", a[i], res); else printf("f(%d) = MAGNA NIMIS!\n", a[i]);
	}
}

int main() {
	run();
	return 0;
}
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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll shpme; int sdamme;
ll shpopp; int sdamopp; 
int ncoin; int deltadam; ll deltahp;

bool solve() {
	REPE(i, ncoin) {
		ll hpme = shpme + i * deltahp;
		int damme = sdamme + (ncoin - i) * deltadam;
		ll hpopp = shpopp; int damopp = sdamopp;
		ll needme = (hpopp + damme - 1) / damme;
		ll needopp = (hpme + damopp - 1) / damopp;
		if (needme <= needopp) return true;
	}
	return false;
}

void run() {
	scanf("%lld%d", &shpme, &sdamme);
	scanf("%lld%d", &shpopp, &sdamopp);
	scanf("%d%d%lld", &ncoin, &deltadam, &deltahp);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}
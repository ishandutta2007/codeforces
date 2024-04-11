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

const int MAXN = 100000;
const int MAXSPECIAL = 26;
const int ALPH = 26;

int n;
char s[MAXN + 1];
int nspecial;
char special[MAXSPECIAL];

int solve() {
	vector<bool> isspecial(ALPH, false);
	REP(i, nspecial) isspecial[special[i] - 'a'] = true;
	vector<int> lst;
	REP(i, n) if (isspecial[s[i] - 'a']) lst.PB(i);
	int ret = 0;
	while (true) {
		//printf("lst:"); REPSZ(i, lst) printf(" %d", lst[i]); puts("");
		if (SZ(lst) == 0 || SZ(lst) == 1 && lst[0] == 0) break;
		vector<int> nlst;
		int killed = 0;
		REPSZ(i, lst) {
			if (i != 0 || lst[i] != 0) ++killed;
			int me = lst[i] - killed;
			while (SZ(nlst) > 0 && nlst.back() == me) nlst.pop_back();
			nlst.PB(me);
		}
		lst = nlst, ++ret;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", s);
	scanf("%d", &nspecial);
	REP(i, nspecial) scanf(" %c", &special[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}
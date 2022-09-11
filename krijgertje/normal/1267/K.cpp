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

ll key;

ll choose(int n, int k) {
	if (k<0 || k>n) return 0;
	ll ret = 1; FORE(i, 1, n) ret *= i; FORE(i, 1, k) ret /= i; FORE(i, 1, n - k) ret /= i; return ret;
}

ll calc(vector<int> finger) {
	//printf("calc:"); REPSZ(i, finger) printf(" %d", finger[i]); puts("");
	ll ret = 1;
	int before = 0;
	for (int l = 0, r = l; l < SZ(finger); l = r) {
		int val = finger[l];
		while (r < SZ(finger) && finger[r] == val) ++r;
		int cnt = r - l;
		int opt = SZ(finger) - max(0, val - 1) - before;
		//printf("\tval=%d cnt=%d opt=%d\n", val, cnt, opt);
		ret *= choose(opt, cnt);
		before += cnt;
	}
	//printf("-> %lld\n", ret);
	return ret;
}

ll solve() {
	vector<int> finger;
	{
		ll x = key; int den = 2;
		while (x > 0) { finger.PB(x%den); x /= den; ++den; }
	}
	sort(finger.begin(), finger.end());
	reverse(finger.begin(), finger.end());
	ll total = calc(finger);
	if (finger.back() == 0) { vector<int> invalid = finger;  invalid.pop_back(); total -= calc(invalid); }
	return total - 1;
}

void run() {
	scanf("%lld", &key);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}
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

const int MAXN = 2000000;

int n;
int cat[MAXN];

vector<int> opt;
void addopt(int x) { if (SZ(opt) > 0 && opt[SZ(opt) - 1] == x) return; opt.PB(x); }

int cnt[MAXN + 1];
int freq[MAXN + 1];
vector<pair<int, int>> have;

int solve() {
	opt.clear();
	for (int i = n; i >= 1; --i) {
		int each = n / i;
		if (n%i == 0) addopt(each);
		addopt(each + 1);
	}
	//printf("opt:"); REPSZ(i, opt) printf(" %d", opt[i]); puts("");

	FORE(i, 1, n) cnt[i] = 0;
	REP(i, n) ++cnt[cat[i]];
	FORE(i, 1, n) freq[i] = 0;
	FORE(i, 1, n) if (cnt[i] > 0) ++freq[cnt[i]];
	have.clear();
	FORE(i, 1, n) if (freq[i] > 0) have.PB(MP(i, freq[i]));
	//printf("have:"); REPSZ(i, have) printf(" %d*%d", have[i].second, have[i].first); puts("");

	for (int i = SZ(opt) - 1; i >= 0; --i) {
		int s = opt[i];
		bool ok = true; int cur = 0;
		REPSZ(j, have) {
			int x = have[j].first, times = have[j].second;
			int screens = (x + s - 1) / s;
			int empty = screens*s - x;
			//printf("\ts=%d x=%d -> screens=%d\n", s, x, screens);
			if (empty > screens) { ok = false; break; }
			cur += screens*times;
		}
		if (ok) return cur;
	}

	return -1;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &cat[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}
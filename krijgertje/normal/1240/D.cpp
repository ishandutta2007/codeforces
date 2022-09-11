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

const int MAXN = 300000;

int n;
int a[MAXN];

int nxt[MAXN + 1];
map<int, int> mp[MAXN + 1];
int mpidx[MAXN + 1];
int len[MAXN + 1];

ll solve() {
	nxt[n] = -1;
	mpidx[n] = n, mp[n].clear();
	for (int i = n - 1; i >= 0; --i) {
		int idx = mpidx[i + 1];
		auto it = mp[idx].find(a[i]);
		if (it != mp[idx].end()) {
			nxt[i] = it->second + 1;
			assert(mpidx[nxt[i]] != -1);
			mpidx[i] = mpidx[nxt[i]];
			mpidx[nxt[i]] = -1;
			if (nxt[i] < n) mp[mpidx[i]][a[nxt[i]]] = nxt[i];
		} else {
			nxt[i] = -1;
			mpidx[i] = i, mp[i].clear();
		}
		mp[mpidx[i]][a[i]] = i;
		/*int at = i + 1;
		while (at < n && a[at] != a[i] && nxt[at] != -1) at = nxt[at];
		nxt[i] = at < n && a[at] == a[i] ? at + 1 : -1;*/
	}
	len[n] = 0;
	for (int i = n - 1; i >= 0; --i) {
		len[i] = nxt[i] == -1 ? 0 : 1 + len[nxt[i]];
	}
	ll ret = 0; REP(i, n) ret += len[i]; return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}
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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 1000;

int n;
char s[MAXN + 1];
string ans;

void solve() {
	queue<pair<string, vector<int>>> q;
	vector<int> all;
	REPE(i, n) all.PB(i);
	q.push(MP("", all));
	while (!q.empty()) {
		string pref = q.front().first;
		vector<int> pos = q.front().second;
		q.pop();
		//printf("processing '%s' (%d)\n", pref.c_str(), SZ(pos));
		vector<vector<int>> npos(26);
		for (int i : pos) {
			if (i == n) continue;
			npos[s[i] - 'a'].PB(i + 1);
		}
		REP(i, 26) {
			string npref = pref + string(1, 'a' + i);
			if (SZ(npos[i]) == 0) { ans = npref; return; }
			q.push(MP(npref, npos[i]));
		}
	}
	assert(false);
}

void run() {
	scanf("%d", &n);
	scanf("%s", s);
	solve();
	printf("%s\n", ans.c_str());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}
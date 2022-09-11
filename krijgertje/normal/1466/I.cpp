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

const int MAXN = 200;
const int MAXB = 200;

int n, b;

bool isbigger(int idx, string s) {
	printf("%d %s\n", idx + 1, s.c_str()); fflush(stdout);
	char ans[10]; scanf("%s", ans);
	return strcmp(ans, "yes") == 0;
}

string solve() {
	queue<int> q;
	REP(i, n) q.push(i);
	string ret; // all items start with something <= ret
	string cur;
	vector<int> stck; 
	// SZ(cur)==SZ(stck)
	// a[stck[i]] start with something <= ret+cur.substr(0,i+1)
	// at least one item starts with something >= ret+cur
	while (SZ(ret) < b) {
		while (!q.empty()) {
			int at = q.front(); q.pop();
			while (cur != string(SZ(cur), '1') && isbigger(at, ret + cur + string(b - SZ(ret) - SZ(cur), '1'))) {
				cur.pop_back(); stck.pop_back();
			}
			if (SZ(ret) + SZ(cur) == b) continue;
			if (isbigger(at, ret + cur + "0" + string(b - SZ(ret) - SZ(cur) - 1, '1'))) {
				cur += "1"; stck.PB(at);
			} else {
				cur += "0"; stck.PB(at);
			}
		}
		assert(SZ(cur) > 0);
		bool anyzero = false;
		for (int i = SZ(stck) - 2; i >= 0; --i) {
			int at = stck[i];
			if (cur[i + 1] == '0') anyzero = true;
			if (anyzero && isbigger(at, ret + cur + string(b - SZ(ret) - SZ(cur), '1'))) {
				while (SZ(cur) > i + 1) { cur.pop_back(); stck.pop_back(); }
				anyzero = false;
			}
		}
		ret += cur;
		cur = "";
		while (SZ(stck) > 0) q.push(stck.back()), stck.pop_back();
	}
	return ret;
}


void run() {
	scanf("%d%d", &n, &b);
	string ans = solve();
	printf("0 %s\n", ans.c_str()); fflush(stdout);
}

int main() {
	run();
	return 0;
}
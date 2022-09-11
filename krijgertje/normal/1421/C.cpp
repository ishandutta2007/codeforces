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

string s;
vector<pair<char, int>> ans;

void solve() {
	ans.clear();
	int n = SZ(s);
	ans.PB(MP('L', n - 2));
	ans.PB(MP('R', n - 2));
	ans.PB(MP('R', 2 * n - 2));
	/*string t = s;
	REPSZ(i, ans) {
		int idx = ans[i].second;
		assert(idx >= 1 && idx < SZ(t) - 1);
		if (ans[i].first == 'L') {
			string tmp = t.substr(1, idx);
			reverse(tmp.begin(), tmp.end());
			t = tmp + t;
		}
		if (ans[i].first == 'R') {
			string tmp = t.substr(idx, SZ(t) - idx - 1);
			reverse(tmp.begin(), tmp.end());
			t = t + tmp;
		}
		cout << t << endl;
	}
	string u = t; reverse(u.begin(), u.end()); assert(u == t);*/

}

void run() {
	cin >> s;
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%c %d\n", ans[i].first, ans[i].second + 1);

}

int main() {
	run();
	return 0;
}
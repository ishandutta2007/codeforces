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

const int MAXN = 100;

int n;

vector<string> query(int l, int r) {
	printf("? %d %d\n", l + 1, r + 1); fflush(stdout);
	vector<string> ret;
	int len = r - l + 1;
	int cnt = (1 + len) * len / 2;
	char buff[MAXN + 1];
	REP(i, cnt) { scanf("%s", buff); if (strcmp(buff, "-") == 0) exit(0); ret.PB(buff); }
	return ret;
}

char diff(string a, string b) {
	assert(SZ(a) == SZ(b) + 1);
	int idx = 0; while (idx < SZ(b) && a[idx] == b[idx]) ++idx;
	FORSZ(i, idx + 1, a) assert(a[i] == b[i - 1]);
	return a[idx];
}

string diffchars(string a, string b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ai = 0, bi = 0; string ret;
	while (ai < SZ(a) || bi < SZ(b)) {
		if (ai < SZ(a) && (bi >= SZ(b) || a[ai] < b[bi])) { ret += string(1, a[ai++]); continue; }
		if (bi < SZ(b) && (ai >= SZ(a) || b[bi] < a[ai])) { assert(false);  }
		assert(ai < SZ(a) && bi < SZ(b) && a[ai] == b[bi]);
		++ai, ++bi;
	}
	return ret;
}

void decrease(map<string, int>& mp, string s) {
	//printf("decrease %s\n", s.c_str());
	sort(s.begin(), s.end());
	auto it = mp.find(s);
	assert(it != mp.end());
	if (it->second == 1) mp.erase(it); else --it->second;
}

string solve2(int len) {
	if (len == 0) return "";
	vector<string> parts = query(0, len - 1);
	vector<map<string, int>> rem(len + 1); REPSZ(i, parts) { string s = parts[i]; sort(s.begin(), s.end()); rem[SZ(s)][s]++; }
	if (len == 1) { assert(SZ(rem[1]) == 1 && rem[1].begin()->second == 1); return rem[1].begin()->first; }
	vector<string> subparts = query(1, len - 1);
	REPSZ(i, subparts) { string s = subparts[i]; decrease(rem[SZ(s)], s); }
	string lastpart = "";
	string ret(len, '?');
	REP(i, len) {
		assert(SZ(rem[i + 1]) == 1 && rem[i + 1].begin()->second == 1); string curpart = rem[i + 1].begin()->first;
		ret[i] = diff(curpart, lastpart);
		lastpart = curpart;
	}
	return ret;
}

string solve() {
	int halflen = n / 2;
	string firsthalf = solve2(halflen);
	vector<string> parts = query(0, n - 1);
	string ret(n, '?'); REP(i, halflen) ret[i] = firsthalf[i];
	vector<map<string, int>> rem(n + 1); REPSZ(i, parts) { string s = parts[i]; sort(s.begin(), s.end()); rem[SZ(s)][s]++; }
	assert(SZ(rem[n]) == 1 && rem[n].begin()->second == 1); string allpart = rem[n].begin()->first;
	string mid = diffchars(allpart, firsthalf);
	string lastpart = allpart;
	for (int idx = n - 1; idx > halflen; --idx) {
		//printf("idx=%d\n", idx);
		int preflen = idx;
		FORE(offset, 1, n - preflen) {
			string cur = ret.substr(offset, halflen - offset) + mid + ret.substr(idx + 1, offset - 1);
			decrease(rem[preflen], cur);
		}
		assert(SZ(rem[preflen]) == 1 && rem[preflen].begin()->second == 1); string curpart = rem[preflen].begin()->first;
		ret[idx] = diff(lastpart, curpart);
		lastpart = curpart;
		mid = diffchars(mid, string(1, ret[idx]));
	}
	REP(i, n) if (i != halflen) { string s(1, ret[i]); decrease(rem[1], s); }
	assert(SZ(rem[1]) == 1 && rem[1].begin()->second == 1); string midpart = rem[1].begin()->first; assert(SZ(midpart) == 1);
	ret[halflen] = midpart[0];
	return ret;
}

void run() {
	scanf("%d", &n);
	string ans=solve();
	printf("! %s\n", ans.c_str()); fflush(stdout);
}

int main() {
	run();
	return 0;
}
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

const int MAXLINE = 50;
string buff;
int count(const string& s) { int ret = 0; REPE(i, SZ(s) - 4) if (s.substr(i, 4) == "haha") ++ret; return ret; }
string cappref(const string& s) { int len = SZ(s); return s.substr(0, min(len, 3)); }
string capsuff(const string& s) { int len = SZ(s); return s.substr(len - min(len, 3), min(len, 3)); }
struct Var { 
	ll inside; string pref, suff;
	Var() {} 
	Var(ll inside, string pref, string suff) :inside(inside), pref(pref), suff(suff) {}
	Var(const string& s) {
		inside = count(s);
		pref = cappref(s);
		suff = capsuff(s);
	}
};
Var operator+(const Var& a, const Var& b) {
	return Var(a.inside + b.inside + count(a.suff + b.pref), cappref(a.pref + b.pref), capsuff(a.suff + b.suff));
}

int nline;
string line[MAXLINE];

vector<string> split(const string& s) {
	vector<string> ret;
	istringstream iss(s);
	string part;
	while (iss >> part) ret.PB(part);
	return ret;
}

ll solve() {
	map<string, Var> mem;
	Var last;
	REP(i, nline) {
		//printf("line %d: %s\n", i + 1, line[i].c_str());
		vector<string> parts = split(line[i]);
		//REPSZ(j, parts) printf("%s\n", parts[j].c_str());
		if (SZ(parts) == 3 && parts[1] == ":=") {
			last = mem[parts[0]] = Var(parts[2]);
		} else if (SZ(parts) == 5 && parts[1] == "=" && parts[3] == "+") {
			last = mem[parts[0]] = mem[parts[2]] + mem[parts[4]];
		} else {
			assert(false);
		}
	}
	return last.inside;
}

void run() {
	string buff; getline(cin, buff);
	sscanf(buff.c_str(), "%d", &nline);
	REP(i, nline) getline(cin, line[i]);
	printf("%lld\n", solve());
}

int main() {
	string buff; getline(cin, buff);
	int ncase; sscanf(buff.c_str(), "%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}
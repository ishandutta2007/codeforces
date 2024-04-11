#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int N;
set <string> Tokens;

char buf[1010];

string erase_spaces(string e) {
	string res;
	for(char f : e) if(f != ' ' && f != '\t' && f != '\n') res.pb(f);
	return res;
}

vector <string> parse() {
	vector <string> res;
	for(int i=0;buf[i];i++) {
		if(buf[i] == '#') {
			for(int j=i;buf[j];j++) buf[j] = 0;
			break;
		}
	}
	for(char *p=strtok(buf, " "); p; p=strtok(NULL, " ")) {
		res.pb(erase_spaces((string)p));
	}
	return res;
}

int check_norm(char c) {
	if(isdigit(c)) return 1;
	if('a' <= c && c <= 'z') return 1;
	if('A' <= c && c <= 'Z') return 1;
	if(c == '_' || c == '$') return 1;
	return 0;
}

int chk_token(string t, int c = 0) {
	if(c == 0 && Tokens.find(t) != Tokens.end()) return 1;
	int dok = 1;
	for(char c : t) if(!isdigit(c)) dok = 0;
	if(dok) return 2;
	if(szz(t) && !isdigit(t[0])) {
		dok = 1;
		for(char c : t) if(!check_norm(c)) dok = 0;
		if(dok) return 3;
	}
	return 0;
}

vector <string> parse_token(vector<string> &L) {
	vector<string> res;
	for(string e : L) {
		while(szz(e) > 0) {
			string r = e;
			while(szz(r) > 0) {
				if(chk_token(r)) {
					res.pb(r);
					string ne;
					for(int i=szz(r);i<szz(e);i++) ne.pb(e[i]);
					e = ne;
					break;
				}
				else r.pop_back();
			}
		}
	}
	return res;
}

void input_line() {
	fgets(buf, 1010, stdin);
	int L = (int)strlen(buf);
	if(buf[L-1] == 0) buf[--L] = 0;
}

int main() {
	input_line(); N = atoi(buf);
	input_line();
	auto v = parse();
	for(string e : v) Tokens.insert(e);
	int M; input_line(); M = atoi(buf);
	vector <string> X;
	for(int i=0;i<M;i++) {
		input_line();
		auto v = parse();
		for(auto e : v) X.pb(e);
	}
	vector <string> Y = parse_token(X);
	vector <string> m, q;
	rep(i, 26) {
		string rr; rr.pb('a' + i);
		q.pb(rr);
		if(Tokens.find(rr) == Tokens.end()) m.pb(rr);
	}
	rep(i, szz(q)) {
		if(szz(m) > szz(Y)) break;
		string e = q[i];
		rep(j, 26) {
			string f = e; f.pb('a' + j);
			if(Tokens.find(f) == Tokens.end()) m.pb(f);
			q.pb(f);
		}
	}
	int cm = 0;
	map <string, string> Mx;
	for(string &e : Y) {
		if(chk_token(e) == 3) {
			if(Mx.find(e) == Mx.end()) Mx[e] = m[cm++];
			e = Mx[e];
		}
	}
	int L = szz(Y);
	vector <pii> px;
	for(int i=0;i<L;i++) {
		string now = Y[i];
		int r = chk_token(now, 1);
		for(int j=i+1;j<L;j++) {
			int ok = 0;
			rep(k, szz(Y[j])) {
				now.pb(Y[j][k]);
				if(r == 2 && !isdigit(Y[j][k])) r = 0;
				if(r == 3 && !check_norm(Y[j][k])) r = 0;
				if(r != 0 || Tokens.find(now) != Tokens.end()) {
					ok = 1; break;
				}
			}
			
			if(ok) {
				px.pb(pii(i+1, j));
			}
		}
	}
	sort(all(px), [](pii a, pii b) { return a.Se < b.Se; });
	int cc[100010] = {};
	for(pii e : px) {
		int exi = 0;
		for(int i=e.Fi;i<=e.Se;i++) exi |= cc[i];
		if(exi) continue;
		cc[e.Se] = 1;
	}
	rep(i, L) {
		printf("%s", Y[i].c_str());
		if(cc[i+1]) printf(" ");
		if(i == L-1) puts("");
	}
	return 0;
}
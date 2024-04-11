#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXLINELEN = 100000;
const char BIBSTART[] = "\\begin{thebibliography}{99}";
const char BIBEND[] = "\\end{thebibliography}";

char s[MAXLINELEN + 3]; int slen;

vector<string> references;
vector<string> descorder;
map<string, string> descriptions;

void findreferences() {
	int at = 0;
	while (at < slen) {
		char c = s[at++];
		if (c != '{') continue;
		int from = at;
		while (at < slen) {
			c = s[at++];
			if (c != '}') continue; else { --at; break; }
		}
		int to = at;
		string ref = string(s + from, s + to);
		//printf("found '%s'\n", ref.c_str());
		references.PB(ref);
	}
}
void parsebibitem() {
	int at = 0;
	while (at < slen) {
		char c = s[at++];
		if (c != '{') continue;
		int from = at;
		while (at < slen) {
			char c = s[at++];
			if (c != '}') continue; else { --at; break; }
		}
		int to = at;
		string ref = string(s + from, s + to);
		string desc = string(s + to + 1, s + slen);
		//printf("found '%s' = '%s'\n", ref.c_str(), desc.c_str());
		assert(!descriptions.count(ref));
		descorder.PB(ref);
		descriptions[ref] = desc;
		break;
	}
}

void run() {
	bool inbib = false; references.clear(); descorder.clear(); descriptions.clear();
	while(true) {
		if (fgets(s, sizeof(s), stdin) == NULL) break; slen = strlen(s); while (s[slen - 1] == '\n' || s[slen - 1] == '\r') s[--slen] = '\0';
		if (strcmp(s, BIBSTART) == 0) {
			inbib = true;
		} else if (strcmp(s, BIBEND) == 0) {
			inbib = false;
		} else {
			//printf("s='%s' (%d) (%s)\n", s, slen, inbib ? "BIB" : "TEXT");
			if (!inbib) findreferences(); else parsebibitem();
		}
	}
	if (references == descorder) { printf("Correct\n"); return; }
	printf("Incorrect\n");
	printf("%s\n", BIBSTART);
	REPSZ(i, references) {
		string ref = references[i];
		auto it = descriptions.find(ref);
		assert(it != descriptions.end());
		printf("\\bibitem{%s}%s\n", ref.c_str(), it->second.c_str());
	}
	printf("%s\n", BIBEND);
}


int main() {
	run();
	return 0;
}
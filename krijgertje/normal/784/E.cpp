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
#include <functional>
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

const int MAXOP = 4 + 4 + 2 + 1;
typedef struct Op { int kind, a, b; } Op;

Op op[MAXOP];
int ans[MAXOP];

int p[4];
void init() {
	op[0].kind = p[0], op[1].kind = p[0], op[2].kind = p[0], op[3].kind = p[0];
	op[4].kind = p[1], op[4].a = 0, op[4].b = 1;
	op[5].kind = p[2], op[5].a = 2, op[5].b = 3;
	op[6].kind = p[3], op[6].a = 1, op[6].b = 2;
	op[7].kind = p[1], op[7].a = 0, op[7].b = 3;
	op[8].kind = p[3], op[8].a = 4, op[8].b = 5;
	op[9].kind = p[2], op[9].a = 6, op[9].b = 7;
	op[10].kind = p[1], op[10].a = 8, op[10].b = 9;
}



int calc() {
	REP(i, MAXOP) {
		switch (op[i].kind) {
			case 0: ans[i] = op[i].a; break;
			case 1: ans[i] = ans[op[i].a] | ans[op[i].b]; break;
			case 2: ans[i] = ans[op[i].a] ^ ans[op[i].b]; break;
			case 3: ans[i] = ans[op[i].a] & ans[op[i].b]; break;
			default: assert(false);
		}
	}
	//REP(i, MAXOP) printf("%d", ans[i]); puts("");
	return ans[MAXOP - 1];
}


void run() {
	REP(i, 4) scanf("%d", &op[i].a);
	REP(i, 4) p[i] = i;
	/*do {
		init();
		REP(i, 4) printf("%d%c", p[i], i == 3 ? ':' : ' '); printf(" %d\n", calc());
	} while (next_permutation(p + 1, p + 4));*/
	swap(p[1], p[2]);
	init();
	printf("%d\n", calc());
}

int main() {
	run();
	return 0;
}
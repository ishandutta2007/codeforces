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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

struct Card { int rank; char suit; };

Card card[3];

int solve() {
	int ret=INT_MAX;
	FORE(rank,1,9) REP(suitidx,3) {
		char suit="msp"[suitidx];
		{ // triplet
			int cur=3; REP(i,3) if(card[i].rank==rank&&card[i].suit==suit) --cur;  ret=min(ret,cur);
		}
		if(rank+2<=9) { // series
			int cur=3; REP(i,3) { bool found=false; REP(j,3) if(card[j].rank==rank+i&&card[j].suit==suit) found=true; if(found) --cur; } ret=min(ret,cur);
		}
	}
	return ret;
}

void run() {
	REP(i,3) { char s[3]; scanf("%s",s); card[i].rank=s[0]-'0',card[i].suit=s[1]; }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
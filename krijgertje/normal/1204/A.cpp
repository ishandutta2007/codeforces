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

const int MAXLEN=100;

char s[MAXLEN+1]; int slen;

int solve() {
	bool isp2=true; FOR(i,1,slen) if(s[i]!='0') isp2=false;
	int ret=0;
	REP(i,slen) if(i%2==0) {
		int idx=slen-i-1;
		if(idx>0||idx==0&&!isp2) ++ret;
	}
	return ret;
}

void run() {
	scanf("%s",s); slen=strlen(s);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
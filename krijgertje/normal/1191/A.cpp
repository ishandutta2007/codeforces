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

int have;

char calc(int x) { return "DACB"[x%4]; }

pair<int,char> solve() {
	pair<int,char> ret=MP(0,calc(have));
	FORE(i,1,2) { char c=calc(have+i); if(c<ret.second) ret=MP(i,c); }
	return ret;
}

void run() {
	scanf("%d",&have);
	pair<int,char> ans=solve();
	printf("%d %c",ans.first,ans.second);
}

int main() {
	run();
	return 0;
}
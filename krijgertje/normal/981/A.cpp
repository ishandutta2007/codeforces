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

const int MAXN=50;

char s[MAXN+1]; int n;

int solve() {
	bool allsame=true; FOR(i,1,n) if(s[i]!=s[0]) allsame=false; if(allsame) return 0;
	bool ispal=true; REP(i,n) if(s[i]!=s[n-i-1]) ispal=false; if(!ispal) return n;
	bool ispal2=true; REP(i,n-1) if(s[i]!=s[n-i-2]) ispal2=false; assert(!ispal2);
	return n-1;
}

void run() {
	scanf("%s",s); n=strlen(s);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
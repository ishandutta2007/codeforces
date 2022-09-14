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
typedef long double ld;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int n;
char s[199999];

int have[26];

void run() {
	scanf("%d%s",&n,s);
	REP(i,26) have[i]=0;
	int ret=0;
	REP(i,2*n-2) {
		if(islower(s[i])) ++have[s[i]-'a'];
		if(isupper(s[i])) { int x=s[i]-'A'; if(have[x]==0) ++ret; else --have[x]; }
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
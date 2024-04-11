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

const int MAXN=200;

int n; char s[MAXN+1];

void run() {
	scanf("%d%s",&n,s);
	int ret=0;
	REP(i,n) {
		int x=0,y=0;
		FOR(j,i,n) {
			if(s[j]=='L') --x; else if(s[j]=='R') ++x; else if(s[j]=='U') ++y; else if(s[j]=='D') --y; else assert(false);
			if(x==0&&y==0) ++ret;
		}
	}
	printf("%d\n",ret);
}
int main() {
	run();
	return 0;
}
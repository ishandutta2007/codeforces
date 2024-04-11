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

const int MAXN=200000;

int n;
char s[MAXN+1];

void run() {
	scanf("%d%s",&n,s);
	int ret=0;
	for(int at=0,to=at;at<n;at=to) {
		int hor=0,ver=0;
		while(to<n) {
			if(s[to]=='L') if(hor==+1) break; else hor=-1;
			if(s[to]=='R') if(hor==-1) break; else hor=+1;
			if(s[to]=='U') if(ver==+1) break; else ver=-1;
			if(s[to]=='D') if(ver==-1) break; else ver=+1;
			++to;
		}
		++ret;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
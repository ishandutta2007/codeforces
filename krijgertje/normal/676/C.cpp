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

const int MAXLEN=100000;

int n,k;
char s[MAXLEN+1];

int calc(char c) {
	int cnt=0,at=0,to=0,ret=0;
	while(at<n) {
		while(to<n&&(s[to]==c||cnt<k)) { if(s[to]!=c) ++cnt; ++to; }
		if(to-at>ret) ret=to-at;
		if(s[at]!=c) --cnt; ++at;
	}
	return ret;
}

void run() {
	scanf("%d%d%s",&n,&k,s);
	int ret=max(calc('a'),calc('b'));
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
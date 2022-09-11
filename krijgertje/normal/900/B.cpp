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

const int MAXB=100000;

int a,b,want;
bool been[MAXB];

void run() {
	scanf("%d%d%d",&a,&b,&want);
	REP(i,b) been[i]=false;
	for(int ret=1;;++ret) {
		if(been[a]) { printf("-1\n"); return; } else been[a]=true;
		int cur=10*a/b; if(cur==want) { printf("%d\n",ret); return; }
		a=10*a%b;
	}
}

int main() {
	run();
	return 0;
}
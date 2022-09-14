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


int calc(int s,int n) {
	n%=6;
	if(n>=1&&s!=2) s=1-s;
	if(n>=2&&s!=0) s=3-s;
	if(n>=3&&s!=2) s=1-s;
	if(n>=4&&s!=0) s=3-s;
	if(n>=5&&s!=2) s=1-s;
	return s;
}

int n,t;

void run() {
	scanf("%d%d",&n,&t);
	REP(s,3) if(calc(s,n)==t) { printf("%d\n",s); return; }
	assert(false);
}

int main() {
	run();
	return 0;
}
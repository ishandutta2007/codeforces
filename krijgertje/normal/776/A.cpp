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

const int MAXLEN=10;
const int MAXN=1000;

int n;
char init[2][MAXLEN+1];
char murder[MAXN][MAXLEN+1],added[MAXN][MAXLEN+1];

void run() {
	scanf("%s%s%d",init[0],init[1],&n); REP(i,n) scanf("%s%s",murder[i],added[i]);
	char *a=init[0],*b=init[1];
	REP(i,n) {
		printf("%s %s\n",a,b);
		if(strcmp(a,murder[i])==0) a=added[i]; else if(strcmp(b,murder[i])==0) b=added[i]; else assert(false);
	}
	printf("%s %s\n",a,b);
}

int main() {
	run();
	return 0;
}
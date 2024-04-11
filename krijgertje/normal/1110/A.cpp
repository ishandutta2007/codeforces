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

const int MAXDIGIT=100000;

int base,ndigit;
int d[MAXDIGIT];

int solve() {
	int sum=0;
	int cur=1; for(int i=ndigit-1;i>=0;--i) { sum=(sum+cur*d[i])%2; cur=(cur*base)%2; }
	return sum;
}

void run() {
	scanf("%d%d",&base,&ndigit);
	REP(i,ndigit) scanf("%d",&d[i]);
	printf("%s\n",solve()==0?"even":"odd");
}

int main() {
	run();
	return 0;
}
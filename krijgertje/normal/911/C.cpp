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

int a[3];

bool solve() {
	if(a[0]==1) return true;
	if(a[0]==2&&a[1]==2) return true;
	if(a[0]==2&&a[1]==4&&a[2]==4) return true;
	if(a[0]==3&&a[1]==3&&a[2]==3) return true;
	return false;
}

void run() {
	REP(i,3) scanf("%d",&a[i]); sort(a,a+3);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}
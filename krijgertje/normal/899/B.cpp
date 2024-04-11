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

const int MAXN=24;
const int DAYS[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};


int n;
int a[MAXN];

bool solve() {
	REP(smon,12) {
		REP(leapyear,3) {
			bool ok=true;
			REP(i,n) {
				int year=(smon+i)/12,mon=(smon+i)%12;
				if(a[i]!=DAYS[year==leapyear?1:0][mon]) ok=false;
			}
			if(ok) return true;
		}
	}
	return false;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	printf("%s\n",solve()?"Yes":"No");
}

int main() {
	run();
	return 0;
}
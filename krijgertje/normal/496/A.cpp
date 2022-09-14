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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n;
int a[100];


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	int cur=0; REP(i,n-1) if(a[i+1]-a[i]>cur) cur=a[i+1]-a[i];
	int ret=INT_MAX;
	FORE(i,1,n-2) {
		int now=max(cur,a[i+1]-a[i-1]); if(now<ret) ret=now;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
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

int m[5],w[5],x[5];
int nok,nwrong;

void run() {
	REP(i,5) scanf("%d",&m[i]);
	REP(i,5) scanf("%d",&w[i]);
	REP(i,5) x[i]=500*(i+1);
	scanf("%d%d",&nok,&nwrong);
	int ret=25000*nok-12500*nwrong;
	REP(i,5) ret+=max(75*x[i],(250-m[i])*x[i]-12500*w[i]);
	ret/=250;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
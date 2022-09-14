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

const int MAXN=1000;

int sx,sy;
int n;
int x[MAXN],y[MAXN],z[MAXN];


void run() {
	scanf("%d%d",&sx,&sy);
	scanf("%d",&n);
	REP(i,n) scanf("%d%d%d",&x[i],&y[i],&z[i]);
	double ret=0;
	REP(i,n) {
		int dx=sx-x[i],dy=sy-y[i]; double cur=sqrt(1.0*dx*dx+dy*dy)/z[i];
		if(i==0||cur<ret) ret=cur;
	}
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}
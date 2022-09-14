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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

const int MOD=1000000007;

// f(i)=f(i-1)-f(i-2)
// x,y,y-x,-x,-y,-y+x,x,y
int CX[]={+1, 0,-1,-1, 0,+1};
int CY[]={ 0,+1,+1, 0,-1,-1};

int x,y,n;

void run() {
	scanf("%d%d%d",&x,&y,&n);
	n=(n-1)%6;
	int ret=x*CX[n]+y*CY[n]; ret=(ret%MOD+MOD)%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
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

int n;
int need[MAXN];
bool done[MAXN];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&need[i]);

	int have=0,at=0,dir=+1,ret=0;
	while(have<n) {
		if(!done[at]&&have>=need[at]) { ++have,done[at]=true; continue; }
		if(at+dir<0||at+dir>=n) dir=-dir,++ret;
		at+=dir;
	}
	printf("%d\n",ret);

}


int main() {
	run();
	return 0;
}
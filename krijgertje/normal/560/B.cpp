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

int h,w;
int x[2],y[2];

void run() {
	scanf("%d%d",&h,&w);
	REP(i,2) scanf("%d%d",&x[i],&y[i]);
	bool ok=false;
	REP(a,2) {
		REP(b,2) {
			//printf("(%d,%d)(%d,%d)\n",x[0],y[0],x[1],y[1]);
			if(x[0]+x[1]<=h&&y[0]<=w&&y[1]<=w) ok=true;
			if(y[0]+y[1]<=w&&x[0]<=h&&x[1]<=h) ok=true;
			swap(x[1],y[1]);
		}
		swap(x[0],y[0]);
	}
	printf("%s\n",ok?"YES":"NO");
}

int main() {
	run();
	return 0;
}
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

const int MOD=24*60;
int x,h,m;

bool ok(int t) {
	int hh=t/60,mm=t%60;
	return mm%10==7||hh%10==7;
}

void run() {
	scanf("%d%d%d",&x,&h,&m);
	//printf("%d %d %d\n",x,h,m);
	int t=h*60+m;
	for(int ret=0;;++ret) {
		if(ok(t)) { printf("%d\n",ret); break; }
		t=(t+MOD-x)%MOD;
	}
}

int main() {
	run();
	return 0;
}
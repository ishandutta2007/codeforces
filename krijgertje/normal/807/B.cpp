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

int pos,have,need;

bool ok(int s) {
	int i=(s/50)%475;
	REP(rep,25) { i=(i*96+42)%475; if(26+i==pos) return true; }
	return false;
}

void run() {
	scanf("%d%d%d",&pos,&have,&need);
	int cur=have;
	while(cur<need) cur+=100; while(cur-50>=need) cur-=50; 
	while(!ok(cur)) cur+=50;
	int gain=cur-have;
	printf("%d\n",gain<0?0:(gain+50)/100);
}

int main() {
	run();
	return 0;
}
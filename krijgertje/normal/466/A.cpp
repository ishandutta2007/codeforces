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

int need,specialcnt,cost,specialcost;

void run() {
	scanf("%d%d%d%d",&need,&specialcnt,&cost,&specialcost);
	int ret=need*cost;
	for(int i=1;;++i) {
		int cur=i*specialcost+max(0,need-i*specialcnt)*cost;
		if(cur<ret) ret=cur;
		if(i*specialcnt>=need) break;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
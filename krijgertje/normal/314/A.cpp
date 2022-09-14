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

int n,okval;
int a[200000];

void run(int casenr) {
	scanf("%d%d",&n,&okval);
	REP(i,n) scanf("%d",&a[i]);
	int left=n,pos=1;
	ll sum=0;
	REP(i,n) {
		ll val=sum-(ll)(left-pos)*(pos-1)*a[i];
		if(val<okval) {
			printf("%d\n",i+1);
			--left;
		} else {
			sum+=a[i]*(pos-1);
			++pos;
		}
	}
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
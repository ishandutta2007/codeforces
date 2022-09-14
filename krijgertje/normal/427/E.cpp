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

const int MOD=1000000007;


int n,cap;
int x[1000000];

void run() {
	scanf("%d%d",&n,&cap);
	REP(i,n) scanf("%d",&x[i]);
	ll ret=0;
	int a=0,b=n-1;
	while(b-a+1>2*cap) {
		ret+=2LL*(x[b]-x[a]);
		a+=cap; b-=cap;
	}
	ret+=2LL*(x[b]-x[a]);
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}
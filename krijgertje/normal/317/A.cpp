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

void run(int casenr) {
	ll x,y,m; cin>>x>>y>>m;
	if(x>=m||y>=m) { printf("0\n"); return; }
	if(x<=0&&y<=0) { printf("-1\n"); return; }
	if(x>y) swap(x,y);
	ll ret=0;
	if(x<0) {
		ll times=(min(0LL,m)-x+y-1)/y;
		ret+=times; x+=times*y;
	}
	while(x<m&&y<m) {
		if(x>y) swap(x,y);
		x+=y; ++ret;
	}
	cout<<ret<<endl;
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
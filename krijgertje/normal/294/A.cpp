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
	int n; scanf("%d",&n);
	vector<int> a(n); REP(i,n) scanf("%d",&a[i]);
	int m; scanf("%d",&m);
	REP(i,m) {
		int x,y; scanf("%d%d",&x,&y); --x,--y;
		int p=y,q=a[x]-y-1; 
		a[x]=0; if(x-1>=0) a[x-1]+=p; if(x+1<n) a[x+1]+=q;
	}
	REP(i,n) printf("%d\n",a[i]);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
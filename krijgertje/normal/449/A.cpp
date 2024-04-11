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

int h,w,k;

void run() {
	scanf("%d%d%d",&h,&w,&k);
	ll ret=-1;
	if(k<h) ret=max(ret,(ll)h/(k+1)*w);
	if(k<w) ret=max(ret,(ll)w/(k+1)*h);
	if(k>=h-1&&k-(h-1)<w) ret=max(ret,(ll)w/(k-(h-1)+1));
	if(k>=w-1&&k-(w-1)<h) ret=max(ret,(ll)h/(k-(w-1)+1));
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}
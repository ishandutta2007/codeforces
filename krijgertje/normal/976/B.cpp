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

int h,w; ll pos;

pair<int,int> solve(ll k) {
	if(k<h) return MP((int)k,0); else k-=h;
	int t=k/(2*(w-1)); k%=2*(w-1);
	if(k<w-1) return MP(h-1-2*t,(int)(1+k)); else k-=w-1;
	return MP(h-1-2*t-1,(int)(w-1-k));
}

void run() {
	scanf("%d%d%lld",&h,&w,&pos);
	pair<int,int> ans=solve(pos);
	printf("%d %d\n",ans.first+1,ans.second+1);
}

int main() {
	run();
	return 0;
}
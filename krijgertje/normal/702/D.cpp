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

ll dist; int step,tcar,tfoot,trepair;

void run() {
	scanf("%lld%d%d%d%d",&dist,&step,&tcar,&tfoot,&trepair);

	// x repairs -> x*trepair+dist*tcar+max(0,dist-(x+1)*step)*(tfoot-tcar)
	ll x=(dist-1)/step;
	ll a=x*trepair+dist*tcar+max(0LL,dist-(x+1)*step)*(tfoot-tcar);
	ll b=max(0LL,x-1)*trepair+dist*tcar+max(0LL,dist-(max(0LL,x-1)+1)*step)*(tfoot-tcar);
	ll c=dist*tcar+max(0LL,dist-step)*(tfoot-tcar);
	//printf("\t%lld %lld %lld\n",a,b,c);
	printf("%lld\n",min(a,min(b,c)));
}

int main() {
	run();
	return 0;
}
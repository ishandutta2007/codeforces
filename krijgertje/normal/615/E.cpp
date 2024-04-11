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

ll n;

void run() {
	scanf("%I64d",&n);
	int z=((int)sqrt(1+3*n)-1)/3;
	int x=+z,y=-2*z; n-=(ll)(2+3*z)*z;
	{ int cur=(int)min((ll)z+1,n); n-=cur; x+=  cur,y+=2*cur; }
	{ int cur=(int)min((ll)z+0,n); n-=cur; x-=  cur,y+=2*cur; }
	{ int cur=(int)min((ll)z+1,n); n-=cur; x-=2*cur; }
	{ int cur=(int)min((ll)z+1,n); n-=cur; x-=  cur,y-=2*cur; }
	{ int cur=(int)min((ll)z+1,n); n-=cur; x+=  cur,y-=2*cur; }
	{ int cur=(int)min((ll)z+1,n); n-=cur; x+=2*cur; }
	printf("%d %d\n",x,y);
}

int main() {
	run();
	return 0;
}
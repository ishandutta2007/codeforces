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
#include <cstring>
#include <list>  
#include <cassert>
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

int sz,nq;

ll solve(int x,int y) {
	ll ret=0;
	if((x+y)%2==0) {
		int a=(sz+1)/2;
		int b=sz/2;
		ret+=(ll)(a+b)*(x/2);
		//printf("ret=%lld a=%d x=%d y=%d\n",ret,a,x,y);
		if(x%2==0) ret+=(y/2); else ret+=a+(y/2);
	} else {
		ret+=((ll)sz*sz+1)/2;
		int a=sz/2;
		int b=(sz+1)/2;
		ret+=(ll)(a+b)*(x/2);
		if(x%2==0) ret+=(y/2); else ret+=a+(y/2);
	}
	return ret;
}

void run() {
	scanf("%d%d",&sz,&nq);
	REP(i,nq) {
		int x,y; scanf("%d%d",&x,&y); --x,--y;
		printf("%lld\n",solve(x,y)+1);
	}
}

int main() {
	run();
	return 0;
}
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

const int MAXOP=100000;

int len,nop;
int x[MAXOP],d[MAXOP];

void run() {
	scanf("%d%d",&len,&nop);
	REP(i,nop) scanf("%d%d",&x[i],&d[i]);

	ll ret=0;
	REP(i,nop) {
		ret+=(ll)len*x[i];
		if(d[i]>=0) {
			ret+=(ll)d[i]*(len-1)*len/2;
		} else {
			int idx=len/2,a=idx+1,b=len-idx;
			ret+=(ll)d[i]*(a-1)*a/2+(ll)d[i]*(b-1)*b/2;
		}
	}
	printf("%.15lf\n",1.0*ret/len);
}

int main() {
	run();
	return 0;
}
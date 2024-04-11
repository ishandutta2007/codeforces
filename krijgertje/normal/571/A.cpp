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

ll ways(int n) {
	//printf("\t%d\n",n);
	if(n<0) return 0;
	return (ll)(n+2)*(n+1)/2;
}

int x[3],have;
ll calc(int have,int a,int b,int c) {
	if(a<0||b<0||c<0||have>a+b+c) return 0;
	ll ret=ways(have)-ways(have-a-1)-ways(have-b-1)-ways(have-c-1)+ways(have-a-b-2)+ways(have-a-c-2)+ways(have-b-c-2)-ways(have-a-b-c-3);
	//printf("%d [%d,%d,%d] = %lld\n",have,a,b,c,ret);
	return ret;
}

void run() {
	scanf("%d%d%d%d",&x[0],&x[1],&x[2],&have);

	ll ret=0;
	REP(i,3) REPE(j,have) {
		int me=x[i]+j;
		int lim[3],nlim=0;
		REP(k,i) lim[nlim++]=me-x[k]-1;
		FOR(k,i+1,3) lim[nlim++]=me-x[k];
		lim[nlim++]=x[0]+x[1]+x[2]-2*x[i]+have-2*j-1;
		ret+=calc(have-j,lim[0],lim[1],lim[2]);
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}
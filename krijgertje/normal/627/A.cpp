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

ll mem[60][3][2];

ll s,x;
ll calc(int shift,int nzero,int carry) {
	ll &ret=mem[shift][nzero][carry];
	if(ret!=-1) return ret;
	//printf("calc(%d,%d,%d) [%lld,%lld]\n",shift,nzero,carry,(s>>shift)-carry,x>>shift);
	if((s>>shift)==carry&&(x>>shift)==0) return ret=(nzero==0?1:0);
	int xx=(x>>shift)&1,ss=((s>>shift)-carry)&1;
	if(xx!=ss) return ret=0;
	if(xx==1) return ret=calc(shift+1,min(1,nzero),carry)+calc(shift+1,max(0,nzero-1),carry);
	return ret=calc(shift+1,nzero,0)+((s>>shift)>=2?calc(shift+1,0,1):0);
}

void run() {
	memset(mem,-1,sizeof(mem));
	scanf("%I64d%I64d",&s,&x);
	printf("%I64d\n",calc(0,2,0));
}

int main() {
	run();
	return 0;
}
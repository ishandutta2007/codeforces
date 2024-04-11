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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MOD=1000000007;
const int LIM=100000;

int nq,sz;
int ways[LIM+1];
int cum[LIM+2];

void run() {
	scanf("%d%d",&nq,&sz);
	memset(ways,0,sizeof(ways));
	ways[0]=1;
	REPE(i,LIM) if(ways[i]>0) {
		if(i+1<=LIM) { ways[i+1]+=ways[i]; if(ways[i+1]>=MOD) ways[i+1]-=MOD; }
		if(i+sz<=LIM) { ways[i+sz]+=ways[i]; if(ways[i+sz]>=MOD) ways[i+sz]-=MOD; }
	}
	//REPE(i,20) printf("%d: %d\n",i,ways[i]);
	cum[0]=0; REPE(i,LIM) { cum[i+1]=cum[i]+ways[i]; if(cum[i+1]>=MOD) cum[i+1]-=MOD; }
	REP(qi,nq) {
		int a,b; scanf("%d%d",&a,&b);
		int ret=cum[b+1]-cum[a]; if(ret<0) ret+=MOD;
		printf("%d\n",ret);
	}
}

int main() {
	run();
	return 0;
}
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

int n,d;
int a[100],x[100],y[100],dp[100];

void run(int casenr) {
	int n,d; scanf("%d%d",&n,&d);
	a[0]=0; FOR(i,1,n-1) scanf("%d",&a[i]);
	REP(i,n) scanf("%d%d",&x[i],&y[i]);
	REP(i,n-1) dp[i]=-1; dp[n-1]=0;
	while(dp[0]==-1) {
		int from=-1,to=-1,cur=-1;
		REP(i,n) if(dp[i]==-1) REP(j,n) if(dp[j]!=-1) {
			int now=max(0,d*abs(x[i]-x[j])+d*abs(y[i]-y[j])+dp[j]-a[i]);
			if(cur==-1||now<cur) { cur=now; from=i; to=j; }
		}
		dp[from]=cur;
//		printf("%d -> %d = %d\n",from,to,cur);
	}
	printf("%d\n",dp[0]);
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
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

int n,k;
int x[200000];

ll best[200000];
int bestpos[200000];

void run(int casenr) {
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d",&x[i]);

	memset(bestpos,-1,sizeof(bestpos));
	{
		ll sum=0; REP(i,k) sum+=x[n-i-1]; best[n-k]=sum; bestpos[n-k]=n-k;
		for(int i=n-k-1;i>=0;--i) { sum+=x[i]-x[i+k]; best[i]=best[i+1]; bestpos[i]=bestpos[i+1]; if(sum>best[i]) best[i]=sum; if(sum==best[i]) bestpos[i]=i; }
	}
	ll totbest; int totbestpos1=-1,totbestpos2=-1;
	{
		ll sum=0; REP(i,k) sum+=x[i];
		totbest=sum+best[k]; totbestpos1=0; totbestpos2=bestpos[k];
		FORE(i,1,n-2*k) { sum+=x[i+k-1]-x[i-1]; if(sum+best[i+k]>totbest) { totbest=sum+best[i+k]; totbestpos1=i; totbestpos2=bestpos[i+k]; } }
	}
	printf("%d %d\n",totbestpos1+1,totbestpos2+1);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
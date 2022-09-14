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

const int MOD=1000000007;

int n,init,blocked,nsteps;

int ways[5000];
int cumways[5001];

void run() {
	scanf("%d%d%d%d",&n,&init,&blocked,&nsteps); --init,--blocked;

	REP(i,n) ways[i]=i==init?1:0;
	REP(step,nsteps) {
		cumways[0]=0; REP(i,n) { cumways[i+1]=cumways[i]+ways[i]; if(cumways[i+1]>=MOD) cumways[i+1]-=MOD; }
		REP(i,n) {
			ways[i]=0;
			if(i<blocked) {
				ways[i]+=cumways[i]-cumways[0]; // 0<=j<=i-1
				ways[i]+=cumways[(blocked+i-1)/2+1]-cumways[i+1]; // i+1<=j<=(blocked+i-1)/2
			}
			if(i>blocked) {
				//if(step==0) printf("%d: %d..%d / %d..%d\n",i,(i+blocked+2)/2,i-1,i+1,n-1);
				ways[i]+=cumways[n]-cumways[i+1]; // i+1<=j<=n-1
				ways[i]+=cumways[i]-cumways[(i+blocked+2)/2]; // (i+blocked+2)/2<=j<=i-1
			}
			while(ways[i]<0) ways[i]+=MOD; while(ways[i]>=MOD) ways[i]-=MOD;
		}
		//REP(i,n) if(ways[i]!=0) printf("%d:%d ",i,ways[i]); puts("");
	}
	int ret=0; REP(i,n) { ret+=ways[i]; if(ret>=MOD) ret-=MOD; }
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
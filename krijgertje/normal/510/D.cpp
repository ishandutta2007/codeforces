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

int n;
int x[300];
int cost[300];

int p[10],np;

int have[300];
int dp[1<<10];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]); REP(i,n) scanf("%d",&cost[i]);
	int ret=INT_MAX;
	REP(i,n) {
		{
			int y=x[i]; np=0;
			for(int j=2;(ll)j*j<=y;++j) if(y%j==0) { p[np++]=j; while(y%j==0) y/=j; }
			if(y!=1) p[np++]=y;
		}
		//printf("%d:",x[i]); REP(j,np) printf(" %d",p[j]); puts("");
		REP(k,1<<np) dp[k]=INT_MAX; dp[0]=cost[i];
		REP(j,n) have[j]=0;
		FOR(j,i+1,n) REP(l,np) if(x[j]%p[l]!=0) have[j]|=1<<l;
		FOR(j,i+1,n) REP(k,1<<np) if(dp[k]!=INT_MAX) {
			int nk=k|have[j];
			if(dp[k]+cost[j]<dp[nk]) dp[nk]=dp[k]+cost[j];
		}
		int cur=dp[(1<<np)-1];
		if(cur<ret) ret=cur;
	}
	printf("%d\n",ret==INT_MAX?-1:ret);
}

int main() {
	run();
	return 0;
}
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

int n,slen;
char s[50][21];

ll unsure[1<<20];
int nsure[1<<20];
double dp[1<<20];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%s",s[i]); slen=strlen(s[0]);

	double ret=0;

	memset(unsure,0,sizeof(unsure));
	REP(i,n) FOR(j,i+1,n) {
		int mask=0; REP(k,slen) if(s[i][k]==s[j][k]) mask|=1<<k;
		unsure[mask]|=(1LL<<i)|(1LL<<j);
	}
	for(int i=(1<<slen)-1;i>=0;--i) if(unsure[i]) REP(j,slen) if(i&(1<<j)) unsure[i-(1<<j)]|=unsure[i];
	memset(nsure,0,sizeof(nsure));
	REP(i,1<<slen) REP(j,n) if((unsure[i]&(1LL<<j))==0) ++nsure[i];

	for(int j=(1<<slen)-1;j>=0;--j) {
		if(nsure[j]==n) { dp[j]=0; continue; }
		double sum=0; int cnt=0;
		REP(k,slen) if((j&(1<<k))==0) {
			int now=nsure[j+(1<<k)]-nsure[j];
			cnt+=n-nsure[j]; sum+=now+(n-nsure[j]-now)*(1+dp[j+(1<<k)]);
		}
		dp[j]=sum/cnt;
	}

	printf("%.9lf\n",dp[0]);
}

int main() {
	run();
	return 0;
}
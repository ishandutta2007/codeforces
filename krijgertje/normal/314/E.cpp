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

int n;
char s[100001];
unsigned int dp[100001];

void run(int casenr) {
	scanf("%d %s",&n,s);
//	REP(i,n) s[i]='?';
	int nquestion=0; REP(i,n) if(s[i]=='?') ++nquestion; //if(nquestion==n&&n==100000) { printf("2313197120\n"); return; }
	if(n%2==1||2*nquestion<n) { printf("0\n"); return; }


	memset(dp,0,sizeof(dp)); dp[0]=1;
	REP(i,n) {
		int minclose=max(0,i+1-n/2),maxclose=(i+1)/2;
//		printf("%d..%d\n",minclose,maxclose);
		if(s[i]=='?') {
			for(int j=maxclose;j>=minclose&&j>=1;--j) dp[j]+=dp[j-1];
		}
	}

	unsigned int ret=dp[n/2]; REP(i,nquestion-n/2) ret*=25;
	cout<<ret<<endl;
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
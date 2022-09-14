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

const int MAXLEN=100000;

int slen,sz; char S[MAXLEN+1];

ll dp[MAXLEN];
ll dpsup[MAXLEN];
ll dpsub[MAXLEN];
ll dpboth[MAXLEN];

void run() {
	scanf("%d%d%s",&slen,&sz,S);
	//srand(time(NULL)); slen=MAXLEN; sz=26; REP(i,slen) S[i]='a'+rand()%sz;


	dp[slen-1]=sz-1;
	if(slen>=2) {
		dpsup[slen-1]=sz;
		dpsub[slen-1]=S[slen-2]==S[slen-1]?1:2;
		dpboth[slen-1]=S[slen-2]==S[slen-1]?1:2;
	}
	for(int i=slen-2;i>=0;--i) {
		//printf("%d: %d %d %d %d\n",i+1,dp[i+1],dpsup[i+1],dpsub[i+1],dpboth[i+1]);
		//dp[i]=ways to take T[i..] so that LCS(S[i..],T[i..])==slen-i-1
		//dp[i]+= ways(S[i]==T[i] && LCS(S[i+1..],T[i+1..])==slen-i-2)
		//dp[i]+= ways(S[i]!=T[i] && S[i+1..] is subsequence of T[i..]) -> ways(S[i]!=T[i] && S[i+1]==T[i] && S[i+2..] is subsequence of T[i+1..])
		//dp[i]+= ways(S[i]!=T[i] && T[i+1..] is subsequence of S[i..])
		//dp[i]-= ways(S[i]!=T[i] && T[i+1..] is subsequence of S[i..] and S[i+1..] is subsequence of T[i..]) -> ways(S[i]!=T[i] && S[i+1]==T[i] && T[i+1..] is subsequence of S[i..] and S[i+2..] is subsequence of T[i+1..])
		dp[i]+=dp[i+1];
		if(S[i+1]!=S[i]) dp[i]+=dpsup[i+1];
		dp[i]+=(sz-1)*dpsub[i+1];
		if(S[i+1]!=S[i]) dp[i]-=dpboth[i+1];
		if(i==0) continue;

		//dpsup[i]=ways to take T[i..] so that S[i+1..] is a subsequence of it
		dpsup[i]+=dpsup[i+1];
		dpsup[i]+=(sz-1);

		//dpsub[i]=ways to take T[i..] so that it is a subsequence of S[i-1..]
		dpsub[i]+=dpsub[i+1];
		if(S[i-1]!=S[i]) dpsub[i]++;

		//dpboth[i]=ways to take T[i..] so that it is a subsequence of S[i-1..] and S[i+1] is a subsequence of it
		if(S[i-1]==S[i+1]) dpboth[i]+=dpboth[i+1];
		if(S[i-1]!=S[i+1]) dpboth[i]++;
		if(S[i-1]!=S[i]) dpboth[i]++;
	}
	printf("%I64d\n",dp[0]);
}

int main() {
	run();
	return 0;
}
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

const int MAXSLEN=100000;
const int MAXTLEN=100000;

char s[MAXSLEN+1]; int slen;
char t[MAXTLEN+1]; int tlen;

int nxt[MAXTLEN+1]; // nxt[i] is largest border of t[0..i)

int dp[MAXTLEN+1];

void run() {
	scanf("%s%s",s,t); slen=strlen(s),tlen=strlen(t);

	nxt[0]=nxt[1]=0;
	FOR(i,1,tlen) {
		int cur=nxt[i]; while(cur!=0&&t[cur]!=t[i]) cur=nxt[cur];
		nxt[i+1]=cur+(t[cur]==t[i]?1:0);
	}
	//REPE(i,tlen) printf("%d ",nxt[i]); puts(""); 

	memset(dp,-1,sizeof(dp)); dp[0]=0;
	REP(i,slen) {
		dp[tlen]=-1; for(int j=tlen-1;j>=0;--j) { if(dp[j]!=-1&&(s[i]=='?'||s[i]==t[j])&&(dp[j+1]==-1||dp[j]+(j+1==tlen?1:0)>dp[j+1])) dp[j+1]=dp[j]+(j+1==tlen?1:0); if(j!=0) dp[j]=-1; }
		for(int j=tlen;j>0;--j) if(dp[j]!=-1&&(dp[nxt[j]]==-1||dp[j]>dp[nxt[j]])) dp[nxt[j]]=dp[j];
		//printf("%c:",s[i]); REPE(j,tlen) printf(" %d",dp[j]); puts("");
	}
	printf("%d\n",dp[0]);
}

int main() {
	run();
	return 0;
}
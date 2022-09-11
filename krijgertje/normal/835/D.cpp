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

const int MAXN=5000;

char s[MAXN+1]; int n;

int dp[MAXN][MAXN];
int ret[MAXN+1];

void run() {
	scanf("%s",s); n=strlen(s);

	FORE(len,1,n) REPE(i,n-len) {
		int j=i+len-1;
		if(len==1) { dp[i][j]=1; continue; }
		if(len==2) { dp[i][j]=s[i]==s[j]?2:0; continue; }
		if(s[i]!=s[j]||dp[i+1][j-1]==0) { dp[i][j]=0; continue; }
		int hlen=len/2,k=i+hlen-1;
		dp[i][j]=1+dp[i][k];
	}
	memset(ret,0,sizeof(ret));
	REP(i,n) FOR(j,i,n) ++ret[dp[i][j]];
	for(int i=n;i>=2;--i) ret[i-1]+=ret[i];
	FORE(i,1,n) { if(i!=1) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}
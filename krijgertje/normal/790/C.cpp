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

const int MAXN=75;

int n;
char s[MAXN+1];

int na,nb,nc;
int dp[MAXN+1][MAXN+1][MAXN+1]; // dp[a][b][c] bc is forbidden

int A[MAXN],B[MAXN],C[MAXN];

int getcost(int a,int b,int c,int idx) {
	int ret=idx;
	REP(i,a) if(A[i]<idx) --ret;
	REP(i,b) if(B[i]<idx) --ret;
	REP(i,c) if(C[i]<idx) --ret;
	return ret;
}

void run() {
	scanf("%d%s",&n,s); REP(i,n) if(s[i]=='V') s[i]='b'; else if(s[i]=='K') s[i]='c'; else s[i]='a';
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0; na=nb=nc=0; REP(i,n) if(s[i]=='a') A[na++]=i; else if(s[i]=='b') B[nb++]=i; else if(s[i]=='c') C[nc++]=i;

	REPE(a,na) REPE(b,nb) REPE(c,nc) if(dp[a][b][c]!=-1) {
		//printf("dp[%d][%d][%d]=%d\n",a,b,c,dp[a][b][c]);
		int cur1=dp[a][b][c];
		REPE(cc,nc-c) {
			int cur2=cur1;
			REPE(bb,nb-b) {
				if(a==na&&b+bb==nb&&c+cc==nc) {
					if(dp[a][b+bb][c+cc]==-1||cur2<dp[a][b+bb][c+cc]) dp[a][b+bb][c+cc]=cur2;
				} else if(a<na) {
					int cur3=cur2;
					cur3+=getcost(a,b+bb,c+cc,A[a]);
					if(dp[a+1][b+bb][c+cc]==-1||cur3<dp[a+1][b+bb][c+cc]) dp[a+1][b+bb][c+cc]=cur3;
				}
				if(b+bb!=nb) cur2+=getcost(a,b+bb,c+cc,B[b+bb]);
			}
			if(c+cc!=nc) cur1+=getcost(a,b,c+cc,C[c+cc]);
		}
	}
	printf("%d\n",dp[na][nb][nc]);
}

int main() {
	run();
	return 0;
}
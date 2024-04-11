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
const int MOD=1000000007;

int n;
char s[MAXN+1];

int dp[MAXN][MAXN+1]; // dp[i][j]=#ways to split with first year length j = sum(dp[i+j][k],k>=j+(?1:0))
int sum[MAXN][MAXN+1]; // sum[i][j]=sum(dp[i][k],k>=j)
int diff[MAXN][MAXN+1]; // diff[i][j]=first diff when comparing [i..i+j) with [i+j..i+2*j)


void run() {
	scanf("%d%s",&n,s);
	for(int i=n-1;i>=0;--i) {
		FORE(j,1,n-i) {
			if(i+j==n) { dp[i][j]=s[i]=='0'?0:1; continue; }
			if(i+2*j>n) { dp[i][j]=0; continue; }
			if(i+2*j==n) {
				diff[i][j]=j; REP(k,j) if(s[i+k]!=s[i+j+k]) { diff[i][j]=k; break; }
			} else {
				diff[i][j]=s[i]!=s[i+j]?0:diff[i+1][j]+1;
			}
			bool lower=diff[i][j]<j&&s[i+diff[i][j]]<s[i+j+diff[i][j]];
			//printf("[%d,%d]: ",i,j); REP(k,j) printf("%c",s[i+k]); printf(" "); REP(k,j) printf("%c",s[i+j+k]); printf(" -> %d %s\n",diff[i][j],lower?"<":">=");
			dp[i][j]=s[i]=='0'?0:sum[i+j][j+(lower?0:1)];
		}
		for(int j=n-i;j>=1;--j) {
			sum[i][j]=(j==n-i?0:sum[i][j+1])+dp[i][j];
			if(sum[i][j]>=MOD) sum[i][j]-=MOD;
		}
	}
	printf("%d\n",sum[0][1]);
}

int main() {
	run();
	return 0;
}
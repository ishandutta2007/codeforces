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

const int MAXN=3000;

int n;
int a[MAXN];
ll dp[MAXN][MAXN]; // dp[i][j]=minimum cost for making [0..i] strictly increasing and b[i]=a[j]+i-j
ll dpmin[MAXN][MAXN]; // dpmin[i][j]=min(dp[i][k],k<=i&&idx[k]<=j)
int idx[MAXN],ridx[MAXN];


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	vector<pair<int,int> > tmp; REP(i,n) tmp.PB(MP(a[i]-i,i)); sort(tmp.begin(),tmp.end()); REP(i,n) idx[tmp[i].second]=i,ridx[i]=tmp[i].second;
	//printf("idx:"); REP(i,n) printf(" %d",idx[i]); puts("");
	//printf("ridx:"); REP(i,n) printf(" %d",ridx[i]); puts("");
	REP(i,n) {
		REP(j,n) {
			int cur=abs(a[j]+i-j-a[i]);
			if(i==0) dp[i][j]=cur; else dp[i][j]=dp[i-1][j]+cur;
			//if(i>0&&j>=i) REP(k,i) if(a[k]+i-1-k<a[j]+i-j) dp[i][j]=min(dp[i][j],dp[i-1][k]+cur);
			if(i>0&&j>=i&&dpmin[i-1][idx[j]]!=LLONG_MAX) dp[i][j]=min(dp[i][j],dpmin[i-1][idx[j]]+cur);
			//if(i>0&&j>=i&&dpmin[i-1][idx[j]]<dp[i][j]-cur) printf("err: %d %d\n",i,j);
		}
		REP(j,n) dpmin[i][j]=min(j==0?LLONG_MAX:dpmin[i][j-1],ridx[j]>i?LLONG_MAX:dp[i][ridx[j]]);
		//REP(j,n) printf("%4lld ",dp[i][j]); puts("");
		//REP(j,n) printf("%4lld ",dpmin[i][j]==LLONG_MAX?-1:dpmin[i][j]); puts("");
	}
	ll ret=LLONG_MAX; REP(j,n) ret=min(ret,dp[n-1][j]); printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}
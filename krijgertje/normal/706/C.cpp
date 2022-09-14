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

const int MAXN=100000;
const int MAXSLEN=100000;

int n;
int c[MAXN];
int len[MAXN],slen[MAXN+1];
char s[MAXSLEN+1];

ll dp[MAXN][2];

bool before(char *as,int alen,bool arev,char *bs,int blen,bool brev) {
	int ad=+1; if(arev) as+=alen-1,ad=-1;
	int bd=+1; if(brev) bs+=blen-1,bd=-1;
	int len=min(alen,blen);
	REP(i,len) {
		//printf("\t%c %c\n",*as,*bs);
		if(*as!=*bs) return *as<*bs;
		as+=ad; bs+=bd;
	}
	return alen<=blen;
}
void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&c[i]);
	slen[0]=0; REP(i,n) { scanf("%s",s+slen[i]); len[i]=strlen(s+slen[i]); slen[i+1]=slen[i]+len[i]; }
	//printf("%s\n",s);
	memset(dp,-1,sizeof(dp)); dp[0][0]=0; dp[0][1]=c[0];
	REP(i,n-1) REP(j,2) if(dp[i][j]!=-1) REP(nj,2) {
		ll nval=dp[i][j]+(nj==1?c[i+1]:0); if(dp[i+1][nj]!=-1&&nval>=dp[i+1][nj]) continue;
		if(!before(s+slen[i],len[i],j==1,s+slen[i+1],len[i+1],nj==1)) continue;
		//printf("%d %d -> %d %d\n",i,j,i+1,nj);
		dp[i+1][nj]=nval;
	}
	ll ret=-1; REP(j,2) if(dp[n-1][j]!=-1&&(ret==-1||dp[n-1][j]<ret)) ret=dp[n-1][j]; printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}
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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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

const int MAXSLEN=100000;
const int MAXQ=1000;
const int MAXRLEN=250;

int slen,nq;
char s[MAXSLEN+1];
char qkind[MAXQ]; int qidx[MAXQ]; char qc[MAXQ]; bool qans[MAXQ];

int nxt[MAXSLEN+1][26];
int dp[MAXRLEN+1][MAXRLEN+1][MAXRLEN+1];

int rlen[3]; char r[3][MAXRLEN+1];

void upd(int &a,int b) { if(b==-1) return; a=min(a,b+1); }
void calc(int i,int j,int k) {
	//printf("calc(%d,%d,%d)\n",i,j,k);
	dp[i][j][k]=INT_MAX;
	if(i-1>=0&&dp[i-1][j][k]!=INT_MAX) upd(dp[i][j][k],nxt[dp[i-1][j][k]][r[0][i-1]-'a']);
	if(j-1>=0&&dp[i][j-1][k]!=INT_MAX) upd(dp[i][j][k],nxt[dp[i][j-1][k]][r[1][j-1]-'a']);
	if(k-1>=0&&dp[i][j][k-1]!=INT_MAX) upd(dp[i][j][k],nxt[dp[i][j][k-1]][r[2][k-1]-'a']);
}

void solve() {
	REP(x,26) nxt[slen][x]=-1; for(int i=slen-1;i>=0;--i) { REP(x,26) nxt[i][x]=nxt[i+1][x]; nxt[i][s[i]-'a']=i; }
	//REPE(i,slen) REP(x,26) if(nxt[i][x]!=-1) printf("nxt[%d][%c]=%d\n",i,'a'+x,nxt[i][x]);
	REP(i,3) rlen[i]=0,r[i][0]='\0';
	dp[0][0][0]=0;
	REP(qi,nq) {
		int idx=qidx[qi]; char kind=qkind[qi],c=qc[qi];
		if(kind=='-') { assert(rlen[idx]>0); --rlen[idx]; r[idx][rlen[idx]]='\0'; }
		if(kind=='+') {
			assert(rlen[idx]<MAXRLEN); r[idx][rlen[idx]++]=c; r[idx][rlen[idx]]='\0';
			if(idx==0) { int i=rlen[0]; REPE(j,rlen[1]) REPE(k,rlen[2]) calc(i,j,k); }
			if(idx==1) { int j=rlen[1]; REPE(i,rlen[0]) REPE(k,rlen[2]) calc(i,j,k); }
			if(idx==2) { int k=rlen[2]; REPE(i,rlen[0]) REPE(j,rlen[1]) calc(i,j,k); }
		}
		qans[qi]=dp[rlen[0]][rlen[1]][rlen[2]]!=INT_MAX;
		//printf("%d %d %d:",rlen[0],rlen[1],rlen[2]); REPE(i,rlen[0]) REPE(j,rlen[1]) REPE(k,rlen[2]) if(dp[i][j][k]!=INT_MAX) printf(" %d|%d|%d=%d",i,j,k,dp[i][j][k]); puts("");
	}
}

void run() {
	scanf("%d%d",&slen,&nq);
	scanf("%s",s);
	REP(i,nq) { scanf(" %c%d",&qkind[i],&qidx[i]); --qidx[i]; if(qkind[i]=='+') scanf(" %c",&qc[i]); }
	solve();
	REP(i,nq) printf("%s\n",qans[i]?"YES":"NO");
}

int main() {
	run();
	return 0;
}
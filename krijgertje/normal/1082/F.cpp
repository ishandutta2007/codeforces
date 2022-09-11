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

const int MAXNUMBER=500;
const int MAXBUT=10;
const int MAXSUMLEN=500;
const int MAXTNODE=MAXSUMLEN+1;
struct TNode { int nxt[10],freq; };

int nnumber,nbut;
char s[MAXNUMBER][MAXSUMLEN+1]; int freq[MAXNUMBER];


TNode t[MAXTNODE]; int nt,troot;
int tmake() { assert(nt<MAXTNODE); int ret=nt++; memset(t[ret].nxt,-1,sizeof(t[ret].nxt)); t[ret].freq=0; return ret; }

int dp[MAXTNODE][MAXTNODE+1][MAXBUT+1]; // dp[i][j][k] = minimum cost to press subtree of i using k speedbuttons, given that it takes j presses to make the root
void upd(int &a,int b) { a=min(a,b); }

void dfs(int at,int dep) {
	REP(x,10) if(t[at].nxt[x]!=-1) dfs(t[at].nxt[x],dep+1);

	REPE(j,dep) REPE(k,nbut) dp[at][j][k]=j*t[at].freq;
	REP(x,10) if(t[at].nxt[x]!=-1) {
		int to=t[at].nxt[x];
		REPE(j,dep) for(int k=nbut;k>=0;--k) {
			FORE(dk,1,nbut-k) upd(dp[at][j][k+dk],dp[at][j][k]+dp[to][j+1][dk]);
			dp[at][j][k]+=dp[to][j+1][0];
		}
	}
	REPE(j,dep) FORE(k,1,nbut) upd(dp[at][j][k],dp[at][0][k-1]);
}

int solve() {
	nt=0; troot=tmake();
	REP(i,nnumber) {
		int at=troot,len=strlen(s[i]);
		REP(j,len) {
			int x=s[i][j]-'0';
			if(t[at].nxt[x]==-1) t[at].nxt[x]=tmake();
			at=t[at].nxt[x];
		}
		t[at].freq+=freq[i];
	}
	dfs(troot,0);
	return dp[troot][0][nbut];
}

void run() {
	scanf("%d%d",&nnumber,&nbut);
	REP(i,nnumber) scanf("%s%d",s[i],&freq[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
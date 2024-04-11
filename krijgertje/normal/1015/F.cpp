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

const int MAXN=100;
const int MAXLEN=200;
const int MOD=1000000007;

int n;
char s[MAXLEN+1]; int slen;

int nxt[MAXLEN+1]; // nxt[i]=longest proper suffix of s[0..i) that is also a prefix

int dp[2*MAXN+1][2*MAXN+1][MAXLEN+1];
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

void run() {
	scanf("%d",&n); scanf("%s",s); slen=strlen(s);

	nxt[0]=nxt[1]=0; FORE(i,2,slen) { nxt[i]=nxt[i-1]; while(nxt[i]!=0&&s[i-1]!=s[nxt[i]]) nxt[i]=nxt[nxt[i]]; if(s[i-1]==s[nxt[i]]) ++nxt[i]; }
	//printf("nxt:"); REPE(i,slen) printf(" %d",nxt[i]); puts("");

	int bal=0,minbal=0; REP(i,slen) { bal+=s[i]=='('?+1:-1; minbal=min(minbal,bal); }
	int pref=-minbal,suff=bal-minbal;
	//printf("pref=%d suff=%d\n",pref,suff);

	memset(dp,0,sizeof(dp)); inc(dp[0][0][0],1);
	REP(i,2*n) REPE(j,2*n) REPE(k,slen) if(dp[i][j][k]!=0) REP(z,2) {
		char c=z==0?'(':')';
		int nj=j+(c=='('?+1:-1),nk=k; if(nk!=slen) { while(nk!=0&&c!=s[nk]) nk=nxt[nk]; if(c==s[nk]) ++nk; }
		//printf("(%d,%d,%d) %c -> (%d,%d,%d)\n",i,j,k,c,i+1,nj,nk);
		if(nj>=0) inc(dp[i+1][nj][nk],dp[i][j][k]);
	}
	//REPE(i,2*n) REPE(j,2*n) REPE(k,slen) if(dp[i][j][k]!=0) printf("dp[%d][%d][%d]=%d\n",i,j,k,dp[i][j][k]);
	printf("%d\n",dp[2*n][0][slen]);
}

int main() {
	run();
	return 0;
}
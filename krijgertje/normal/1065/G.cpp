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

const int MAXN=200;
const int MAXNEED=200;

int n,need; ll idx;


char fpref[MAXN+1][MAXNEED+1];
char fsuff[MAXN+1][MAXNEED+1];
char ans[MAXNEED+1];

char s[2*MAXNEED+1];
ll dp[MAXN+1];

int nxt[MAXNEED+1];

int cnts() {
	int anslen=strlen(ans),slen=strlen(s);
	nxt[0]=nxt[1]=0;
	FORE(i,2,anslen) {
		nxt[i]=nxt[i-1];
		while(nxt[i]!=0&&ans[nxt[i]]!=ans[i-1]) nxt[i]=nxt[nxt[i]];
		if(ans[nxt[i]]==ans[i-1]) ++nxt[i];
	}
	//printf("nxt:"); REPE(i,anslen) printf(" %d",nxt[i]); puts("");
	int ret=0,at=0;
	REP(i,slen) {
		while(at!=0&&ans[at]!=s[i]) at=nxt[at];
		if(ans[at]==s[i]) ++at;
		if(at==anslen) ++ret,at=nxt[at];
	}
	//printf("cnts: %s in %s = %d\n",ans,s,ret);
	return ret;
}

bool hassuffix() {
	int anslen=strlen(ans);
	if(anslen==0) return false;
	int flen=strlen(fsuff[n]);
	if(anslen>flen) return false;
	REP(i,anslen) if(fsuff[n][flen-anslen+i]!=ans[i]) return false;
	//printf("has %s = yes\n",ans);
	return true;
}
ll safeadd(ll a,ll b) { if(a>=LLONG_MAX-b) return LLONG_MAX; else return a+b; }
ll cntsubstr() {
	int anslen=strlen(ans);
	REP(i,2) { s[0]='0'+i; s[1]='\0'; dp[i]=cnts(); }
	FORE(i,2,n) {
		int alen=strlen(fsuff[i-2]),blen=min(anslen-1,(int)strlen(fpref[i-1]));
		int askip=alen-min(alen,anslen-1);
		REP(j,alen-askip) s[j]=fsuff[i-2][askip+j]; REP(j,blen) s[alen-askip+j]=fpref[i-1][j]; s[alen-askip+blen]='\0';
		int cur=cnts();
		dp[i]=safeadd(cur,safeadd(dp[i-2],dp[i-1]));
	}
	//printf("cntsubstr %s = %lld\n",ans,dp[n]);
	return dp[n];
}

void solve() {
	REP(i,2) fpref[i][0]='0'+i,fpref[i][1]='\0';
	REP(i,2) fsuff[i][0]='0'+i,fsuff[i][1]='\0';
	FORE(i,2,n) {
		int alen=strlen(fpref[i-2]);
		int blen=min(need-alen,(int)strlen(fpref[i-1]));
		REP(j,alen) fpref[i][j]=fpref[i-2][j]; REP(j,blen) fpref[i][alen+j]=fpref[i-1][j]; fpref[i][alen+blen]='\0';
	}
	FORE(i,2,n) {
		int blen=strlen(fsuff[i-1]);
		int alen=strlen(fsuff[i-2]),askip=alen-min(need-blen,alen);
		REP(j,alen-askip) fsuff[i][j]=fsuff[i-2][askip+j]; REP(j,blen) fsuff[i][alen-askip+j]=fsuff[i-1][j]; fsuff[i][alen-askip+blen]='\0';
	}
	//REPE(i,n) printf("%d: pref=%s suff=%s\n",i,fpref[i],fsuff[i]);

	ll rem=idx;
	REP(i,need) {
		ans[i]='\0';
		if(hassuffix()) { if(rem==0) return; else --rem; }
		ans[i]='0'; ans[i+1]='\0';
		ll cnt=cntsubstr();
		if(rem>=cnt) { ans[i]='1'; rem-=cnt; }
	}
	ans[need]='\0';
}

void run() {
	scanf("%d%lld%d",&n,&idx,&need),--idx;
	solve();
	printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}
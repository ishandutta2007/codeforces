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

const int MAXLEN=100000;
const int MAXQ=100000;
const int MOD=1000000007;
const int MAXHLEN=MAXLEN/2;
const int MAXCH=52;

char s[MAXLEN+1]; int slen;
int nq; int qa[MAXQ],qb[MAXQ],qans[MAXQ];

int hlen;
int ways[MAXHLEN+1];
char ch[MAXLEN]; int nch;
int cnt[MAXCH];
int ans[MAXCH][MAXCH];

int inv[MAXLEN+1];
int fac[MAXLEN+1];
int ifac[MAXLEN+1];

void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { if((a-=b)<0) a+=MOD; }
void addcnt(int by) {
	for(int i=hlen;i>=by;--i) inc(ways[i],ways[i-by]);
}
void remcnt(int by) {
	for(int i=by;i<=hlen;++i) dec(ways[i],ways[i-by]);
}

void solve() {
	nch=0; REP(i,slen) ch[nch++]=s[i]; sort(ch,ch+nch); nch=unique(ch,ch+nch)-ch; assert(nch<=MAXCH);
	REP(i,nch) cnt[i]=0; REP(i,slen) { int idx=lower_bound(ch,ch+nch,s[i])-ch; ++cnt[idx]; }
	//printf("cnt:"); REP(i,nch) printf(" %c=%d",ch[i],cnt[i]); puts("");

	hlen=slen/2; REPE(i,hlen) ways[i]=0; ways[0]=1;
	REP(i,nch) addcnt(cnt[i]);
	REP(i,nch) {
		remcnt(cnt[i]);
		ans[i][i]=ways[hlen];
		FOR(j,i+1,nch) {
			remcnt(cnt[j]);
			ans[i][j]=ans[j][i]=ways[hlen];
			addcnt(cnt[j]);
		}
		addcnt(cnt[i]);
	}
	//REP(i,nch) { printf("ans%d:",i); REP(j,nch) printf(" %d",ans[i][j]); puts(""); }

	inv[1]=1; FORE(i,2,slen) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,slen) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,slen) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;
	int mlt=2; REP(i,2) mlt=(ll)mlt*fac[hlen]%MOD; REP(i,nch) mlt=(ll)mlt*ifac[cnt[i]]%MOD;
	REP(i,nch) REP(j,nch) ans[i][j]=(ll)ans[i][j]*mlt%MOD;
	//printf("mlt=%d\n",mlt);

	REP(i,nq) {
		int a=lower_bound(ch,ch+nch,s[qa[i]])-ch;
		int b=lower_bound(ch,ch+nch,s[qb[i]])-ch;
		qans[i]=ans[a][b];
	}
}

void run() {
	scanf("%s",s); slen=strlen(s);
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d",&qa[i],&qb[i]),--qa[i],--qb[i];
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}
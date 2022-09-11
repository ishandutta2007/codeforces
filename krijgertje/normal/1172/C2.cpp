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

const int MAXPICT=200000;
const int MAXVISIT=3000;
const int MOD=998244353;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { inc(a,MOD-b); }
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int inv(int x) { return pw(x,MOD-2); }

int npict,nvisit;
int like[MAXPICT];
int w[MAXPICT];
int ans[MAXPICT];

int prob[MAXVISIT+1][MAXVISIT+1]; // prob[i][j] is probability that after i visits exactly j of them were liked

int invtot[2*MAXVISIT+1];

void solve() {
	int ssumlike=0,ssumhate=0; REP(i,npict) if(like[i]==1) ssumlike+=w[i]; else ssumhate+=w[i];
	FORE(delta,-nvisit,+nvisit) if(ssumlike+ssumhate+delta>0) invtot[nvisit+delta]=inv(ssumlike+ssumhate+delta);

	memset(prob,0,sizeof(prob));
	prob[0][0]=1;
	REP(i,nvisit) REPE(j,i) if(prob[i][j]!=0) {
		int csumlike=ssumlike+j,csumhate=ssumhate-(i-j);
		int cdeltatot=2*j-i; assert(ssumlike+ssumhate+cdeltatot>0);
		inc(prob[i+1][j+0],(ll)prob[i][j]*csumhate%MOD*invtot[nvisit+cdeltatot]%MOD);
		inc(prob[i+1][j+1],(ll)prob[i][j]*csumlike%MOD*invtot[nvisit+cdeltatot]%MOD);
	}
	//REPE(j,nvisit) printf("prob %d: %d\n",j,prob[nvisit][j]);
	int hateloss=0,likewin=0,invhate=inv(ssumhate),invlike=inv(ssumlike);
	REPE(j,nvisit) {
		inc(hateloss,(ll)prob[nvisit][j]*(nvisit-j)%MOD*invhate%MOD);
		inc(likewin,(ll)prob[nvisit][j]*j%MOD*invlike%MOD);
	}
	REP(i,npict) { 
		ans[i]=w[i];
		if(like[i]==0) dec(ans[i],(ll)hateloss*w[i]%MOD);
		if(like[i]==1) inc(ans[i],(ll)likewin*w[i]%MOD);
	}
}

void run() {
	scanf("%d%d",&npict,&nvisit);
	REP(i,npict) scanf("%d",&like[i]);
	REP(i,npict) scanf("%d",&w[i]);
	solve();
	REP(i,npict) printf("%d\n",ans[i]);
}

int main() {
	run();
	return 0;
}
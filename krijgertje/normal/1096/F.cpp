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

const int MOD=998244353;
const int MAXN=200000;
const int MAXFAC=MAXN;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { inc(a,MOD-b); }
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int n;
int a[MAXN];

int inv[MAXFAC+1];
int fac[MAXFAC+1];
int ifac[MAXFAC+1];

bool have[MAXN];
int sumhave[MAXN+1];
int sumbefore[MAXN+1];

int bit[MAXN+1];
int bget(int idx) { ++idx; int ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }
void bmod(int idx,int by) { ++idx; while(idx<=n) { bit[idx]+=by; idx+=idx&-idx; } }

void init() {
	inv[1]=1; FORE(i,2,MAXFAC) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,MAXFAC) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,MAXFAC) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;
}

int solve() {
	REP(i,n) have[i]=false; REP(i,n) if(a[i]!=-1) have[a[i]]=true;
	sumhave[0]=0; REP(i,n) sumhave[i+1]=sumhave[i]+(have[i]?1:0);
	sumbefore[0]=0; REP(i,n) sumbefore[i+1]=sumbefore[i]+(a[i]==-1?1:0);
	int remtot=n-sumhave[n];
	//printf("remtot=%d\n",remtot);

	int num=0;
	REPE(i,n) bit[i]=0;
	REP(i,n) if(a[i]!=-1) {
		int remsmaller=a[i]-sumhave[a[i]];
		int remgreater=(n-a[i])-(sumhave[n]-sumhave[a[i]]);
		int rembefore=sumbefore[i],remafter=sumbefore[n]-sumbefore[i];
		int curgreater=(i-sumbefore[i])-bget(a[i]); bmod(a[i],+1);
		//printf("idx=%d val=%d remsmaller=%d remgreater=%d rembefore=%d remafter=%d curgreater=%d\n",i,a[i],remsmaller,remgreater,rembefore,remafter,curgreater);
		inc(num,(ll)remgreater*rembefore%MOD*fac[remtot-1]%MOD);
		inc(num,(ll)remsmaller*remafter%MOD*fac[remtot-1]%MOD);
		inc(num,(ll)curgreater*fac[remtot]%MOD);
	}
	inc(num,(ll)remtot*(remtot-1)/2%MOD*inv[2]%MOD*fac[remtot]%MOD);
	int den=fac[remtot];
	return (ll)num*pw(den,MOD-2)%MOD;
}

void run() {
	scanf("%d",&n);
	REP(i,n) { scanf("%d",&a[i]); if(a[i]!=-1) --a[i]; }
	init();
	printf("%d\n",solve());
}

int bfsolve() {
	vector<int> p(n); REP(i,n) p[i]=i;
	int num=0,den=0;
	do {
		bool ok=true; REP(i,n) if(a[i]!=-1&&a[i]!=p[i]) { ok=false; break; } if(!ok) continue;
		int cur=0; REP(i,n) FOR(j,i+1,n) if(p[i]>p[j]) ++cur;
		num+=cur,den+=1;
	} while(next_permutation(p.begin(),p.end()));
	return (ll)num*pw(den,MOD-2)%MOD;
}

void stress() {
	init();
	REP(rep,1000) {
		n=10; REP(i,n) a[i]=i; random_shuffle(a,a+n);
		int remtot=rand()%(n+1); REP(i,remtot) while(true) { int idx=rand()%n; if(a[i]==-1) continue; a[i]=-1; break; }
		int have=solve();
		int want=bfsolve();
		if(have==want) { printf("."); continue; }
		printf("err rep=%d have=%d want=%d\n",rep,have,want);
		printf("%d\n",n); REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]==-1?-1:a[i]+1); } puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}
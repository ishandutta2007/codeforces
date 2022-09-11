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

const int MAXP=10;
const int MAXN=1000000;
int pw(int x,int n,int mod) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%mod; if((n>>=1)==0) return ret; x=(ll)x*x%mod; } }

int p[MAXP],np;
bool isp(int x) { if(x<=1) return false; for(int i=2;i*i<=x;++i) if(x%i==0) return false; return true; }

int n;
char s[MAXN+1];

int sum[MAXP][MAXN+1];
int pp[MAXP][MAXN+1];
int dv[MAXP][MAXN+1];

bool test(int alen,int blen,int clen) {
	if(alen>=2&&s[0]=='0'||blen>=2&&s[alen]=='0'||clen>=2&&s[alen+blen]=='0') return false;
	//printf("here (%d,%d,%d)\n",alen,blen,clen);
	REP(i,np) {
		int asum=sum[i][alen];
		int bsum=((ll)sum[i][alen+blen]+p[i]-(ll)sum[i][alen]*pp[i][blen]%p[i])%p[i];
		int csum=((ll)sum[i][alen+blen+clen]+p[i]-(ll)sum[i][alen+blen]*pp[i][clen]%p[i])%p[i];
		if((asum+bsum)%p[i]!=csum) return false;
	}
	int cur=0;
	REP(i,clen) {
		int a=i<alen?s[alen-i-1]-'0':0;
		int b=i<blen?s[alen+blen-i-1]-'0':0;
		int c=s[alen+blen+clen-i-1]-'0';
		cur+=a+b;
		if(cur%10!=c) return false;
		cur/=10;
	}
	return cur==0;
}
void print(int alen,int blen,int clen) {
	REP(i,alen) printf("%c",s[i]); printf("+"); REP(i,blen) printf("%c",s[alen+i]); printf("="); REP(i,clen) printf("%c",s[alen+blen+i]); puts("");
}

void run() {
	np=0; for(int i=1000000000;np<MAXP;++i) if(isp(i)) p[np++]=i;
	//REP(i,np) printf("%d\n",p[i]);

	scanf("%s",s); n=strlen(s);
	REP(i,np) { sum[i][0]=0; REP(j,n) sum[i][j+1]=((ll)10*sum[i][j]+(s[j]-'0'))%p[i]; }
	REP(i,np) { pp[i][0]=1; pp[i][1]=10; FORE(j,2,n) pp[i][j]=(ll)pp[i][j-1]*pp[i][1]%p[i]; }
	REP(i,np) { dv[i][0]=1; dv[i][1]=pw(10,p[i]-2,p[i]); FORE(j,2,n) dv[i][j]=(ll)dv[i][j-1]*dv[i][1]%p[i]; }

	FORE(clen,1,n) {
		FORE(alen,max(1,clen-1),clen) { int blen=n-clen-alen; if(blen>=1&&blen<=clen&&test(alen,blen,clen)) { print(alen,blen,clen); return; } }
		FORE(blen,max(1,clen-1),clen) { int alen=n-clen-blen; if(alen>=1&&alen<=clen&&test(alen,blen,clen)) { print(alen,blen,clen); return; } }
	}
	printf("no solution\n");
}

int main() {
	run();
	return 0;
}
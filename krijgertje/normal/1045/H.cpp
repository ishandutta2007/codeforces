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

const int MAXLEN=100000;
const int MOD=1000000007;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

char l[MAXLEN+1]; int llen;
char r[MAXLEN+1]; int rlen;
int sa,sb,sc,sd;

int inv[MAXLEN+1];
int fac[MAXLEN+1];
int ifac[MAXLEN+1];
int C(int n,int k) { if(k<0||k>n) return 0; return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD; }

int calczero(int len,int a,int b,int c,int d) { // ways to satisfy the constaints for a string starting with a 0 and having len characters after
	if(a<0||b<0||c<0||d<0) return 0;
	if(len!=a+b+c+d) return 0;
	if(c>b||c<b-1) return 0;
	int na=c+1,nd=b;
	return (ll)(a==0?1:C(a+na-1,a))*(d==0?1:C(d+nd-1,d))%MOD;
}
int calcone(int maxlen,int a,int b,int c,int d) { // ways to satisfy the constraints for any string starting with a 1 and having at most maxlen characters after
	if(a<0||b<0||c<0||d<0) return 0;
	int len=a+b+c+d; if(len>maxlen) return 0;
	if(b>c||b<c-1) return 0;
	int na=c,nd=b+1;
	return (ll)(a==0?1:C(a+na-1,a))*(d==0?1:C(d+nd-1,d))%MOD;
}

int calc(char *s) {
	int slen=strlen(s);
	if(slen>=1) assert(s[0]=='1');
	int a=sa,b=sb,c=sc,d=sd;
	int ret=0;
	if(slen>=2) inc(ret,calcone(slen-2,a,b,c,d));
	REP(i,slen) {
		if(i!=0&&s[i]=='1') inc(ret,calczero(slen-i-1,a-(s[i-1]=='0'?1:0),b,c-(s[i-1]=='1'?1:0),d));
		if(i!=0) { if(s[i-1]=='0'&&s[i]=='0') --a; else if(s[i-1]=='0'&&s[i]=='1') --b; else if(s[i-1]=='1'&&s[i]=='0') --c; else if(s[i-1]=='1'&&s[i]=='1') --d; else assert(false); }
	}
	if(slen>=1&&a==0&&b==0&&c==0&&d==0) inc(ret,1);
	return ret;
}

void precalc() {
	inv[1]=1; FORE(i,2,MAXLEN) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,MAXLEN) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,MAXLEN) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;
}

int solve() {
	int rcnt=calc(r);
	for(int i=llen-1;i>=0;--i) if(l[i]=='1') { l[i]='0'; break; } else l[i]='1';
	int lcnt=l[0]=='0'?calc(l+1):calc(l);
	int ret=(rcnt+MOD-lcnt)%MOD;
	return ret;
}

void run() {
	scanf("%s%s",l,r); llen=strlen(l),rlen=strlen(r); scanf("%d%d%d%d",&sa,&sb,&sc,&sd);
	printf("%d\n",solve());
}


bool bfsatisfies(char *s) {
	int slen=strlen(s);
	int a=sa,b=sb,c=sc,d=sd;
	FOR(i,1,slen) { if(s[i-1]=='0'&&s[i]=='0') --a; else if(s[i-1]=='0'&&s[i]=='1') --b; else if(s[i-1]=='1'&&s[i]=='0') --c; else if(s[i-1]=='1'&&s[i]=='1') --d; else assert(false); }
	return a==0&&b==0&&c==0&&d==0;
}

void stress() {
	REPE(a,3) REPE(b,3) REPE(c,3) REPE(d,3) {
		sa=a,sb=b,sc=c,sd=d;
		int len=a+b+c+d+1;
		int want=0;
		FORE(i,1,1<<(len+1)) {
			int clen=0; for(int x=i;x!=0;x/=2) r[clen++]='0'+x%2; r[clen]='\0'; reverse(r,r+clen);
			int have=calc(r);
			want+=bfsatisfies(r)?1:0;
			if(have==want) { printf("."); continue; }
			printf("err have=%d want=%d\n",have,want);
			printf("%s %d %d %d %d\n",r,a,b,c,d);
			return;
		}
	}
}

int main() {
	precalc();
	run();
	//stress();
	return 0;
}
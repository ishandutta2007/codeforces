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

const int MAXLEN=300000;
const int MOD=1000000007;

char c[MAXLEN+1]; int clen;
char d[MAXLEN+1]; int dlen;
int n;
int p2[MAXLEN+2];

int pmx[MAXLEN+1];
int phi[MAXLEN+1];
int f[MAXLEN+1];

int fac[2*MAXLEN+1];
int inv[2*MAXLEN+1];
int ifac[2*MAXLEN+1];

void run() {
	p2[0]=1; FORE(i,1,MAXLEN+1) p2[i]=(ll)2*p2[i-1]%MOD;
	inv[1]=1; FORE(i,2,2*MAXLEN) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1; FORE(i,1,2*MAXLEN) fac[i]=(ll)fac[i-1]*i%MOD;
	ifac[0]=1; FORE(i,1,2*MAXLEN) ifac[i]=(ll)ifac[i-1]*inv[i]%MOD;
	memset(pmx,0,sizeof(pmx)); FORE(i,2,MAXLEN) if(pmx[i]==0) for(int j=i;j<=MAXLEN;j+=i) pmx[j]=i;
	phi[1]=1; FORE(i,2,MAXLEN) { int j=i/pmx[i]; phi[i]=pmx[i]==pmx[j]?phi[j]*pmx[i]:phi[j]*(pmx[i]-1); }
	f[1]=1; FORE(i,2,MAXLEN) f[i]=(f[i-1]+(ll)2*phi[i])%MOD;

	scanf("%s%s%d",c,d,&n); clen=strlen(c); dlen=strlen(d);
	int ca=0,cb=0,cq=0; REP(i,clen) if(c[i]=='A') ++ca; else if(c[i]=='B') ++cb; else ++cq;
	int da=0,db=0,dq=0; REP(i,dlen) if(d[i]=='A') ++da; else if(d[i]=='B') ++db; else ++dq;

	int ret=0;
	FORE(a,-clen,+dlen) { // d contains a As more than c
		int b=dlen-clen-a;
		int have=cq+dq,need=ca+a-da+cq; if(need<0||need>have) continue;
		int cur=(ll)fac[have]*ifac[need]%MOD*ifac[have-need]%MOD;
		//printf("%d %d -> %d\n",a,b,cur);
		if(a==0&&b==0) {
			assert(clen==dlen);
			int cursame=1; REP(i,clen) if(c[i]=='A'&&d[i]=='B'||c[i]=='B'&&d[i]=='A') cursame=0; else if(c[i]=='?'&&d[i]=='?') cursame=(ll)2*cursame%MOD;
			int curdiff=(cur+MOD-cursame)%MOD;
			int anything=(p2[n+1]+MOD-2)%MOD;
			int nowsame=(ll)anything*anything%MOD;
			//printf("same=%d diff=%d (%d/%d)\n",cursame,curdiff,nowsame,nowdiff);
			ret=(ret+(ll)cursame*nowsame)%MOD;
			FORE(g,1,n) {
				int nowdiff=(ll)p2[g]*f[n/g]%MOD;
				ret=(ret+(ll)curdiff*nowdiff)%MOD;
			}
		}
		if(a<0&&b>0||a>0&&b<0) {
			int g=gcd(abs(a),abs(b));
			int slen=abs(b)/g,tlen=abs(a)/g,mlen=max(slen,tlen); // sum(p2[i] | i*mlen<=n)
			int imx=n/mlen;
			int now=(p2[imx+1]+MOD-2)%MOD;
			//printf("a=%d b=%d -> g=%d slen=%d tlen=%d -> %d\n",a,b,g,slen,tlen,now);
			ret=(ret+(ll)cur*now)%MOD;
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
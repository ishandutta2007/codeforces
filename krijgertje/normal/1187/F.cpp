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

const int MAXN=200000;
const int MOD=1000000007;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { inc(a,MOD-b); }
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int inv(int x) { assert(x!=0); return pw(x,MOD-2); }

int n;
int l[MAXN],r[MAXN];

int len[MAXN];
int invlen[MAXN];
int p[MAXN-1];

int solve() {
	REP(i,n) len[i]=r[i]-l[i]+1,invlen[i]=inv(len[i]);
	REP(i,n-1) {
		int la=l[i],ra=r[i],lb=l[i+1],rb=r[i+1],lena=ra-la+1,lenb=rb-lb+1;
		int lab=max(la,lb),rab=min(ra,rb),lenab=lab<=rab?rab-lab+1:0;
		int waysdiff=((ll)lenab*(lenb-1)+(ll)(lena-lenab)*lenb)%MOD;
		p[i]=(ll)waysdiff*invlen[i]%MOD*invlen[i+1]%MOD;
	}
	//printf("p:"); REP(i,n-1) printf(" %d",p[i]); puts("");
	int ret=1;
	int psum=0; REP(i,n-1) inc(psum,p[i]);
	inc(ret,(ll)3*psum%MOD);
	REP(i,n-1) {
		int cur=psum;
		dec(cur,p[i]); if(i-1>=0) dec(cur,p[i-1]); if(i+1<n-1) dec(cur,p[i+1]);
		inc(ret,(ll)cur*p[i]%MOD);
	}
	REP(i,n-2) {
		int la=l[i],ra=r[i],lb=l[i+1],rb=r[i+1],lc=l[i+2],rc=r[i+2],lena=ra-la+1,lenb=rb-lb+1,lenc=rc-lc+1;
		int labc=max(la,max(lb,lc)),rabc=min(ra,min(rb,rc)),lenabc=labc<=rabc?rabc-labc+1:0;
		int lab=max(la,lb),rab=min(ra,rb),lenab=lab<=rab?rab-lab+1-lenabc:0;
		int lbc=max(lb,lc),rbc=min(rb,rc),lenbc=lbc<=rbc?rbc-lbc+1-lenabc:0;
		int lennone=lenb-lenabc-lenab-lenbc;
		int waysdiff=((ll)lenabc*(lena-1)%MOD*(lenc-1)+(ll)lenab*(lena-1)%MOD*lenc+(ll)lenbc*lena%MOD*(lenc-1)+(ll)lennone*lena%MOD*lenc)%MOD;
		int pdiff=(ll)waysdiff*invlen[i]%MOD*invlen[i+1]%MOD*invlen[i+2]%MOD;
		//printf("%d/%d/%d: abc=%d ab=%d bc=%d none=%d -> waysdiff=%d -> %d\n",i+1,i+2,i+3,lenabc,lenab,lenbc,lennone,waysdiff,pdiff);
		inc(ret,(ll)2*pdiff%MOD);
	}

	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&l[i]);
	REP(i,n) scanf("%d",&r[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
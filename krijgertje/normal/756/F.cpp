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

int pw(int x,int n,int mod) { /*printf("\tpw(%d,%d,%d)\n",x,n,mod);*/ int ret=1; while(true) { if(n&1) ret=(ll)ret*x%mod; if((n>>=1)==0) return ret; x=(ll)x*x%mod; } }
int inv(int x,int mod) { /*printf("\tinv(%d,%d)\n",x,mod);*/ int phi=mod==1000000007?mod-1:mod==1000000006?500000002:-1; assert(phi!=-1&&x>=1&&gcd(x,mod)==1); int ret=pw(x,phi-1,mod); assert((ll)ret*x%mod==1); return ret; }
int F(int a,int b,int bb,int r,int mod) { /*printf("\tF(%d,%d,%d,%d)\n",a,b,r,mod);*/ if(r==1) return ((ll)b+mod-a+1)%mod; return (ll)(pw(r,bb+1,mod)-pw(r,a,mod)+mod)*inv(r-1,mod)%mod; }
int G(int a,int b,int bb,int r,int mod) { /*printf("\tG(%d,%d,%d,%d)\n",a,b,r,mod);*/ return (((ll)b*pw(r,bb+1,mod)-(ll)a*pw(r,a,mod)-F(a+1,b,bb,r,mod))%mod+mod)%mod*inv(r-1,mod)%mod; }
int sval(char *s,int slen,int mod) { int ret=0; REP(i,slen) ret=((ll)10*ret+s[i]-'0')%mod; /*printf("\tsval=%d\n",ret);*/ return ret; }


const int MAXLEN=1000000;
const int MOD=1000000007;

int calc(char *s,int slen) {
	// A:sum(len=1..slen-1,sum(x=10^(len-1)..10^len-1,x*10^((s-10^(slen-1)+1)*slen+sum(l=len+1..slen-1,l*9*10^(l-1))+(10^len-1-x)*len)))
	// B:sum(x=10^(slen-1)..s,x*10^((s-x)*slen))

	// F(a,b,r)=sum(x=a..b,r^x)=(r^(b+1)-r^a)/(r-1)
	// G(a,b,r)=sum(x=a..b,x*r^x)=(b*r^(b+1)-a*r^a-F(a+1,b,r))/(r-1)
	// off[slen]=10^((s-10^(slen-1)+1)*slen)
	// off[len]=10^(9*sum(L=len..slen-2,L*10^L)+9*sum(L=len..slen-2,10^L))
	// A: sum(len=1..slen-1,off[slen]*off[len]*((10^len-1)*F(0,9*10^(len-1)-1,10^len)-G(0,9*10^(len-1)-1,10^len)))
	// B: s*F(0,s-10^(slen-1),10^slen)-G(0,s-10^(slen-1),10^slen)

	//REP(i,slen) printf("%c",s[i]); puts("");
	int ret=0;
	int s0=sval(s,slen,MOD),s1=sval(s,slen,MOD-1);
	FORE(len,1,slen) {
		int o1,o2,e1=0,e2=0,t,a,b,bb,r=pw(10,len,MOD);
		if(len!=slen) {
			e1=((ll)s1+MOD-1-pw(10,slen-1,MOD-1)+1)%(MOD-1);
			e2=len==slen-1?0:((ll)9*G(len,slen-2,slen-2,10,MOD-1)+(ll)9*F(len,slen-2,slen-2,10,MOD-1))%(MOD-1);
			//if(len!=slen-1) printf("\t9*%d+9*%d [%d..%d]\n",G(len,slen-2,10,MOD-1),F(len,slen-2,10,MOD-1),len,slen-2);
			o1=pw(10,(ll)e1*slen%(MOD-1),MOD);
			o2=pw(10,e2,MOD);
			t=r-1; if(t<0) t+=MOD; a=0; b=(ll)9*pw(10,len-1,MOD)%MOD-1; if(b<0) b+=MOD; bb=(ll)9*pw(10,len-1,MOD-1)%(MOD-1)-1; if(bb<0) bb+=MOD;
		} else {
			o1=o2=1;
			t=s0; a=0; b=s0-pw(10,len-1,MOD); if(b<0) b+=MOD; bb=s1-pw(10,len-1,MOD-1); if(bb<0) bb+=MOD-1;
		}
		int z=((ll)t*F(a,b,bb,r,MOD)-G(a,b,bb,r,MOD)+MOD)%MOD;
		int cur=(ll)o1*o2%MOD*z%MOD;
		//printf("%d: o1=%d o2=%d t=%d a=%d b=%d bb=%d r=%d z=%d cur=%d\n",len,o1,o2,t,a,b,bb,r,z,cur);
		ret+=cur; if(ret>=MOD) ret-=MOD;
	}
	//printf("=%d\n",ret);
	return ret;
}
int calclen(char *s,int slen) {
	// A:sum(len=1..slen-1,9*len*10^(len-1))
	// B:slen*(s-10^(slen-1)+1)

	int ret=0;
	int s1=sval(s,slen,MOD-1);
	FORE(len,1,slen) {
		int cnt;
		if(len!=slen) {
			cnt=(ll)9*pw(10,len-1,MOD-1)%(MOD-1);
		} else {
			cnt=(s1+MOD-1-pw(10,len-1,MOD-1)+1)%(MOD-1);
		}
		int cur=(ll)cnt*len%(MOD-1);
		ret+=cur; if(ret>=MOD-1) ret-=MOD-1;
	}
	//printf("len(%s)=%d\n",s,ret);
	return ret;
}

void dec(char *s,int &slen) {
	for(int i=slen-1;i>=0;--i) if(s[i]!='0') { --s[i]; break; } else s[i]='9';
	if(s[0]=='0') { REP(i,slen) s[i]=s[i+1]; --slen; }
}

typedef struct R { int len,val; } R;

char *nrstart[MAXLEN], *nrend[MAXLEN]; int nnr;
int termtype[MAXLEN],terma[MAXLEN],termb[MAXLEN],nterm;
vector<int> expr[MAXLEN]; int nexpr;

int parsenumber(char *&s) {
	assert(isdigit(*s));
	int ret=nnr++;
	nrstart[ret]=s;
	while(isdigit(*s)) ++s;
	nrend[ret]=s;
	return ret;
}
int parseexpr(char *&s);
int parseterm(char *&s) {
	int ret=nterm++;
	terma[ret]=parsenumber(s);
	if(*s=='-') { ++s; termtype[ret]=1; termb[ret]=parsenumber(s); }
	else if(*s=='(') { ++s; termtype[ret]=2; termb[ret]=parseexpr(s); assert(*s==')'); ++s; }
	else termtype[ret]=0;
	return ret;
}
int parseexpr(char *&s) {
	int ret=nexpr++;
	expr[ret].PB(parseterm(s));
	while(*s=='+') { ++s; expr[ret].PB(parseterm(s)); }
	return ret;
}
int parse(char *ss,int slen) {
	nexpr=nterm=nnr=0;
	char *s=ss;
	int expr=parseexpr(s);
	assert(s==ss+slen);
	return expr;
}

void printexpr(int e);
void printnumber(int x) { for(char *c=nrstart[x];c!=nrend[x];++c) printf("%c",*c); }
void printterm(int t) { printnumber(terma[t]); if(termtype[t]==1) { printf("-"); printnumber(termb[t]); } if(termtype[t]==2) { printf("("); printexpr(termb[t]); printf(")"); } }
void printexpr(int e) { REPSZ(i,expr[e]) { if(i!=0) printf("+"); printterm(expr[e][i]); } }

R concat(const R &a,const R &b) {
	R ret; ret.len=a.len+b.len; if(ret.len>=MOD-1) ret.len-=MOD-1; ret.val=((ll)a.val*pw(10,b.len,MOD)+b.val)%MOD; return ret;
}
R repeat(const R &b,char *s,int slen) {
	// b*sum(x=0..s-1,(10^blen)^x) = b*F(0,s-1,10^blen)
	int s0=sval(s,slen,MOD),s1=sval(s,slen,MOD-1);
	R ret; ret.len=(ll)b.len*s1%(MOD-1); ret.val=(ll)b.val*F(0,s0==0?MOD-1:s0-1,s1==0?MOD-2:s1-1,pw(10,b.len,MOD),MOD)%MOD; return ret;
}
R calcnumber(int x) {
	R ret; ret.len=0,ret.val=0;
	for(char *c=nrstart[x];c!=nrend[x];++c) ++ret.len,ret.val=((ll)10*ret.val+*c-'0')%MOD;
	return ret;
}
R calcexpr(int e);
R calcterm(int t) {
	if(termtype[t]==0) {
		return calcnumber(terma[t]);
	}
	if(termtype[t]==1) {
		char *a=nrstart[terma[t]]; int alen=nrend[terma[t]]-nrstart[terma[t]];
		char *b=nrstart[termb[t]]; int blen=nrend[termb[t]]-nrstart[termb[t]];
		dec(a,alen);
		int A=calclen(a,alen),B=calclen(b,blen),D=B-A; if(D<0) D+=MOD-1; //printf("%d %d -> %d\n",A,B,D);
		int val=calc(b,blen)-(ll)pw(10,D,MOD)*calc(a,alen)%MOD; if(val<0) val+=MOD;
		R ret; ret.len=D,ret.val=val; return ret;
	}
	if(termtype[t]==2) {
		R x=calcexpr(termb[t]);
		char *a=nrstart[terma[t]]; int alen=nrend[terma[t]]-nrstart[terma[t]];
		return repeat(x,a,alen);
	}
}
R calcexpr(int e) {
	R ret; ret.len=0,ret.val=0;
	REPSZ(i,expr[e]) {
		R cur=calcterm(expr[e][i]);
		ret=concat(ret,cur);
	}
	return ret;
}

char s[MAXLEN+1];
int slen;

void run() {
	scanf("%s",s); slen=strlen(s);
	int rt=parse(s,slen);
	//printexpr(rt); puts("");
	R res=calcexpr(rt);
	printf("%d\n",res.val);
}

int main() {
	run();
	return 0;
}
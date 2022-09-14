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

const int MAXLEN=500;
const int MOD=1000000007;
const int MAXX=1+2*83;

typedef struct X { int l,r; char op; } X;


char s[MAXLEN+1]; char *at;
X x[MAXX]; int nx;
int nq;

int ways[MAXX][1<<16];

inline void inc(int &a,const int &b) { if((a+=b)>=MOD) a-=MOD; }
inline void sub(int &a,const int &b) { if((a-=b)<0) a+=MOD; }
inline int mult(const int &a,const int &b) { return (ll)a*b%MOD; }
void print16(int x) { REP(i,16) printf("%c",((x>>i)&1)?'1':'0'); }
int parse() {
	char c=*at++;
	if(isalpha(c)||c=='?') {
		REP(low,2) for(char cc=(low?'a':'A');cc<=(low?'d':'D');++cc) if(c==cc||c=='?') REP(i,1<<16) {
			bool ok=true;
			REP(j,16) if(((i>>j)&1)!=(((j>>(tolower(cc)-'a'))&1)==(low?0:1))) { ok=false; break; }
			if(ok) ++ways[nx][i];
		}
		x[nx].l=x[nx].r=-1,x[nx].op='x'; return nx++;
	} else {
		assert(c=='(');
		int l=parse();
		c=*at++; assert(c==')');
		c=*at++; assert(c=='|'||c=='&'||c=='?'); char op=c;
		c=*at++; assert(c=='(');
		int r=parse();
		c=*at++; assert(c==')');
		x[nx].l=l,x[nx].op=op,x[nx].r=r; return nx++;
	}
}

int f[1<<16],fl[1<<16],fr[1<<16];
void calc(int at) {
	if(x[at].op=='x') return;
	//printf("calc(%d) = %c\n",at,x[at].op);
	calc(x[at].l);
	calc(x[at].r);
	if(x[at].op=='|'||x[at].op=='?') {
		REP(i,1<<16) fl[i]=ways[x[at].l][i]; REP(j,16) REP(i,1<<16) if((i>>j)&1) inc(fl[i],fl[i^(1<<j)]);
		REP(i,1<<16) fr[i]=ways[x[at].r][i]; REP(j,16) REP(i,1<<16) if((i>>j)&1) inc(fr[i],fr[i^(1<<j)]);
		REP(i,1<<16) f[i]=mult(fl[i],fr[i]); REP(j,16) REP(i,1<<16) if((i>>j)&1) sub(f[i],f[i^(1<<j)]);
		REP(i,1<<16) inc(ways[at][i],f[i]);
	}
	if(x[at].op=='&'||x[at].op=='?') {
		REP(i,1<<16) fl[i]=ways[x[at].l][i]; REP(j,16) REP(i,1<<16) if((i>>j)&1) inc(fl[i^(1<<j)],fl[i]);
		REP(i,1<<16) fr[i]=ways[x[at].r][i]; REP(j,16) REP(i,1<<16) if((i>>j)&1) inc(fr[i^(1<<j)],fr[i]);
		REP(i,1<<16) f[i]=mult(fl[i],fr[i]); REP(j,16) REP(i,1<<16) if((i>>j)&1) sub(f[i^(1<<j)],f[i]);
		REP(i,1<<16) inc(ways[at][i],f[i]);
	}
}


void run() {
	scanf("%s%d",s,&nq);
	int zero=0,one=0;
	REP(i,nq) { int a,b,c,d,e; scanf("%d%d%d%d%d",&a,&b,&c,&d,&e); int id=a+2*b+4*c+8*d; if(e==0) zero|=1<<id; else one|=1<<id; }

	nx=0; memset(ways,0,sizeof(ways));
	at=s; int root=parse();
	calc(root); assert(*at=='\0');

	//printf("0: "); print16(zero); printf(" 1: "); print16(one); puts("");

	//REP(i,1<<16) { print16(i); printf(" -> %d\n",ways[root][i]); }

	int ret=0;
	REP(i,1<<16) if((i&one)==one&&(i&zero)==0) inc(ret,ways[root][i]);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
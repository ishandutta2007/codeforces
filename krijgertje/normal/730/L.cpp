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

const int MAXN=400000;
const int MOD=1000000007;

int mypow(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) break; x=(ll)x*x%MOD; } return ret; }
int inv(int x) { assert(x!=0); return mypow(x,MOD-2); }

int n,nq;
char s[MAXN+1];

int match[MAXN];
int stck[MAXN],nstck;
int numb[MAXN],nnumb,numbval[MAXN],numbstart[MAXN],numbend[MAXN];
int term[MAXN],nterm,termval[MAXN],termstart[MAXN],termend[MAXN];
int expr[MAXN],nexpr,exprval[MAXN];

int p10[MAXN+1];
int digsum[MAXN+1];
int zerosum[MAXN+1],numbprod[MAXN+1];
int termsum[MAXN+1];

int parsenumb(int &at) {
	numbstart[nnumb]=at;
	if(s[at]=='(') {
		numbval[nnumb]=exprval[expr[at+1]];
		numb[at]=nnumb,term[at]=nterm,expr[at]=nexpr;
		at=match[at];
		numb[at]=nnumb,term[at]=nterm,expr[at]=nexpr;
		++at;
	} else if(isdigit(s[at])) {
		numbval[nnumb]=0;
		while(isdigit(s[at])) {
			numb[at]=nnumb,term[at]=nterm,expr[at]=nexpr;
			numbval[nnumb]=((ll)numbval[nnumb]*10+s[at]-'0')%MOD;
			++at;
		}
	} else assert(false);
	numbend[nnumb]=at-1;
	return numbval[nnumb++];
}
int parseterm(int &at) {
	termstart[nterm]=nnumb;
	termval[nterm]=parsenumb(at);
	while(s[at]=='*') {
		++at;
		termval[nterm]=(ll)termval[nterm]*parsenumb(at)%MOD;
	}
	termend[nterm]=nnumb-1;
	return termval[nterm++];
}
int parseexpr(int &at) {
	exprval[nexpr]=parseterm(at);
	while(s[at]=='+') {
		++at;
		exprval[nexpr]=(exprval[nexpr]+parseterm(at))%MOD;
	}
	return exprval[nexpr++];
}

int solvesamenumb(int l,int r) {
	if(s[l]=='(') return numbval[numb[l]];
	return (digsum[r+1]+MOD-(ll)p10[r-l+1]*digsum[l]%MOD)%MOD;
}
int solvesameterm(int l,int r) {
	int nzero=zerosum[r+1]-zerosum[l]; if(nzero!=0) return 0;
	return (ll)numbprod[r+1]*inv(numbprod[l])%MOD;
}
int solvesameexpr(int l,int r) {
	return (termsum[r+1]+MOD-termsum[l])%MOD;
}

int solve(int l,int r) {
	if(!isdigit(s[l])&&s[l]!='(') return -1;
	if(!isdigit(s[r])&&s[r]!=')') return -1;
	if(numb[l]==numb[r]) return solvesamenumb(l,r);
	if(term[l]==term[r]) {
		int a=solvesamenumb(l,numbend[numb[l]]);
		int b=solvesameterm(numb[l]+1,numb[r]-1);
		int c=solvesamenumb(numbstart[numb[r]],r);
		return (ll)a*b%MOD*c%MOD;
	}
	if(expr[l]==expr[r]) {
		int a=solvesamenumb(l,numbend[numb[l]]);
		int b=solvesameterm(numb[l]+1,termend[term[l]]);
		int c=solvesameexpr(term[l]+1,term[r]-1);
		int d=solvesameterm(termstart[term[r]],numb[r]-1);
		int e=solvesamenumb(numbstart[numb[r]],r);
		return ((ll)a*b+c+(ll)d*e)%MOD;
	}
	return -1;
}

void run() {
	scanf("%s",s); n=strlen(s);
	memset(match,-1,sizeof(match)); nstck=0; REP(i,n) if(s[i]=='(') stck[nstck++]=i; else if(s[i]==')') assert(nstck>0),match[i]=stck[nstck-1],match[stck[nstck-1]]=i,--nstck; assert(nstck==0);
	memset(numb,-1,sizeof(numb)); memset(term,-1,sizeof(term)); memset(expr,-1,sizeof(expr)); nnumb=nterm=nexpr=0;
	for(int i=n-1;i>=0;--i) if(s[i]=='(') { int at=i+1; parseexpr(at); assert(at==match[i]); }
	{ int at=0; parseexpr(at); assert(at==n); }
	//REP(i,n) printf("%c",expr[i]!=-1?'0'+expr[i]:s[i]); puts("");
	//REP(i,n) printf("%c",term[i]!=-1?'0'+term[i]:s[i]); puts("");
	//REP(i,n) printf("%c",numb[i]!=-1?'0'+numb[i]:s[i]); puts("");
	//REP(i,nexpr) printf("expr%d=%d\n",i,exprval[i]);
	//REP(i,nterm) printf("term%d=%d\n",i,termval[i]);
	//REP(i,nnumb) printf("numb%d=%d\n",i,numbval[i]);

	p10[0]=1; REP(i,n) p10[i+1]=(ll)10*p10[i]%MOD;
	digsum[0]=0; REP(i,n) digsum[i+1]=((ll)10*digsum[i]+(isdigit(s[i])?s[i]-'0':0))%MOD;
	zerosum[0]=0; REP(i,nnumb) zerosum[i+1]=zerosum[i]+(numbval[i]==0?1:0);
	numbprod[0]=1; REP(i,nnumb) numbprod[i+1]=(ll)numbprod[i]*(numbval[i]==0?1:numbval[i])%MOD;
	termsum[0]=0; REP(i,nterm) termsum[i+1]=(termsum[i]+termval[i])%MOD;

	scanf("%d",&nq);
	REP(qi,nq) {
		int l,r; scanf("%d%d",&l,&r); --l,--r;
		printf("%d\n",solve(l,r));
	}
}

int main() {
	run();
	return 0;
}
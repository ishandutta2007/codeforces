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

const int MAXSIZE=250;
const int MAXID=(MAXSIZE+1)*MAXSIZE;
const int MOD=1000000007;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void dec(int &a,int b) { inc(a,MOD-b); }
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
int calcinv(int x) { assert(x!=0); return pw(x,MOD-2); }


int ssize,spos,mxsz;

int inv[MAXSIZE+1];

struct Eq { vector<int> coef; Eq() {} Eq(int nvar) { coef=vector<int>(nvar+1); } };
Eq operator+(const Eq &a,const Eq &b) { assert(SZ(a.coef)==SZ(b.coef)); Eq ret=a; REPSZ(i,b.coef) inc(ret.coef[i],b.coef[i]); return ret; }
Eq operator-(const Eq &a,const Eq &b) { assert(SZ(a.coef)==SZ(b.coef)); Eq ret=a; REPSZ(i,b.coef) dec(ret.coef[i],b.coef[i]); return ret; }
Eq operator*(const Eq &a,const int &b) { Eq ret=a; REPSZ(i,ret.coef) ret.coef[i]=(ll)ret.coef[i]*b%MOD; return ret; }

Eq eq[MAXSIZE+1][MAXSIZE+1];
Eq sumup[MAXSIZE+1][MAXSIZE+1];
Eq sumlt[MAXSIZE+1][MAXSIZE+1];

vector<Eq> eqs;
void gauss() {
	int R=SZ(eqs),C=SZ(eqs[0].coef),r=0,c=0;
	while(r<R) {
		{ int rr=r; while(rr<R&&eqs[rr].coef[c]==0) ++rr; if(rr>=R) { ++c; continue; } swap(eqs[r],eqs[rr]); assert(eqs[r].coef[c]!=0); }
		eqs[r]=eqs[r]*calcinv(eqs[r].coef[c]);
		REP(rr,R) if(rr!=r) eqs[rr]=eqs[rr]-eqs[r]*eqs[rr].coef[c];
		++r,++c;
	}
}

int solve() {
	if(spos==0||spos==ssize-1) return ssize;
	inv[1]=1; FORE(i,2,mxsz) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	int nvar=mxsz-2;
	REPE(j,mxsz-1) { eq[0][j]=Eq(nvar); inc(eq[0][j].coef[nvar],j+1); }
	FORE(i,1,mxsz-1) { eq[i][0]=Eq(nvar); inc(eq[i][0].coef[nvar],i+1); }
	FORE(j,1,mxsz-2) { eq[1][j]=Eq(nvar); inc(eq[1][j].coef[j-1],1); }
	eqs.clear();
	REPE(i,mxsz-1) REPE(j,mxsz-1-i) {
		sumup[i][j]=i==0?Eq(nvar):sumup[i-1][j]+eq[i-1][j];
		sumlt[i][j]=j==0?Eq(nvar):sumlt[i][j-1]+eq[i][j-1];
		if(i==0||j==0) continue;
		//printf("using (%d,%d) ",i,j); if(i+1+j<=mxsz-1) printf(" to calculate (%d,%d)",i+1,j); else printf(" as an equation"); puts("");
		int pbreak=(ll)(i+j+1)*inv[mxsz]%MOD,pinsert=(1+MOD-pbreak)%MOD;
		Eq cur=eq[i][j];
		//printf("(%d,%d):",i,j); REPE(k,nvar) printf(" %d",cur.coef[k]); puts("");
		cur=cur-(sumup[i][j]+sumlt[i][j])*((ll)pbreak*inv[i+j]%MOD);
		if(i+j+1<=mxsz-1) {
			cur=cur-eq[i][j+1]*((ll)pinsert*(j+1)%MOD*inv[i+j+2]%MOD);
			cur=cur*calcinv((ll)pinsert*(i+1)%MOD*inv[i+j+2]%MOD);
			eq[i+1][j]=cur;
		} else {
			//printf("eq:"); REPE(k,nvar) printf(" %d",cur.coef[k]); puts("");
			eqs.PB(cur);
		}
	}
	assert(SZ(eqs)==nvar);
	gauss();
	//REPSZ(i,eqs) { printf("eq%d:",i); REPE(k,nvar) printf(" %d",eqs[i].coef[k]); puts(""); }
	REP(i,nvar) assert(eqs[i].coef[i]==1);
	vector<int> vals(nvar); REP(i,nvar) vals[i]=(MOD-eqs[i].coef[nvar])%MOD; vals.PB(1);
	//printf("vals:"); REP(i,nvar) printf(" %d",vals[i]); puts("");
	int ret=0; REPE(k,nvar) inc(ret,(ll)vals[k]*eq[spos][ssize-spos-1].coef[k]%MOD); return ret;
}

void run() {
	scanf("%d%d%d",&ssize,&spos,&mxsz); --spos;
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
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

const int MAXN=100000;
const int MAXQ=100000;
const int MINVAL=-100001;
const int MAXVAL=+100001;
const int MAXVALS=MAXVAL-MINVAL+1;
const int MAXS=4*MAXVALS;

int n,nq;
int a[MAXN];
char qop[MAXQ]; int qx[MAXQ];
int ans[MAXN];

bool slazytoggle[MAXS];
int sval[MAXS];

void sapplytoggle(int x) {
	if(sval[x]!=-1) sval[x]=1-sval[x]; else slazytoggle[x]=!slazytoggle[x];
}
void sapplyval(int x,int val) {
	slazytoggle[x]=false; sval[x]=val;
}
void spush(int x) {
	if(slazytoggle[x]) sapplytoggle(2*x+1),sapplytoggle(2*x+2),slazytoggle[x]=false;
	if(sval[x]!=-1) sapplyval(2*x+1,sval[x]),sapplyval(2*x+2,sval[x]),sval[x]=-1;
}

void sset(int x,int l,int r,int L,int R,bool VAL) {
	if(L<=l&&r<=R) {
		sapplyval(x,VAL?1:0);
	} else {
		int m=l+(r-l)/2;
		spush(x);
		if(L<=m) sset(2*x+1,l,m,L,R,VAL);
		if(m+1<=R) sset(2*x+2,m+1,r,L,R,VAL);
	}
}
void stoggle(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		sapplytoggle(x);
	} else {
		int m=l+(r-l)/2;
		spush(x);
		if(L<=m) stoggle(2*x+1,l,m,L,R);
		if(m+1<=R) stoggle(2*x+2,m+1,r,L,R);
	}
}
bool sget(int x,int l,int r,int IDX) {
	if(l==r) {
		assert(sval[x]!=-1); return sval[x]==1;
	} else {
		int m=l+(r-l)/2;
		spush(x);
		return IDX<=m?sget(2*x+1,l,m,IDX):sget(2*x+2,m+1,r,IDX);
	}
}
void sset(int l,int r,bool val) { sset(0,MINVAL,MAXVAL,l,r,val); }
void stoggle(int l,int r) { stoggle(0,MINVAL,MAXVAL,l,r); }
bool sget(int idx) { return sget(0,MINVAL,MAXVAL,idx); }

void solve() {
	slazytoggle[0]=false,sval[0]=0;
	REP(i,nq) {
		char op=qop[i]; int x=qx[i];
		if(op=='<') {
			if(x<=0) {
				sset(MINVAL,x-1,true);
				sset(-x+1,MAXVAL,false);
			} else {
				sset(MINVAL,-x,true);
				stoggle(-x+1,x-1);
				sset(x,MAXVAL,false);
			}
		}
		if(op=='>') {
			if(x>=0) {
				sset(MINVAL,-x-1,false);
				sset(x+1,MAXVAL,true);
			} else {
				sset(MINVAL,x,false);
				stoggle(x+1,-x-1);
				sset(-x,MAXVAL,true);
			}
		}
	}
	REP(i,n) ans[i]=sget(a[i])?-a[i]:a[i];
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,nq) scanf(" %c%d",&qop[i],&qx[i]);
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}
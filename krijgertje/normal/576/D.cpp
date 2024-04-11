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

const int MAXN=150;
const int MAXM=150;
const int BITSZ=50;
const int NBIT=(MAXM+BITSZ-1)/BITSZ;

typedef ull Mat[MAXN][NBIT];
typedef struct F { int a,b,d; } F;
bool operator<(const F &p,const F &q) { return p.d<q.d; }

int n;

void zero(Mat &A) { REP(i,n) REP(j,NBIT) A[i][j]=0; }
void setbit(Mat &A,int i,int j) { A[i][j/BITSZ]|=1LL<<(j%BITSZ); }
bool isset(const Mat &A,int i,int j) { return ((A[i][j/BITSZ]>>(j%BITSZ))&1)!=0; }
void ident(Mat &A) { zero(A); REP(i,n) setbit(A,i,i); }
void copy(Mat &A,const Mat &B) { REP(i,n) REP(j,NBIT) A[i][j]=B[i][j]; }
void trans(Mat &A,const Mat &B) { zero(A); REP(i,n) REP(j,n) if(isset(B,i,j)) setbit(A,j,i); }
void mmult(Mat &A,const Mat &B) {
	Mat C,D; copy(C,A); trans(D,B); zero(A);
	REP(i,n) REP(j,n) REP(k,NBIT) if((C[i][k]&D[j][k])!=0) { setbit(A,i,j); break; }
}
void mpow(Mat &A,const Mat &B,int k) {
	Mat C; copy(C,B);
	while(true) {
		if((k&1)!=0) mmult(A,C);
		if((k>>=1)==0) break;
		mmult(C,C);
	}
}

int m;
F f[MAXM];

int q[MAXN],qhead,qtail;
int cd[MAXN];

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].d); --f[i].a,--f[i].b; }
	sort(f,f+m);

	Mat one; zero(one);
	Mat cur; ident(cur);

	int at=0,ret=INT_MAX;
	//REP(i,n) { REP(j,n) printf("%c",isset(cur,i,j)?'V':'.'); printf(" "); REP(j,n) printf("%c",isset(one,i,j)?'V':'.'); puts(""); }
	while(at<m) {
		int to=at; while(to<m&&f[at].d==f[to].d) ++to;
		mpow(cur,one,f[at].d-(at==0?0:f[at-1].d));
		FOR(i,at,to) setbit(one,f[i].a,f[i].b);
		//printf("at %d:\n",f[at].d);	REP(i,n) { REP(j,n) printf("%c",isset(cur,i,j)?'V':'.'); printf(" "); REP(j,n) printf("%c",isset(one,i,j)?'V':'.'); puts(""); }
		REP(i,n) cd[i]=-1;
		qhead=qtail=0; q[qhead++]=n-1; cd[n-1]=0;
		while(qtail<qhead) {
			int cat=q[qtail++];
			if(isset(cur,0,cat)&&f[at].d+cd[cat]<ret) ret=f[at].d+cd[cat];
			REP(cto,n) if(cd[cto]==-1&&isset(one,cto,cat)) { cd[cto]=cd[cat]+1; q[qhead++]=cto; }
		}
		at=to;
	}
	if(ret==INT_MAX) printf("Impossible\n"); else printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
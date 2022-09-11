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

const int MAXN=10000;
const int MOD=1000000007;
typedef int Mat[3][3];
struct E { int x; ll y; int kind; E() {} E(int x,ll y,int kind):x(x),y(y),kind(kind) {} };
bool operator<(const E &a,const E &b) { if(a.y!=b.y) return a.y<b.y; return false; }

void mmlt(Mat A,Mat B) {
	Mat _A;
	REP(i,3) REP(j,3) { ll cur=0; REP(k,3) cur+=(ll)A[i][k]*B[k][j]; _A[i][j]=cur%MOD; }
	REP(i,3) REP(j,3) A[i][j]=_A[i][j];
}

void mpw(Mat _A,ll n,Mat B) {
	Mat A; REP(i,3) REP(j,3) A[i][j]=_A[i][j];
	REP(i,3) REP(j,3) B[i][j]=i==j?1:0;
	while(true) { if(n&1) mmlt(B,A); if((n>>=1)==0) return; mmlt(A,A); }
}


int n; ll w;

E e[2*MAXN]; int ne;

int ways[3];
int blockcnt[3];

Mat A;
Mat B;
int nways[3];


void proceed(ll steps) {
	REP(i,3) REP(j,3) A[i][j]=abs(i-j)<=1&&blockcnt[j]==0?1:0;
	mpw(A,steps,B);
	//printf("proceed(%lld)\n",steps); REP(i,3) { REP(j,3) printf("%d ",B[i][j]); puts(""); }
	REP(i,3) nways[i]=0; REP(i,3) REP(j,3) nways[j]=(nways[j]+(ll)ways[i]*B[i][j])%MOD; REP(i,3) ways[i]=nways[i];
}

void run() {
	scanf("%d%lld",&n,&w); REP(i,n) { int x; ll ly,hy; scanf("%d%lld%lld",&x,&ly,&hy); --x; e[ne++]=E(x,ly,+1); e[ne++]=E(x,hy+1,-1); }

	sort(e,e+ne);
	int ei=0; blockcnt[0]=blockcnt[1]=blockcnt[2]=0; ways[0]=0,ways[1]=1,ways[2]=0; ll y=1;
	while(y<w) {
		ll ny=ei<ne?e[ei].y:w;
		assert(ny>y);
		if(ny!=y+1) proceed(ny-y-1),y+=ny-y-1;
		while(ei<ne&&e[ei].y==ny) blockcnt[e[ei].x]+=e[ei].kind,++ei;
		proceed(1),++y;
	}
	printf("%d\n",ways[1]);
}

int main() {
	run();
	return 0;
}
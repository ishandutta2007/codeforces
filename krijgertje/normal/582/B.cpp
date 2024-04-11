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

const int MAXN=100;

int n,k;
int a[MAXN];


int x[MAXN],nx;
int one[MAXN][MAXN];

int s[MAXN],t[MAXN];


void run() {
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d",&a[i]);

	nx=0; REP(i,n) x[nx++]=a[i];
	sort(x,x+nx);
	nx=unique(x,x+nx)-x;
	//printf("x:"); REP(i,nx) printf(" %d",x[i]); puts("");

	memset(one,0,sizeof(one));
	REP(i,n) {
		int at=0; while(x[at]<a[i]) ++at; assert(x[at]==a[i]);
		REP(j,nx) for(int k=at;k>=j;--k) if(one[j][k]+1>one[j][at]) one[j][at]=one[j][k]+1;
		REP(j,nx) REP(k,nx-1) if(one[j][k]>one[j][k+1]) one[j][k+1]=one[j][k];
	}
	//REP(i,nx) { REP(j,nx) printf("%3d",one[i][j]); puts(""); }

	memset(s,0,sizeof(s)); memset(t,0,sizeof(t));
	int k1=k/2,k2=k-k1; if(k1>nx) k1=nx; if(k2>nx) k2=nx;
	REP(kk,k1) for(int i=nx-1;i>=0;--i) { int nval=0; REPE(j,i) if(s[j]+one[j][i]>nval) nval=s[j]+one[j][i]; s[i]=nval; }
	REP(kk,k2) REP(i,nx) { int nval=0; FOR(j,i,nx) if(one[i][j]+t[j]>nval) nval=one[i][j]+t[j]; t[i]=nval; }
	//printf("s%d:",k1); REP(i,nx) printf(" %d",s[i]); puts("");
	//printf("t%d:",k2); REP(i,nx) printf(" %d",t[i]); puts("");

	int ret=0;
	REP(i,nx) { int cur=s[i]+(k-k1-k2)*one[i][i]+t[i]; if(cur>ret) ret=cur; }
	printf("%d\n",ret);
}


int main() {
	run();
	return 0;
}
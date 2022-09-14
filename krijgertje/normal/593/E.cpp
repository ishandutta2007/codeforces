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

const int MAXN=20;
const int MOD=1000000007;
const int DX[]={-1,0,+1,0,0},DY[]={0,+1,0,-1,0};
typedef int Mat[MAXN][MAXN];

int h,w,n,nq;
Mat trans;
Mat cur;

void mmult(Mat &A,const Mat &B,const Mat &C) {
	REP(i,n) REP(j,n) { ll cur=0; REP(k,n) cur+=(ll)B[i][k]*C[k][j]%MOD; A[i][j]=cur%MOD; }
}

void mmult(Mat &A,const Mat &B,int k) {
	//REP(i,n) { REP(j,n) printf("%12d",A[i][j]); puts(""); } printf("*\n"); REP(i,n) { REP(j,n) printf("%2d",B[i][j]); puts(""); } printf("^%d\n",k); puts("");
	Mat C,D; REP(i,n) REP(j,n) C[i][j]=B[i][j];
	for(;k>0;k>>=1) {
		REP(i,n) REP(j,n) D[i][j]=A[i][j];
		if(k&1) mmult(A,D,C);
		REP(i,n) REP(j,n) D[i][j]=C[i][j];
		mmult(C,D,D);
	}
}

void run() {
	scanf("%d%d%d",&h,&w,&nq); n=h*w;
	memset(trans,0,sizeof(trans));
	memset(cur,0,sizeof(cur));
	cur[0][0]=1;
	REP(x,h) REP(y,w) REP(k,5) {
		int nx=x+DX[k],ny=y+DY[k];
		if(nx<0||nx>=h||ny<0||ny>=w) continue;
		trans[nx*w+ny][x*w+y]=1;
	}

	int t=1;
	REP(qi,nq) {
		int type,x,y,nt; scanf("%d%d%d%d",&type,&x,&y,&nt); --x,--y;
		mmult(cur,trans,nt-t); t=nt;
		if(type==1) printf("%d\n",cur[0][x*w+y]);
		if(type==2) REP(i,n) cur[i][x*w+y]=0;
		if(type==2||type==3) REP(k,5) {
			int nx=x+DX[k],ny=y+DY[k];
			if(nx<0||nx>=h||ny<0||ny>=w) continue;
			trans[nx*w+ny][x*w+y]=type==2?0:1;
		}
	}
	
}

int main() {
	run();
	return 0;
}
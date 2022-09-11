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

const int MAXN=300000;
const int MAXQ=300000;
const int MAXBIT=18;

int n,nq;
int a[MAXN];
int qx[MAXQ],qy[MAXQ]; bool qans[MAXQ];

int nxtwithbit[MAXN+1][MAXBIT+1];
int shortestpathtobit[MAXN+1][MAXBIT+1];
void upd(int &a,int b) { a=min(a,b); }


void solve() {
	REPE(k,MAXBIT) nxtwithbit[n][k]=n;
	for(int i=n-1;i>=0;--i) REPE(k,MAXBIT) nxtwithbit[i][k]=(a[i]&(1<<k))!=0?i:nxtwithbit[i+1][k];
	//REPE(i,n) REPE(k,MAXBIT) if(nxtwithbit[i][k]!=n) printf("nxtwithbit[%d][%d]=%d\n",i,k,nxtwithbit[i][k]);

	REPE(k,MAXBIT) shortestpathtobit[n][k]=n;
	for(int i=n-1;i>=0;--i) {
		REPE(k,MAXBIT) shortestpathtobit[i][k]=n;
		REPE(k,MAXBIT) if((a[i]&(1<<k))!=0) {
			upd(shortestpathtobit[i][k],i);
			REPE(kk,MAXBIT) upd(shortestpathtobit[i][kk],shortestpathtobit[nxtwithbit[i+1][k]][kk]);
		}
	}
	//REPE(i,n) REPE(k,MAXBIT) if(shortestpathtobit[i][k]!=n) printf("shortestpathtobit[%d][%d]=%d\n",i,k,shortestpathtobit[i][k]);

	REP(i,nq) {
		qans[i]=false; int x=qx[i],y=qy[i];
		REPE(k,MAXBIT) if((a[y]&(1<<k))!=0&&shortestpathtobit[x][k]<=y) qans[i]=true;
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,nq) scanf("%d%d",&qx[i],&qy[i]),--qx[i],--qy[i];
	solve();
	REP(i,nq) printf("%s\n",qans[i]?"Shi":"Fou");
}

void stress() {
	REP(rep,100) {
		n=MAXN,nq=MAXQ;
		REP(i,n) a[i]=rand()%300000;
		REP(i,nq) while(true) { qx[i]=rand()%n,qy[i]=rand()%n; if(qx[i]>qy[i]) swap(qx[i],qy[i]); if(qx[i]==qy[i]) continue; else break; }
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}
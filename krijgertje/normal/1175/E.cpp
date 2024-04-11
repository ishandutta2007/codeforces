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

const int MAXSEG=200000;
const int MAXQ=200000;
const int MAXVAL=500000;
const int MAXLG=18;
struct Seg { int l,r; };

int nseg,nq;
Seg seg[MAXSEG];
int ql[MAXQ],qr[MAXQ],qans[MAXQ];

int mx[MAXVAL+1];
int jump[MAXVAL+1][MAXLG+1];

void upd(int &a,int b) { a=max(a,b); }
void solve() {
	REPE(i,MAXVAL) mx[i]=i;
	REP(i,nseg) upd(mx[seg[i].l],seg[i].r);
	FORE(i,1,MAXVAL) upd(mx[i],mx[i-1]);
	REPE(i,MAXVAL) jump[i][0]=mx[i];
	REP(k,MAXLG) REPE(i,MAXVAL) jump[i][k+1]=jump[jump[i][k]][k];
	REP(i,nq) {
		int l=ql[i],r=qr[i]; int x=l; qans[i]=0;
		for(int k=MAXLG;k>=0;--k) if(jump[x][k]<r) x=jump[x][k],qans[i]+=1<<k;
		if(mx[x]<r) qans[i]=-1; else ++qans[i];
	}
}

void run() {
	scanf("%d%d",&nseg,&nq);
	REP(i,nseg) scanf("%d%d",&seg[i].l,&seg[i].r);
	REP(i,nq) scanf("%d%d",&ql[i],&qr[i]);
	solve();
	REP(i,nq) printf("%d\n",qans[i]);

}

int main() {
	run();
	return 0;
}
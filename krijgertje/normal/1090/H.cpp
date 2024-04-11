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

const int MAXLEN=200000;
const int MAXQ=200000;
const int MAXLG=17;
const int MAXY=MAXLG*(MAXLEN-1);

int tlen; char t[MAXLEN+1];
int nq;
int ql[MAXQ],qr[MAXQ],qans[MAXQ];

int x[MAXLEN-1];

int pos[MAXLEN-1][MAXLG+1],npos;
int y[MAXY];
int ysum[MAXY+1];

void solve() {
	REP(i,tlen-1) x[i]=(t[i]-'0')^(t[i+1]-'0');
	//printf("x: "); REP(i,tlen-1) printf("%d",x[i]); puts("");

	npos=0;
	for(int j=1;;++j) {
		int jump=1<<j;
		if(jump+1>tlen-1) break;
		REP(offset,jump) for(int k=offset;k<tlen-1;k+=jump) y[npos]=x[k],pos[k][j]=npos++;
	}
	//printf("y: "); REP(i,npos) printf("%d",y[i]); puts("");
	ysum[0]=0; REP(i,npos) ysum[i+1]=ysum[i]+y[i];

	REP(i,nq) {
		int nchanges=0;
		for(int j=1;;++j) {
			int jump=1<<j,offset=ql[i]+jump/2-1;
			if(offset+jump+1>qr[i]) break;
			int lim=(qr[i]-offset)/jump;
			int len=lim+1,none=ysum[pos[offset][j]+lim+1]-ysum[pos[offset][j]],nzero=len-none;
			//printf("q%d: testing (%d..%d) -> %d/%d:",i,pos[offset][j],pos[offset][j]+lim,nzero,none); for(int k=offset;k+1<=qr[i];k+=jump) printf(" %d",k); puts("");
			nchanges+=min(nzero,none);
		}
		qans[i]=(nchanges+1)/2;
	}
}

void run() {
	scanf("%d",&tlen);
	scanf("%s",t);
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d",&ql[i],&qr[i]);
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}
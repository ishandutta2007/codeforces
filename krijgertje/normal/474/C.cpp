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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

void rotate(int &x,int &y,int cx,int cy) {
	int dx=x-cx,dy=y-cy;
	x=cx-dy,y=cy+dx;
}

int nq;
int n;
int sx[4],sy[4],cx[4],cy[4],tx[4],ty[4];
int moves[4];

bool issquare() {
	int xx=0,yy=0; REP(i,4) xx+=tx[i],yy+=ty[i];
	int used=0;
	int x=tx[0]*4,y=ty[0]*4; used|=1<<0;
	if(x==xx&&y==yy) return false;
	REP(i,3) {
		rotate(x,y,xx,yy);
		bool found=false; REP(j,4) if((used&(1<<j))==0&&tx[j]*4==x&&ty[j]*4==y) { found=true; used|=1<<j; break; }
		if(!found) return false;
	}
	return true;
}


void run() {
	scanf("%d",&nq);
	REP(qi,nq) {
		n=4; REP(i,n) scanf("%d%d%d%d",&sx[i],&sy[i],&cx[i],&cy[i]);
		int ret=INT_MAX;
		REP(a,4) REP(b,4) REP(c,4) REP(d,4) {
			moves[0]=a; moves[1]=b; moves[2]=c; moves[3]=d;
			REP(i,n) { tx[i]=sx[i],ty[i]=sy[i]; REP(j,moves[i]) rotate(tx[i],ty[i],cx[i],cy[i]); }
			if(!issquare()) continue;
			int cur=a+b+c+d; if(cur<ret) ret=cur;
		}
		printf("%d\n",ret==INT_MAX?-1:ret);
	}
}

int main() {
	run();
	return 0;
}
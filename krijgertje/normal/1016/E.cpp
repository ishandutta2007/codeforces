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

const int MAXN=200000;
struct P { int x,y; P(int x,int y):x(x),y(y) {} };
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }

int ay,alx,arx;
int n;
int bl[MAXN],br[MAXN];
int nq;
int qx[MAXN],qy[MAXN];

int bsum[MAXN+1];

int calcside(int ax,int ay,int bx,int by,int cx,int cy) {
	P a(ax,ay),b(bx,by),c(cx,cy);
	//printf("calcside(%d,%d)-(%d,%d) ? (%d,%d)\n",ax,ay,bx,by,cx,cy);
	ll res=(c-a)^(b-a);
	return res<0?-1:res>0?+1:0;
}

double calc(int i) {
	int l=-1,r=n; // (l,r]
	while(l+1<r) {
		int m=l+(r-l)/2;
		int side=calcside(alx,ay,qx[i],qy[i],br[m],0);
		//printf("left %d: side=%d\n",m,side);
		if(side>=0) r=m; else l=m;
	}
	int fst=r;
	l=-1,r=n; // (l,r]
	while(l+1<r) {
		int m=l+(r-l)/2;
		int side=calcside(arx,ay,qx[i],qy[i],bl[m],0);
		if(side<=0) l=m; else r=m;
	}
	int lst=l;
	//printf("fst=%d lst=%d\n",fst,lst);
	if(fst>lst) return 0;

	bool fstpart=calcside(alx,ay,qx[i],qy[i],bl[fst],0)<0;
	bool lstpart=calcside(arx,ay,qx[i],qy[i],br[lst],0)>0;
	if(fst==lst&&fstpart&&lstpart) return arx-alx;

	double ret=0;
	if(fstpart) { double x=qx[i]+1.0*(qy[i]-ay)*(br[fst]-qx[i])/qy[i]; ret+=x-alx; ++fst; }
	if(lstpart) { double x=qx[i]+1.0*(qy[i]-ay)*(bl[lst]-qx[i])/qy[i]; ret+=arx-x; --lst; }
	int mid=bsum[lst+1]-bsum[fst];
	ret+=1.0*mid*(qy[i]-ay)/qy[i];
	return ret;
}

void run() {
	scanf("%d%d%d",&ay,&alx,&arx);
	scanf("%d",&n); REP(i,n) scanf("%d%d",&bl[i],&br[i]);
	scanf("%d",&nq); REP(i,nq) scanf("%d%d",&qx[i],&qy[i]);

	bsum[0]=0; REP(i,n) bsum[i+1]=bsum[i]+br[i]-bl[i];
	REP(i,nq) {
		double ans=calc(i);
		printf("%.15lf\n",ans);
	}


}

int main() {
	run();
	return 0;
}
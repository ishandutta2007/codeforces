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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

int n;
int px[100000];
int py[100000];

int xi[100000];
int yi[100000];
bool xcmp(const int &a,const int &b) { return px[a]<px[b]; }
bool ycmp(const int &a,const int &b) { return py[a]<py[b]; }

bool cd[100000];
bool ac[100000];
bool ab[100000];
bool bd[100000];
int cnta,cntb,cntc,cntd;


void run(int casenr) {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&px[i],&py[i]);

	REP(i,n) xi[i]=i; sort(xi,xi+n,xcmp);
	REP(i,n) yi[i]=i; sort(yi,yi+n,ycmp);

	memset(cd,false,sizeof(cd)); REP(i,n/2) cd[yi[i]]=true;
	memset(ac,false,sizeof(ac)); REP(i,n/2) ac[xi[i]]=true;
	memset(ab,false,sizeof(ab)); REP(i,n/2) ab[yi[n-i-1]]=true;
	memset(bd,false,sizeof(bd)); REP(i,n/2) bd[xi[n-i-1]]=true;
	cnta=cntb=cntc=cntd=0;
	REP(i,n) { if(ab[i]&&ac[i]) ++cnta; if(ab[i]&&bd[i]) ++cntb; if(cd[i]&&ac[i]) ++cntc; if(cd[i]&&bd[i]) ++cntd; }

	ll base=0;
	REP(i,n) base+=2*abs(px[i]-px[xi[n/2]]);
	REP(i,n) base+=2*abs(py[i]-py[yi[n/2]]);

//	printf("base = %lld, cnts=[%d,%d,%d,%d]\n",base,cnta,cntb,cntc,cntd);
//	REP(i,n) printf("xorder %d = %d = (%d,%d)\n",i,xi[i],px[xi[i]],py[xi[i]]);
//	REP(i,n) printf("yorder %d = %d = (%d,%d)\n",i,yi[i],px[yi[i]],py[yi[i]]);

	if(n%2==0) {
		/* y  a | b		#a==#d	path if #d==0 -> (bc)+ [all optimal] -> cost = 0
		 * ^ ---+---	#b==#c	path if #c==0 -> (ad)+ [all optimal] -> cost = 0
		 * |  c | d				path	(ad)+(bc)+ [nonoptimal edges db and ca]	-> cost = 2*deltax
		 * +->x						 or	(ad)+(cb)+ [nonoptimal edges dc and ba]	-> cost = 2*deltay
		 */
		int cost=0;
		if(cnta>0&&cntb>0) {
			cost=2*min(px[xi[n/2]]-px[xi[n/2-1]],py[yi[n/2]]-py[yi[n/2-1]]);
//			printf("cost = min(%d-%d,%d-%d) = min(%d,%d) = %d\n",px[xi[n/2]],px[xi[n/2-1]],py[yi[n/2]],py[yi[n/2-1]],px[xi[n/2]]-px[xi[n/2-1]],py[yi[n/2]]-py[yi[n/2-1]],cost);
		}
		cout<<base-cost<<endl;
	} else if(xi[n/2]!=yi[n/2]) {
		/*    a | e | b		(or symetric)
		 *   ---+---+---	#d=#a+1		path (da)*de(cb)*f [all optimal] -> cost = 0
		 * y  f | 0 | 0		#b=#c
		 * ^ ---+---+---	#e=#f=1
		 * |  c | 0 | d		
		 * +->x
		 */
		cout<<base<<endl;
	} else {
		/*    a | 0 | b		#d=#a		path if #d==0 (bc)*e [all optimal] -> cost = 0
		 *   ---+---+---	#b=#c		path if #c==0 (ad)*e [all optimal] -> cost = 0
		 * y  0 | e | 0		#e=1		path	(ad)+e(bc)+ [nonoptimal edge ca] -> cost = 2*deltaxleft
		 * ^ ---+---+---						(ad)+e(cb)+ [nonoptimal edge ba] -> cost = 2*deltayup
		 * |  c | 0 | d							(da)+e(bc)+ [nonoptimal edge cd] -> cost = 2*deltaydown
		 * +->x									(da)+e(cb)+ [nonoptimal edge bd] -> cost = 2*deltaxright
		 */
		int cost=0;
		if(cnta>0&&cntb>0) cost=2*min(min(px[xi[n/2]]-px[xi[n/2-1]],px[xi[n/2+1]]-px[xi[n/2]]),min(py[yi[n/2]]-py[yi[n/2-1]],py[yi[n/2+1]]-py[yi[n/2]]));
		cout<<base-cost<<endl;
	}
}

int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
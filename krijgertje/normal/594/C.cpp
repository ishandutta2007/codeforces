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

const int MAXN=100000;
const int MAXK=10;
typedef struct R { int lx,ly,hx,hy,cx,cy; } R;

int n,k;
R r[MAXN];
int mark[MAXN],curmark;
int ox[MAXN]; bool xcmp(int a,int b) { return r[a].cx<r[b].cx; }
int oy[MAXN]; bool ycmp(int a,int b) { return r[a].cy<r[b].cy; }


void run() {
	scanf("%d%d",&n,&k); REP(i,n) scanf("%d%d%d%d",&r[i].lx,&r[i].ly,&r[i].hx,&r[i].hy);
	REP(i,n) r[i].cx=r[i].lx+r[i].hx,r[i].cy=r[i].ly+r[i].hy;

	REP(i,n) ox[i]=i; sort(ox,ox+n,xcmp);
	REP(i,n) oy[i]=i; sort(oy,oy+n,ycmp);

	memset(mark,-1,sizeof(mark)); curmark=-1; ll ret=LLONG_MAX;
	REPE(a,k) REPE(b,k-a) REPE(c,k-a-b) {
		int d=k-a-b-c; ++curmark;
		int aa,bb,cc,dd,left;
		for(aa=0,left=a;aa<n&&left>0;++aa) if(mark[ox[aa]]!=curmark) mark[ox[aa]]=curmark,--left;
		for(bb=n-1,left=b;bb>=0&&left>0;--bb) if(mark[ox[bb]]!=curmark) mark[ox[bb]]=curmark,--left;
		for(cc=0,left=c;cc<n&&left>0;++cc) if(mark[oy[cc]]!=curmark) mark[oy[cc]]=curmark,--left;
		for(dd=n-1,left=d;dd>=0&&left>0;--dd) if(mark[oy[dd]]!=curmark) mark[oy[dd]]=curmark,--left;
		while(aa<n&&mark[ox[aa]]==curmark) ++aa;
		while(bb>=0&&mark[ox[bb]]==curmark) --bb;
		while(cc<n&&mark[oy[cc]]==curmark) ++cc;
		while(dd>=0&&mark[oy[dd]]==curmark) --dd;
		assert(aa<=bb&&cc<=dd);
		int dx=(r[ox[bb]].cx-r[ox[aa]].cx+1)/2,dy=(r[oy[dd]].cy-r[oy[cc]].cy+1)/2;
		if(dx<=0) dx=1; if(dy<=0) dy=1;
		ll cur=(ll)dx*dy;
		if(cur<ret) ret=cur;
	}
	printf("%I64d\n",ret);


}

int main() {
	run();
	return 0;
}
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

typedef struct P { ll x,y; } P;
bool operator<(const P &a,const P &b) { return a.x<b.x; }

typedef struct YSORT { int i,y; } YSORT;
bool operator<(const YSORT &a,const YSORT &b) { return a.y<b.y; }

int n;
P p[100000];
YSORT ysort[100000];

int ny;
ll realy[100000];

multiset<int> have;

void inc(int y) {
	have.insert(y);
}

void dec(int y) {
	multiset<int>::iterator it=have.find(y);
	have.erase(it);
}

ll getmaxdiff() {
	if(SZ(have)==0) return 0;
	multiset<int>::iterator it=have.begin(); int y1=*it;
	it=have.end(); --it; int y2=*it;
	return realy[y2]-realy[y1];
}

void run(int casenr) {
	scanf("%d",&n);
	REP(i,n) { int xx,yy; scanf("%d%d",&xx,&yy); p[i].x=xx+yy; p[i].y=xx-yy; }
	sort(p,p+n);

	REP(i,n) { ysort[i].i=i; ysort[i].y=p[i].y; }
	sort(ysort,ysort+n);
	ny=0; REP(i,n) { if(i==0||ysort[i].y!=ysort[i-1].y) realy[ny++]=ysort[i].y; p[ysort[i].i].y=ny-1; }

//	REP(i,n) printf("(%d,%d=%d)\n",(int)p[i].x,(int)p[i].y,(int)realy[p[i].y]);

	have.clear();
	REP(i,n) inc(p[i].y);
	ll ret=getmaxdiff();

	int tail=0,head=0; // [tail,head)
	while(tail<n) {
		ll xdiff=tail==head?0:p[head-1].x-p[tail].x;
		ll ydiff=getmaxdiff();
		ll cur=max(xdiff,ydiff); if(cur<ret) ret=cur;
//		printf("%d..%d = %d / %d -> %d [%d]\n",tail==head?666:(int)p[tail].x,tail==head?666:(int)p[head-1].x,(int)xdiff,(int)ydiff,(int)cur,SZ(have));
		if(head<n&&ydiff>=xdiff) {
			dec(p[head].y); ++head;
		} else {
			inc(p[tail].y); ++tail;
		}
	}
	printf("%.1lf\n",0.5*ret);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
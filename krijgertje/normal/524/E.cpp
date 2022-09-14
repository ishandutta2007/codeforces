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

typedef struct P { int x,y; } P;
bool operator<(const P &a,const P &b) { return a.y<b.y; }
typedef struct Q { int x1,x2,y1,y2,idx; } Q;
bool operator<(const Q &a,const Q &b) { return a.y2<b.y2; }

int h,w,np,nq;
P p[200000];
Q q[200000];
bool ret[200000];

int sbase;
int sval[1<<19];

void init(int n) {
	sbase=1; while(sbase<n) sbase*=2;
	REP(i,2*sbase) sval[i]=INT_MIN;
}
void update(int pos,int val) {
	int at=sbase+pos;
	if(val>sval[at]) sval[at]=val;
	while(at!=1) {
		at=at/2;
		sval[at]=min(sval[2*at],sval[2*at+1]);
	}
}
int get(int lpos,int rpos) {
	int ret=INT_MAX,at1=sbase+lpos,at2=sbase+rpos;
	while(at1<=at2) {
		if(at1%2==1) { ret=min(ret,sval[at1]); ++at1; }
		if(at2%2==0) { ret=min(ret,sval[at2]); --at2; }
		at1/=2,at2/=2;
	}
	return ret;
}



void run() {
	scanf("%d%d%d%d",&w,&h,&np,&nq);
	REP(i,np) { scanf("%d%d",&p[i].x,&p[i].y); --p[i].x,--p[i].y; }
	REP(i,nq) { scanf("%d%d%d%d",&q[i].x1,&q[i].y1,&q[i].x2,&q[i].y2); --q[i].x1,--q[i].x2,--q[i].y1,--q[i].y2,q[i].idx=i; }
	REP(i,nq) ret[i]=false;

	REP(orient,2) {
		sort(p,p+np);
		sort(q,q+nq);
		init(w);

		int atp=0,atq=0;
		while(atq<nq) {
			while(atp<np&&p[atp].y<=q[atq].y2) { update(p[atp].x,p[atp].y); ++atp; }
			int cur=get(q[atq].x1,q[atq].x2);
			//printf("%c: %d=(%d,%d,%d,%d) -> %d\n",orient==0?'Y':'X',q[atq].idx,q[atq].x1,q[atq].x2,q[atq].y1,q[atq].y2,cur);
			if(cur>=q[atq].y1) ret[q[atq].idx]=true;
			++atq;
		}

		swap(h,w);
		REP(i,np) swap(p[i].x,p[i].y);
		REP(i,nq) swap(q[i].x1,q[i].y1),swap(q[i].x2,q[i].y2);
	}
	REP(i,nq) printf("%s\n",ret[i]?"YES":"NO");
}

int main() {
	run();
	return 0;
}
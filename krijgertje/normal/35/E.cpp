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
#include <cassert>
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

typedef struct X { int h,l,r; } X;
bool operator<(const X &a,const X &b) { if(a.l!=b.l) return a.l<b.l; return a.h>b.h; }

typedef struct Y { int h,r; } Y;
bool operator<(const Y &a,const Y &b) { if(a.h!=b.h) return a.h>b.h; return a.r<b.r; }

typedef struct P { int x,y; P(int x,int y):x(x),y(y) {} } P;

void run() {
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	
	int n; scanf("%d",&n);
	vector<X> z(n); REP(i,n) scanf("%d%d%d",&z[i].h,&z[i].l,&z[i].r);
	sort(z.begin(),z.end());
	//REP(i,n) printf("%d %d %d\n",z[i].h,z[i].l,z[i].r);
	
	int at=0; int h=0;
	set<Y> have;
	vector<P> ret;
	while(at<n||SZ(have)>0) {
		if(SZ(have)==0||at<n&&z[at].l<=have.begin()->r) {
			//printf("add %d\n",at);
			int x=z[at].l;
			have.insert((Y){z[at].h,z[at].r});
			if(z[at].h>h) {
				ret.PB(P(x,h));
				ret.PB(P(x,z[at].h));
				h=z[at].h;
			}
			++at;
		} else {
			int x=have.begin()->r;
			//for(set<Y>::iterator j=have.begin();j!=have.end();++j) printf("\t%d %d\n",j->h,j->r);
			while(SZ(have)>0&&have.begin()->r<=x) have.erase(have.begin());
			int nh=SZ(have)==0?0:have.begin()->h;
			//printf("%d,%d -> %d\n",x,h,nh);
			if(h!=nh) {
				ret.PB(P(x,h));
				ret.PB(P(x,nh));
				h=nh;
			}
		}
	}
	printf("%d\n",SZ(ret));
	REPSZ(i,ret) printf("%d %d\n",ret[i].x,ret[i].y);
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
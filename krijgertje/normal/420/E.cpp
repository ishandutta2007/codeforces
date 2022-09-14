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

typedef struct E { double ang; int by; } E;
bool operator<(const E &a,const E &b) { return a.ang<b.ang; }

const double PI=atan(1)*4,eps=1e-9;
int ncircle,step;

E evt[4000000]; int nevt;
void addevt(double ang,int by) { evt[nevt].ang=ang; evt[nevt].by=by; ++nevt; }

void run() {
	scanf("%d%d",&ncircle,&step);
	nevt=0;
	REP(i,ncircle) {
		int x,y,r; scanf("%d%d%d",&x,&y,&r);
		int dd=x*x+y*y;
		double d=sqrt(1.0*dd),ang=atan2(y,x); while(ang<0) ang+=2*PI;
		int times=(int)floor((d-r)/step); if(times<=0) times=1;
		while((times*step-r)*(times*step-r)<=dd) {
			//printf("(%d,%d) -> %d times\n",x,y,times);
			if((times*step+r)*(times*step+r)<dd) { ++times; continue; }
			int cr=times*step;
			if((cr+r)*(cr+r)==dd||(cr-r)*(cr-r)==dd) {
				addevt(ang-eps,+1);
				addevt(ang+eps,-1);
			} else {
				double dang=acos(1.0*(cr*cr+d*d-r*r)/(2*cr*d));
				double ang1=ang-dang,ang2=ang+dang;
				while(ang1<0) { ang1+=2*PI; ang2+=2*PI; }
				addevt(ang1-eps,+1);
				while(ang2>=2*PI) { addevt(2*PI,-1); addevt(0,+1); ang2-=2*PI; }
				addevt(ang2+eps,-1);
			}
			++times;
		}
	}
	sort(evt,evt+nevt);
	//REP(i,nevt) printf("%lf: %d\n",evt[i].ang,evt[i].by);
	int ret=0,cur=0;
	REP(i,nevt) {
		cur+=evt[i].by;
		if(cur>ret) ret=cur;
	}
	printf("%d\n",ret);

}

int main() {
	run();
	return 0;
}
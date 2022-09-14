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

const int Q01=0,Q02=1,Q12=2,Q10=3,Q21=4;
int need[5]={0,0,1,1,2};
typedef struct X { int a,b,have; bool z[5]; } X;

int n,want;
X x[300000];


// opt(n)->opt(n+1): either 1 level increases 1 star, or 1 level increases 2 stars and 1 level loses a star

priority_queue<pair<int,pair<int,int> > > inc1;
priority_queue<pair<int,pair<int,int> > > inc2;
priority_queue<pair<int,pair<int,int> > > dec1;

void ensure(int i) {
	if(x[i].have==0) {
		if(!x[i].z[Q01]) { inc1.push(MP(-x[i].a,MP(i,Q01))); x[i].z[Q01]=true; }
		if(!x[i].z[Q02]) { inc2.push(MP(-x[i].a-x[i].b,MP(i,Q02))); x[i].z[Q02]=true; }
	} else if(x[i].have==1) {
		if(!x[i].z[Q12]) { inc1.push(MP(-x[i].b,MP(i,Q12))); x[i].z[Q12]=true; }
		if(!x[i].z[Q10]) { dec1.push(MP(+x[i].a,MP(i,Q10))); x[i].z[Q10]=true; }
	} else if(x[i].have==2) {
		if(!x[i].z[Q21]) { dec1.push(MP(+x[i].b,MP(i,Q21))); x[i].z[Q21]=true; }
	}
}

void run() {
	scanf("%d%d",&n,&want);
	REP(i,n) { scanf("%d%d",&x[i].a,&x[i].b); x[i].b-=x[i].a; }
	REP(i,n) x[i].have=0;
	REP(i,n) REP(j,5) x[i].z[j]=false;

	REP(i,n) ensure(i);

	int have=0; ll ret=0;
	while(have<want) {
#define IDX(q) (q.top().second.first)
#define TYPE(q) (q.top().second.second)
		while(!inc1.empty()&&need[TYPE(inc1)]!=x[IDX(inc1)].have) { x[IDX(inc1)].z[TYPE(inc1)]=false; inc1.pop(); }
		while(!inc2.empty()&&need[TYPE(inc2)]!=x[IDX(inc2)].have) { x[IDX(inc2)].z[TYPE(inc2)]=false; inc2.pop(); }
		while(!dec1.empty()&&need[TYPE(dec1)]!=x[IDX(dec1)].have) { x[IDX(dec1)].z[TYPE(dec1)]=false; dec1.pop(); }

		int opt1=inc1.empty()?INT_MAX:-inc1.top().first;
		int opt2=inc2.empty()||dec1.empty()?INT_MAX:-inc2.top().first-dec1.top().first;
		if(opt1<=opt2) {
			int a=IDX(inc1);
			ret+=opt1;
//			printf("%d (%d+)\n",opt1,a);
			++have; ++x[a].have; ensure(a);
		} else {
			int a=IDX(inc2),b=IDX(dec1);
			ret+=opt2;
//			printf("%d (%d++,%d-)\n",opt2,a,b);
			++have; x[a].have+=2; --x[b].have; ensure(a); ensure(b);
		}
	}
	cout<<ret<<endl;
	REP(i,n) printf("%d",x[i].have); puts("");
}

int main() {
	run();
	return 0;
}
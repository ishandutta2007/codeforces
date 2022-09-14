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

typedef struct P { int x,v; } P;
bool operator<(const P &a,const P &b) { return a.x<b.x; }
typedef struct QItem { double val; int a,b; } QItem;

int qsize;
QItem q[500000];
int qind[500000];

int up(int at) {
	while(at>0) {
		int to=at/2;
		if(q[to].val<=q[at].val) break;
		swap(q[at],q[to]);
		qind[q[at].a]=at;
		at=to;
	}
	qind[q[at].a]=at;
	return at;
}

int down(int at) {
	while(true) {
		int a=2*at+1,b=2*at+2,to=-1;
		if(a<qsize&&q[a].val<q[at].val) to=a;
		if(b<qsize&&q[b].val<q[at].val&&(to==-1||q[b].val<q[to].val)) to=b;
		if(to==-1) break;
		swap(q[at],q[to]);
		qind[q[at].a]=at;
		at=to;
	}
	qind[q[at].a]=at;
	return at;
}

void update(double t,int a,int b) {
//	printf("updating (%d,%d) -> %lf [%d]\n",a,b,t,qind[a]);
	int at=qind[a]!=-1?qind[a]:qsize++;
	q[at].val=t; q[at].a=a; q[at].b=b;
	at=up(at);
	at=down(at);
}

void rem(int at) {
//	printf("removing (%d,%d) (at %d)\n",q[at].a,q[at].b,at);
	assert(at!=-1);
	qind[q[at].a]=-1;
	swap(q[at],q[--qsize]); if(at>=qsize) return;
	at=up(at);
	at=down(at);
}

void run() {
	int n; scanf("%d",&n);
	vector<P> p(n); REP(i,n) scanf("%d%d",&p[i].x,&p[i].v);
	
/*	n=500000; p=vector<P>(n);
	srand(time(NULL));
	REP(i,n) p[i].x=rand()%100000,p[i].v=rand()%100000-50000;
	REP(i,n) if(p[i].v==0) ++p[i].v;
	sort(p.begin(),p.end()); FOR(i,1,n) { if(p[i].x<=p[i-1].x) p[i].x=p[i-1].x+1; }
//	REP(i,n) printf("%d %d\n",p[i].x,p[i].v); */
	
//	n=500000; p=vector<P>(n);
//	REP(i,n) p[i].x=i<(n/2)?INT_MIN+i:INT_MAX-(n-1)+i,p[i].v=i<n/2?n/2-i:n/2-1-i;
	
	vector<int> next(n,-1),prev(n,-1);
	
	double ret=-1;
	int at=0;
	while(at<n) {
		int a=at;
		while(at<n&&p[at].v>0) ++at;
		int b=at;
		while(at<n&&p[at].v<0) ++at;
		int c=at;
		// [a,b) -> <- [b,c)
		if(a==b||b==c) continue;
		FOR(i,a,c-1) next[i]=i+1; next[c-1]=-1;
		prev[a]=-1; FOR(i,a+1,c) prev[i]=i-1;
		qsize=0;
		FOR(i,a,c) qind[i]=-1;
		#define TEST(i,j) if(p[i].x<p[j].x&&p[i].v!=p[j].v) { double t=1.0*((ll)p[j].x-p[i].x)/((ll)p[i].v-p[j].v); if(t>0) update(t,i,j); else if(qind[i]!=-1) rem(qind[i]); } else if(qind[i]!=-1) rem(qind[i]);
		FOR(i,a,c-1) TEST(i,next[i]);
		while(true) {
//			REP(i,qsize) printf("(%d,%d)=%lf ",q[i].a,q[i].b,q[i].val); puts("");
			assert(qsize>0);
			double t=q[0].val; int i=q[0].a,j=q[0].b;
//			printf("%lf: %d<->%d\n",t,i,j);
//			if(j!=next[i]) { REP(i,n) printf("%d %d\n",p[i].x,p[i].v); fflush(stdout); fprintf(stderr,"!\n"); return; }
			assert(j==next[i]);
			if(p[i].v>0&&p[j].v<0) { if(ret==-1||t<ret) ret=t; break; }
			assert(p[i].v>0&&p[j].v>0||p[i].v<0&&p[j].v<0);
			if(p[i].v>0) {
				next[i]=next[j]; prev[j]=next[j]=-1; 
				if(next[i]!=-1) {
					prev[next[i]]=i;
					if(qind[j]!=-1) rem(qind[j]);
					TEST(i,next[i]);
				}
			} else {
				prev[j]=prev[i]; prev[i]=next[i]=-1;
				rem(0);
				if(prev[j]!=-1) {
					next[prev[j]]=j;
					TEST(prev[j],j);
				}
			}
		}
	}
	printf("%.9lf\n",ret);
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
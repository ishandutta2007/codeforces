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

typedef struct Truck { int v,c,l,r,ind; } Truck;
bool operator<(const Truck &a,const Truck &b) {
	if(a.l+a.c+a.r!=b.l+b.c+b.r) return a.l+a.c+a.r<b.l+b.c+b.r;
	return a.ind<b.ind;
}

void run() {
	int n; scanf("%d",&n);
	vector<Truck> truck(n); REP(i,n) { scanf("%d%d%d%d",&truck[i].v,&truck[i].c,&truck[i].l,&truck[i].r); truck[i].ind=i; }
	sort(truck.begin(),truck.end());
	vector<int> ret; int best=INT_MIN; // value of passing trucks
	int at=0;
	vector<int> prev(n,-1);
	vector<int> mark(truck.back().l+truck.back().c+truck.back().r+1,-1);
	vector<int> dp(truck.back().l+truck.back().c+truck.back().r+1);
	vector<int> last(truck.back().l+truck.back().c+truck.back().r+1);
	int curmark=0;
	while(at<SZ(truck)) {
//		printf("at %d\n",at);
		int cnt=truck[at].l+truck[at].c+truck[at].r;
		mark[0]=curmark; dp[0]=0; last[0]=-2;
		for(;at<SZ(truck)&&truck[at].l+truck[at].c+truck[at].r==cnt;++at) {
//			printf("\tat %d (%d)\n",at,cnt);
			int l=truck[at].l,c=truck[at].c,r=truck[at].r,v=truck[at].v;
			if(mark[l]!=curmark) continue;
			int to=l+c,nval=dp[l]+v;
//			printf("\tto %d -> %d (%d)\n",to,nval,dp[to]);
			if(mark[to]!=curmark||nval>dp[to]) { mark[to]=curmark; dp[to]=nval; last[to]=at; prev[at]=last[l]; }
		}
		if(mark[cnt]==curmark&&dp[cnt]>best) {
			best=dp[cnt];
			ret.clear(); for(int x=last[cnt];x!=-2;x=prev[x]) ret.PB(truck[x].ind); reverse(ret.begin(),ret.end());
		}
		++curmark;
	}
	printf("%d\n",SZ(ret));
	REPSZ(i,ret) { if(i>0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
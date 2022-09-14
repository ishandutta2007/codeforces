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


void run() {
	int ncells,nstairs,nq; scanf("%d%d%d",&ncells,&nstairs,&nq);
	vector<int> start(nstairs),end(nstairs),init(nstairs); REP(i,nstairs) scanf("%d%d%d",&start[i],&end[i],&init[i]);
	vector<int> q(nq); REP(i,nq) scanf("%d",&q[i]);
	sort(q.begin(),q.end());
	
	vector<pair<int,int> > events;
	REP(i,nstairs) events.PB(MP(start[i],init[i])),events.PB(MP(end[i]+1,-(init[i]+end[i]+1-start[i])));
	sort(events.begin(),events.end());

	ll ret=0,cur=0,delta=0;
	int ei=0,qi=0,at=0;
	while(qi<SZ(q)) {
//		printf("\tat %d, cur=%lld, delta=%lld (next event at %d)\n",at,cur,delta,ei<SZ(events)?events[ei].first:-1);
		if(ei>=SZ(events)||q[qi]<events[ei].first) {
			ret+=cur+delta*(q[qi]-at);
			++qi;
			continue;
		}
		cur+=delta*(events[ei].first-at); at=events[ei].first;
		if(events[ei].second>0) cur+=events[ei].second,++delta;
		if(events[ei].second<0) cur+=events[ei].second,--delta;
		++ei;		
	}
	cout<<ret<<endl;
}


int main() {
//	freopen ("input.txt","r",stdin);
//	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
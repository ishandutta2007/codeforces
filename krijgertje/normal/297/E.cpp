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

const int LIMIT=1<<18;
int val[LIMIT+1];

int get(int x) {
	++x;
	int ret=0;
	while(x!=0) {
		ret+=val[x];
		x-=x&-x;
	}
	return ret;
}

void update(int x,int by) {
	++x;
	while(x<=LIMIT) {
		val[x]+=by;
		x+=x&-x;
	}
}

void run(int casenr) {
	int nline; scanf("%d",&nline);
	vector<int> a(nline),b(nline); REP(i,nline) { scanf("%d%d",&a[i],&b[i]); --a[i]; --b[i]; }
	REP(i,nline) if(a[i]>b[i]) swap(a[i],b[i]);

	vector<int> ncross(nline,0);
	vector<int> ninside(nline,0);

	vector<pair<int,int> > events;
	REP(i,nline) { events.PB(MP(a[i],i)); events.PB(MP(b[i],i)); }
	sort(events.begin(),events.end());
	int ndone=0;
	REPSZ(i,events) {
		int p=events[i].first,at=events[i].second;
//		printf("%d: %d (%d)\n",i,p,at);
		if(p==a[at]) {
			ninside[at]-=ndone;
			ninside[at]-=get(a[at]);
			ncross[at]+=get(a[at]);
			update(a[at],+1);
		} else {
			ninside[at]+=ndone;
			update(a[at],-1); ++ndone;
			ncross[at]-=get(a[at]);
			ncross[at]+=get(b[at])-get(a[at]);
			ninside[at]+=get(a[at]);
		}
	}
//	REP(i,nline) printf("%d: %d,%d,%d\n",i,ncross[i],ninside[i],nline-ncross[i]-ninside[i]-1);

	ll tot=(ll)nline*(nline-1)*(nline-2)/6;
	ll min1=0;
	ll min2=0;
	REP(i,nline) {
		int noutside=nline-ncross[i]-ninside[i]-1;
		min1+=(ll)ninside[i]*noutside;
		min2+=(ll)ncross[i]*(ninside[i]+noutside);
	}
	ll ret=tot-min1-min2/2;
	cout<<ret<<endl;
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
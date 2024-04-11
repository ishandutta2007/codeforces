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
	int n,nq; scanf("%d%d",&n,&nq);

	int grouppow=0,groupsize=1;
	while(n/(2*groupsize)+2*groupsize<n/groupsize+groupsize) grouppow++,groupsize*=2;
		
	vector<int> single(n); REP(i,n) { int x; scanf("%d",&x); single[i]=i+x; }
	// next[i]=a -> (i>>grouppow)==(a>>grouppow), but (i>>grouppow)<(single[a]>>grouppow)
	// i->a == cnt[i] steps (only within group)
	vector<int> next(n);
	vector<int> cnt(n);
	for(int i=n-1;i>=0;--i) {
		if(single[i]<n&&(i>>grouppow)==(single[i]>>grouppow)) next[i]=next[single[i]],cnt[i]=1+cnt[single[i]];
		else next[i]=i,cnt[i]=0;
	}
//	printf("groupsize: %d\n",groupsize);
	while(nq-->0) {
//	REP(i,n) printf("%d: %d / (%d,%d)\n",i,single[i],nextgroup[i].first,nextgroup[i].second);
		int type; scanf("%d",&type);
		if(type==0) {
			int a,b; scanf("%d%d",&a,&b); --a;
			single[a]=a+b;
			for(int i=a;i>=0&&(i>>grouppow)==(a>>grouppow);--i) {
				if(single[i]<n&&(i>>grouppow)==(single[i]>>grouppow)) next[i]=next[single[i]],cnt[i]=1+cnt[single[i]];
				else next[i]=i,cnt[i]=0;
			}
		} else {
			int a; scanf("%d",&a); --a;
			int at=a,steps=0;
			while(single[at]<n) {
				steps+=cnt[at]; at=next[at];
				if(single[at]<n) ++steps,at=single[at];
			}
			printf("%d %d\n",at+1,steps+1);
		}
	}
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
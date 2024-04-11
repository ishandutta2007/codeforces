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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

typedef struct R { int id,l,r,cnt; } R;
bool operator<(const R &a,const R &b) { if(a.r!=b.r) return a.r<b.r; return a.id<b.id; }

R need[100000]; int nneed;
R have[100000]; int nhave;

set<pair<int,int> > state;
int ret[100000];

void run() {
	scanf("%d",&nneed); REP(i,nneed) { need[i].id=i; scanf("%d%d",&need[i].l,&need[i].r); need[i].cnt=1; } sort(need,need+nneed);
	scanf("%d",&nhave); REP(i,nhave) { have[i].id=i; scanf("%d%d%d",&have[i].l,&have[i].r,&have[i].cnt); } sort(have,have+nhave);


	// sort need according to highest note
	// sort have according to highest note
	// process in order of highest note:
	// o is a range we need -> add it to datastructure
	// o is a range we have -> choose range in datastructure with lowest note it can take
	int atneed=0,athave=0; state=set<pair<int,int> >();
	while(atneed<nneed||athave<nhave) {
		if(athave>=nhave||atneed<nneed&&need[atneed].r<=have[athave].r) {
			state.insert(MP(need[atneed].l,need[atneed].id));
			++atneed;
		} else {
			REP(i,have[athave].cnt) {
				set<pair<int,int> >::iterator it=state.lower_bound(MP(have[athave].l,-1));
				if(it==state.end()) break;
				ret[it->second]=have[athave].id;
				state.erase(it);
			}
			++athave;
		}
	}
	if(SZ(state)!=0) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,nneed) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}
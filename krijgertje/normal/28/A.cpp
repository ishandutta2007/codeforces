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
	int nnails,nrods; scanf("%d%d",&nnails,&nrods);
	vector<int> x(nnails),y(nnails); REP(i,nnails) scanf("%d%d",&x[i],&y[i]);
	vector<pair<int,int> > have(nrods); REP(i,nrods) { scanf("%d",&have[i].first); have[i].second=i; }
	sort(have.begin(),have.end());
	REP(start,2) {
		vector<pair<int,int> > need;
		for(int i=start;i<nnails;i+=2) {
			int a=i-1; if(a<0) a+=nnails;
			int b=i;
			int c=i+1; if(c>=nnails) c-=nnails;
			need.PB(MP(abs(x[b]-x[a])+abs(y[b]-y[a])+abs(x[c]-x[b])+abs(y[c]-y[b]),i));
		}
		sort(need.begin(),need.end());
		vector<int> match(nnails,-1); bool ok=true;
		int at=0;
		REPSZ(i,need) {
			while(at<SZ(have)&&need[i].first!=have[at].first) ++at;
			if(at>=SZ(have)) { ok=false; break; }
			match[need[i].second]=have[at++].second;
		}
		if(ok) {
			printf("YES\n");
			REP(i,nnails) { if(i!=0) printf(" "); printf("%d",match[i]==-1?-1:match[i]+1); } puts("");
			return;
		}
	}
	printf("NO\n");
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
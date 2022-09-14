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

ll take2(ll maxsum) {
	if(maxsum<0) return 0;
	return (maxsum+2)*(maxsum+1)/2;
}

ll notmore(ll maxval) {
	if(maxval<0) return 0;
	return (maxval+2)*(maxval+1)/2;
}

ll take2eq(ll val) {
	if(val<0) return 0;
	return val+1;
}

ll notdiff(ll maxval) {
	if(maxval<0) return 0;
	return maxval+1;
}

void run() {
	int N,x,M,y; scanf("%d%d%d%d",&N,&x,&M,&y);
	int d=abs(x-y);
	ll nzero=0,none=0,ntwo=0,ntotal=(ll)N*M;
	// {a+b+2<=d a:[0,N-1] b:[0,M-1]}
	// {a+b+2<=d} - {a+b+2<=d-M}  - {a+b+2<=d-N} + {a+b+2<=d-N-M}
	nzero+=take2(d-2)-take2(d-2-M)-take2(d-2-N)+take2(d-2-N-M);
//	printf("\t%lld\n",nzero);
	// {a-b>d a:[0,N-1] b:[0,M-1]}
	// {a>=b a:[0,N-d-2] b:[0,M-1]}
	// {a>=b a:[0,N-d-2]} - {a>=b a:[0,N-d-2-M]}
	nzero+=notmore(N-d-2)-notmore(N-M-d-2);
	nzero+=notmore(M-d-2)-notmore(M-N-d-2);
//	printf("\t%lld\n",nzero);
	// {a+b+1=d a:[0,N-1] b:[0,M-1]}
	// {a+b+1=d} - {a+b+M+1=d} - {N+a+b+1=d} + {N+a+b+M+1=d}
	none+=take2eq(d-1)-take2eq(d-M-1)-take2eq(d-N-1)+take2eq(d-N-M-1);
//	printf("\t%lld\n",none);
	// {a-b=d a:[0,N-1] b:[0,M-1]}
	// {a=b a:[0,N-1-d]} - {a=b a:[0,N-1-d-M]}
	none+=notdiff(N-d-1)-notdiff(N-M-d-1);
	none+=notdiff(M-d-1)-notdiff(M-N-d-1);
//	printf("\t%lld\n",none);
	ntwo=ntotal-nzero-none;
//	printf("\t%lld\n",ntwo);
	ll ret=1;
	ret+=1*none+2*ntwo;
	ret+=N; if(M>=d+1) ret-=min(N,M-d);
	ret+=M; if(N>=d+1) ret-=min(M,N-d);
	cout<<ret<<endl;
}


int main() {
//	freopen ("input.txt","r",stdin);
//	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
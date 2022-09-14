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

int ncll;
int cll[1000000];
int narr;
int arr[1000000];
int val[1000000];

void run(int casenr) {
	scanf("%d%d",&ncll,&narr);
	REP(i,ncll) scanf("%d",&cll[i]);
	REP(i,narr) scanf("%d",&arr[i]);
	REP(i,narr) val[i]=1;
	sort(arr,arr+narr);

	int at=0,ret=0;
	for(int i=0;;++i) {
		int cnt=0; REP(j,ncll) if(cll[j]&(1<<i)) { cll[j]-=1<<i; ++cnt; }
//		printf("%d: %d [%d]\n",i<<i,cnt,at);
//		FOR(j,at,narr) printf("(%d=%d)",arr[j],val[j]); puts("");
		while(cnt>0&&at<narr&&arr[at]==i) { ret+=val[at]; --cnt; ++at;  }
		int to=at; while(to<narr&&arr[to]==i) ++to;
		int nmerge=to-at;
		if(nmerge%2==1) { --to; arr[to]=i+1; }
		REP(j,nmerge/2) {
			arr[to-1-j]=i+1;
			val[to-1-j]=val[to-2*j-2]+val[to-2*j-1];
		}
		at=to-nmerge/2;
		bool done=true; REP(j,ncll) if(cll[j]!=0) { done=false; break; } if(done) break;
	}
	printf("%d\n",ret);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
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

int n,k;
int c[2000][2000];


void run(int casenr) {
	scanf("%d%d",&n,&k);
	REP(i,n-1) { c[i][i]=-1; FOR(j,i+1,n) { scanf("%d",&c[i][j]); c[j][i]=c[i][j]; } } c[n-1][n-1]=-1;
//	REP(i,n) { REP(j,n) printf("%2d ",c[i][j]); puts(""); }

	if(k==1) {
		ll sum=0; REP(i,n) REP(j,n) if(c[i][j]!=-1) sum+=c[i][j];
		cout<<sum/n<<endl;
	} else if(k==2) {
		int ntriangle=(n-1)/2;
		int center=-1;
		REP(i,n) { int cnt=0; REP(j,n) if(c[i][j]!=-1) ++cnt; if(cnt==n-1) center=i; } assert(center!=-1);
		REP(i,n) if(i!=center) { int cnt=0; REP(j,n) if(c[i][j]!=-1) ++cnt; assert(cnt==2); }
		ll sum=0;
		REP(i,n) FOR(j,i+1,n) if(i!=center&&j!=center&&c[i][j]!=-1) sum+=2*c[i][j];
		REP(i,n) if(i!=center) sum+=2LL*ntriangle*c[i][center];
		ll den=3*ntriangle+2LL*ntriangle*(ntriangle-1);
		cout<<sum/den;
	} else if(k==n-1) {
		REP(i,n) REP(j,n) if(i!=j) assert(c[i][j]!=-1);
		ll sum=0; REP(i,n) FOR(j,i+1,n) sum+=2LL*c[i][j];
		cout<<sum/n;
	} else {
		assert(false);
	}
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
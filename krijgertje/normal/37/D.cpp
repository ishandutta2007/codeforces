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


#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector> 
#include <deque> 
#include <queue> 
#include <set> 
#include <map> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 

const int MOD=1000000007;

int choose[1001][1001];

void run() {
	int n; scanf("%d",&n);
	vector<int> x(n); REP(i,n) scanf("%d",&x[i]);
	vector<int> y(n); REP(i,n) scanf("%d",&y[i]);
	int xsum=0; REP(i,n) xsum+=x[i];
	
	int at=0;
	vector<int> dp[2]; dp[at]=vector<int>(xsum+1,0); dp[at][0]=1;
	int xdone=0;
	REP(i,n) {
		int to=1-at; 
		dp[to]=vector<int>(xsum+1,0);
		int z1=choose[xsum-xdone][x[i]];
		REPE(j,xsum) if(dp[at][j]>0) {
			int z2=dp[at][j];
			int have=j+x[i];
			REPE(k,min(have,y[i])) {
				int z3=choose[have][k];
				dp[to][have-k]=(dp[to][have-k]+(ll)z1*z2%MOD*z3)%MOD;
			}
		}
		at=to; xdone+=x[i];
	}
	printf("%d\n",dp[at][0]);
}


int main() {
	REPE(i,1000) { choose[i][0]=choose[i][i]=1; FOR(j,1,i) { choose[i][j]=choose[i-1][j-1]+choose[i-1][j]; if(choose[i][j]>=MOD) choose[i][j]-=MOD; } }
//	freopen ("input.txt","r",stdin);
//	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
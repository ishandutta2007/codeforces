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

const int MOD=1000000007;

int n,m,k;

typedef struct State {
	int len,cntlast,ways;
	State(int len,int cntlast,int ways):len(len),cntlast(cntlast),ways(ways) {}
} State;
bool operator<(const State &a,const State &b) {
	if(a.len!=b.len) return a.len<b.len;
	if(a.cntlast!=b.cntlast) return a.cntlast<b.cntlast;
	if(a.ways!=b.ways) return a.ways<b.ways;
	return false;
}

map<State,ll> dp[2];
int choose[101][101];

void run(int casenr) {
	REPE(i,100) { choose[i][0]=choose[i][i]=1;
		FOR(j,1,i) {
			choose[i][j]=choose[i-1][j-1]+choose[i-1][j];
			if(choose[i][j]>=101) choose[i][j]=101;
		}
	}
	
	scanf("%d%d%d",&n,&m,&k);
	
	int at=0;
	FORE(i,1,n) dp[1-at][State(i,i,1)]++;
	ll ret=0;
	FORE(mm,2,m) {
		at=1-at; dp[1-at].clear();
		for(map<State,ll>::iterator it=dp[at].begin();it!=dp[at].end();++it) {
			int len=it->first.len,cntlast=it->first.cntlast,ways=it->first.ways;
			if(len+cntlast<=n) {
				ret+=(m-mm+1)*it->second;
			}
			FORE(curcnt,cntlast+1,n-len) {
				int nlen=len+curcnt,ncntlast=curcnt-cntlast,nways=ways*choose[curcnt-1][cntlast-1];
				if(nways>k) continue;
				dp[1-at][State(nlen,ncntlast,nways)]+=it->second;
			}
		}
	}
	ret%=MOD;
	cout<<ret<<endl;
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
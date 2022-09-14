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
	int R,C; scanf("%d%d",&R,&C);
	vector<string> g(R,string(C,'?')); REP(r,R) REP(c,C) scanf(" %c",&g[r][c]);
	VVI maxdown(R,VI(C)); REP(c,C) for(int r=R-1;r>=0;--r) maxdown[r][c]=g[r][c]=='1'?0:1+(r+1<R?maxdown[r+1][c]:0);
//	REP(r,R) { REP(c,C) printf("%d",maxdown[r][c]); puts(""); }
	int ret=0;
	REP(r,R) {
		stack<pair<int,int> > stack;
		#define SOL(c1,c2,dr) ret=max(ret,2*(dr)+2*((c2)-(c1)+1));
		REP(c,C) {
			int c1=c;
			while(SZ(stack)>0&&stack.top().first>maxdown[r][c]) {
				SOL(stack.top().second,c-1,stack.top().first);
				c1=stack.top().second;
				stack.pop();
			}
			if(maxdown[r][c]>0&&(SZ(stack)==0||maxdown[r][c]>stack.top().first)) stack.push(MP(maxdown[r][c],c1));
		}
		while(SZ(stack)>0) {
			SOL(stack.top().second,C-1,stack.top().first);
			stack.pop();
		}
	}
	printf("%d\n",ret);
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
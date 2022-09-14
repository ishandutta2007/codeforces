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

int n,m;
bool e[19][19];

ll mem[19][1<<19];
ll go(int start,int at,int been,int cnt) {
	ll &ret=mem[at][been];
	if(ret==-1) {
		ret=0;
		if(cnt>=3&&e[at][start]) ++ret;
		FOR(to,start+1,n) {
			if(!e[at][to]) continue;
			if((been&(1<<to))!=0) continue;
			ret+=go(start,to,been|(1<<to),cnt+1);
		}
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&m);
	memset(e,false,sizeof(e));
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; e[a][b]=e[b][a]=true; }
	
	ll ret=0;
	REP(i,n) {
		memset(mem,-1,sizeof(mem));
		ret+=go(i,i,1<<i,1);
	}
	cout<<ret/2<<endl;
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}
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
#include <cstring>
#include <list>  
#include <cassert>
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

const int MAXN=200000;
const int MAXM=200000;

int n,m,want;
vector<pair<int,int> > e[MAXN];

int d[MAXN];
int q[MAXN],qhead,qtail;
vector<int> opt[MAXN];

int have;
char cur[MAXM+1];
int lst[MAXN],nlst;

vector<string> ans;

void go(int idx) {
	if(have>=want) return;
	if(idx>=nlst) { ans.PB(cur); ++have; return; }
	int at=lst[idx];
	REPSZ(i,opt[at]) {
		int ei=opt[at][i];
		cur[ei]='1';
		go(idx+1);
		cur[ei]='0';
	}
}

void run() {
	scanf("%d%d%d",&n,&m,&want);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; e[a].PB(MP(b,i)); e[b].PB(MP(a,i)); }

	qhead=qtail=0; REP(i,n) d[i]=INT_MAX;
	d[0]=0,q[qhead++]=0;
	while(qtail<qhead) {
		int at=q[qtail++];
		REPSZ(i,e[at]) { int to=e[at][i].first; if(d[to]!=INT_MAX) continue; d[to]=d[at]+1,q[qhead++]=to; }
	}

	FOR(i,1,n) REPSZ(j,e[i]) if(d[i]==d[e[i][j].first]+1) opt[i].PB(e[i][j].second);
	REP(i,m) cur[i]='0'; cur[m]='\0';
	nlst=0; REP(i,n) if(SZ(opt[i])==1) cur[opt[i][0]]='1'; else if(SZ(opt[i])>1) lst[nlst++]=i;
	have=0; go(0);
	printf("%d\n",have); REP(i,have) printf("%s\n",ans[i].c_str());
}

int main() {
	run();
	return 0;
}
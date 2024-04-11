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

typedef struct X { int val,idx; } X;
bool operator<(const X &p,const X &q) { return p.val<q.val; }

int n,a,b;
X x[100000];

int e[100000][2];
int ret[100000];
int ans[100000];

int q[100000],qhead,qtail;

bool bfs(int start,int type) {
	qhead=qtail=0; q[qhead++]=start; ret[start]=type;
	while(qtail<qhead) {
		int at=q[qtail++];
		if(e[at][type]==-1) return false;
		if(e[at][type]!=-1&&ret[e[at][type]]==-1) { q[qhead++]=e[at][type]; ret[e[at][type]]=type; }
		if(e[at][1-type]!=-1&&ret[e[at][1-type]]==-1) { q[qhead++]=e[at][1-type]; ret[e[at][1-type]]=type; }
	}
	return true;
}

bool solve() {
	REP(i,n) ret[i]=-1;
	REP(i,n) if(e[i][0]==-1&&e[i][1]==-1) return false;
	REP(i,n) if(ret[i]==-1&&e[i][0]!=-1&&e[i][1]==-1) if(!bfs(i,0)) return false;
	REP(i,n) if(ret[i]==-1&&e[i][0]==-1&&e[i][1]!=-1) if(!bfs(i,1)) return false;
	REP(i,n) if(ret[i]==-1) if(!bfs(i,0)) return false;
	return true;
}

void run() {
	scanf("%d%d%d",&n,&a,&b);
	REP(i,n) scanf("%d",&x[i].val),x[i].idx=i; sort(x,x+n);

	{
		REP(i,n) e[i][0]=-1;
		int l=0,h=n-1;
		while(l<=h) {
			if(x[l].val+x[h].val<a) ++l;
			else if(x[l].val+x[h].val>a) --h;
			else { e[l][0]=h; e[h][0]=l; ++l; --h; }
		}
	}
	{
		REP(i,n) e[i][1]=-1;
		int l=0,h=n-1;
		while(l<=h) {
			if(x[l].val+x[h].val<b) ++l;
			else if(x[l].val+x[h].val>b) --h;
			else { e[l][1]=h; e[h][1]=l; ++l; --h; }
		}
	}
	//REP(i,n) printf("%d: %d / %d\n",x[i],e[i][0]==-1?0:x[e[i][0]],e[i][1]==-1?0:x[e[i][1]]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,n) ans[i]=-1; REP(i,n) ans[x[i].idx]=ret[i];
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}
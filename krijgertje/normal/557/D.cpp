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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MAXM=100000;

int n,m;
int head[MAXN],nxt[2*MAXM],to[2*MAXM];

int col[MAXN];
int colcnt[2];
int q[MAXN],qhead,qtail;

bool bipartite;
ll ways1;
void solve() {
	bipartite=true; ways1=0;
	REP(i,n) col[i]=-1;
	REP(i,n) if(col[i]==-1) {
		qhead=qtail=0; REP(j,2) colcnt[j]=0;
		col[i]=0; q[qhead++]=i; 
		while(qtail<qhead) {
			int at=q[qtail++];
			++colcnt[col[at]];
			for(int x=head[at];x!=-1;x=nxt[x]) {
				if(col[at]==col[to[x]]) { bipartite=false; return; }
				if(col[to[x]]!=-1) continue;
				col[to[x]]=1-col[at]; q[qhead++]=to[x];
			}
		}
		REP(j,2) ways1+=(ll)colcnt[j]*(colcnt[j]-1)/2;
	}
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) head[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a;
	}

	solve();
	if(!bipartite) { printf("%d %d\n",0,1); return; }
	if(ways1>0) { cout<<1<<" "<<ways1<<endl; return; }
	if(m>0) { cout<<2<<" "<<((ll)m*(n-2))<<endl; return; }
	{ cout<<3<<" "<<((ll)n*(n-1)*(n-2)/6)<<endl; return; }
}

int main() {
	run();
	return 0;
}
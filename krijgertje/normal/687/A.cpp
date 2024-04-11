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
int q[MAXN],qhead,qtail;

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) head[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a;
	}
	REP(i,n) col[i]=-1;
	qhead=qtail=0;
	REP(i,n) if(col[i]==-1) {
		col[i]=0; q[qhead++]=i;
		while(qtail<qhead) {
			int at=q[qtail++];
			for(int x=head[at];x!=-1;x=nxt[x]) {
				if(col[to[x]]==1-col[at]) continue;
				if(col[to[x]]!=-1) { printf("-1\n"); return; }
				col[to[x]]=1-col[at]; q[qhead++]=to[x];
			}
		}
	}
	int cnt[2]; cnt[0]=cnt[1]=0; REP(i,n) ++cnt[col[i]];
	REP(c,2) { printf("%d\n",cnt[c]); bool first=true; REP(i,n) if(col[i]==c) { if(first) first=false; else printf(" "); printf("%d",i+1); } puts(""); }
}

int main() {
	run();
	return 0;
}
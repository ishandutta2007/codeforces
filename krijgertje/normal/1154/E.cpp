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
#include <bitset>
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

int n,takedst;
int a[MAXN];
int ans[MAXN];

bool alive[MAXN];
int pos[MAXN];
int nxt[MAXN];
int prv[MAXN];

void kill(int x) {
	assert(alive[x]); alive[x]=false;
	if(prv[x]!=-1) nxt[prv[x]]=nxt[x];
	if(nxt[x]!=-1) prv[nxt[x]]=prv[x];
	prv[x]=nxt[x]=-1;
}

void solve() {
	REP(i,n) alive[i]=true,prv[i]=i==0?-1:i-1,nxt[i]=i==n-1?-1:i+1; REP(i,n) pos[a[i]]=i;
	int turn=1;
	for(int _=n-1;_>=0;--_) {
		int at=pos[_];
		if(!alive[at]) continue;
		{
			int cur=prv[at];
			REP(i,takedst) {
				if(cur==-1) break;
				int ncur=prv[cur];
				ans[cur]=turn;
				kill(cur);
				cur=ncur;
			}
		}
		{
			int cur=nxt[at];
			REP(i,takedst) {
				if(cur==-1) break;
				int ncur=nxt[cur];
				ans[cur]=turn;
				kill(cur);
				cur=ncur;
			}
		}
		ans[at]=turn;
		kill(at);
		turn=3-turn;
	}
}

void run() {
	scanf("%d%d",&n,&takedst);
	REP(i,n) scanf("%d",&a[i]),--a[i];
	solve();
	REP(i,n) printf("%d",ans[i]); puts("");

}

int main() {
	run();
	return 0;
}
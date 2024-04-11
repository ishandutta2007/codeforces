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
const int MOD=1000000007;

int n;
int nxt[2*MAXN];
int state[2*MAXN];

vector<int> ch[2*MAXN];
int dfssz(int at) { int ret=1; REPSZ(i,ch[at]) ret+=dfssz(ch[at][i]); /*printf("sz(%d)=%d\n",at,ret);*/ return ret; }

void run() {
	scanf("%d",&n); REP(i,2*n) nxt[i]=-1;
	REP(i,n) { int a,b; scanf("%d%d",&a,&b); --a,--b; nxt[a]=b; }

	int ret=1;
	REP(i,2*n) state[i]=0;
	REP(i,2*n) if(state[i]==0&&nxt[i]!=-1) {
		int at=i; while(state[at]==0) { state[at]=1; if(nxt[at]==-1) break; at=nxt[at]; }
		if(state[at]==1&&nxt[at]!=-1&&nxt[at]!=at) ret=(ll)ret*2%MOD;
		int nstate=state[at]==2||state[at]==1&&nxt[at]!=-1?2:3;
		at=i; while(state[at]==1) { state[at]=nstate; if(nxt[at]==-1) break; at=nxt[at]; }
		//printf("state:"); REP(j,2*n) printf(" %d",state[j]); puts("");
	}

	//printf("state:"); REP(j,2*n) printf(" %s",state[j]!=3?"x":nxt[j]==-1?"r":"n"); puts("");
	REP(i,2*n) if(nxt[i]!=-1&&state[i]==3) ch[nxt[i]].PB(i);
	REP(i,2*n) if(nxt[i]==-1&&state[i]==3) ret=(ll)ret*dfssz(i)%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
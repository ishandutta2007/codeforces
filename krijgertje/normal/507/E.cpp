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

int n,m;
int fst[100000];
int working[100000];
int nworking[100000];
int nxt[200000];
int to[200000];

int d[100000];
int best[100000],back[100000];
int q[100000],qhead,qtail;


void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) fst[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d%d",&a,&b,&working[i]); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}
	
	int s=n-1,t=0;
	REP(i,n) d[i]=-1;
	qhead=qtail=0; q[qhead++]=s; d[s]=0;
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=fst[at];x!=-1;x=nxt[x]) if(d[to[x]]==-1) { q[qhead++]=to[x]; d[to[x]]=d[at]+1; }
	}

	REP(i,n) best[i]=-1,back[i]=-2; best[s]=0,back[s]=-1;
	REP(i,n) {
		int at=q[i];
		for(int x=fst[at];x!=-1;x=nxt[x]) if(d[to[x]]==d[at]+1) {
			int nval=best[at]+working[x/2];
			if(nval>best[to[x]]) best[to[x]]=nval,back[to[x]]=x^1;
		}
	}

	REP(i,m) nworking[i]=0;
	for(int x=t;x!=s;x=to[back[x]]) nworking[back[x]/2]=1;

	int ret=0; REP(i,m) if(working[i]!=nworking[i]) ++ret;
	printf("%d\n",ret);
	REP(i,m) if(working[i]!=nworking[i]) printf("%d %d %d\n",to[2*i+1]+1,to[2*i+0]+1,nworking[i]);
}

int main() {
	run();
	return 0;
}
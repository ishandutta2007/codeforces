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

int n,m;
int fst[100000];
int to[200000];
int nxt[200000];

int state[100000];
int todo[100000];
int responsible[100000];
int stck[100000],nstck;

int nret,ret[50000][3];

void run() {
	scanf("%d%d",&n,&m);
	memset(fst,-1,sizeof(fst));
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i]=fst[a]; fst[a]=2*i; to[2*i]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}

	nstck=0; nret=0;
	memset(todo,-1,sizeof(todo));
	memset(state,-1,sizeof(state));
	memset(responsible,-1,sizeof(responsible));
	REP(i,n) if(state[i]==-1) {
		stck[nstck++]=i; state[i]=0;
		while(nstck>0) {
			int at=stck[nstck-1];
			if(state[at]==0) {
				for(int x=fst[at];x!=-1;x=nxt[x]) {
					if(responsible[x>>1]==-1) responsible[x>>1]=at;
					if(state[to[x]]==-1) { stck[nstck++]=to[x]; state[to[x]]=0; }
				}
				state[at]=1;
			} else if(state[i]==1) {
				for(int x=fst[at];x!=-1;x=nxt[x]) {
					if(responsible[x>>1]!=at) continue;
					if(todo[to[x]]!=-1) { ret[nret][0]=at; ret[nret][1]=to[x]; ret[nret][2]=todo[to[x]]; ++nret; todo[to[x]]=-1; continue; }
					if(todo[at]==-1) { todo[at]=to[x]; continue; }
					{ ret[nret][0]=todo[at]; ret[nret][1]=at; ret[nret][2]=to[x]; ++nret; todo[at]=-1; continue; }
				}
				state[at]=2;
				--nstck;
			}
		}
	}

	REP(i,n) if(todo[i]!=-1) { printf("No solution\n"); return; }
	REP(i,nret) printf("%d %d %d\n",ret[i][0]+1,ret[i][1]+1,ret[i][2]+1);
}

int main() {
	run();
	return 0;
}
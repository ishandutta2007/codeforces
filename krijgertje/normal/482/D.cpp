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

const int MOD=1000000007;

int n;
int par[100000];
int fst[100000],nxt[100000];

int evn[100000],odd[100000];

#define M(a,b) (((ll)(a)*(b))%MOD)
#define A(a,b) (((ll)(a)+(b))%MOD)
#define S(a,b) (((ll)(a)-(b)+MOD)%MOD)

void go(int at) {
	int e=0,o=1,alle=1,eallo=1,oallo=0;
	for(int to=fst[at];to!=-1;to=nxt[to]) {
		go(to);
		int ne=A(e,A(M(e,evn[to]),M(o,odd[to])));
		int no=A(o,A(M(e,odd[to]),M(o,evn[to])));
		int nalle=A(alle,M(alle,evn[to]));
		int neallo=A(eallo,M(oallo,odd[to]));
		int noallo=A(oallo,M(eallo,odd[to]));
		e=ne,o=no,alle=nalle,eallo=neallo,oallo=noallo;
	}
	evn[at]=S(M(e,2),oallo);
	odd[at]=S(M(o,2),alle);
//	printf("%d: evn=%d odd=%d [%d,%d,%d,%d,%d]\n",at,evn[at],odd[at],e,o,alle,eallo,oallo);
}


void run() {
	scanf("%d",&n);
	par[0]=-1; FOR(i,1,n) { scanf("%d",&par[i]); --par[i]; }
	memset(fst,-1,sizeof(fst));
	for(int i=n-1;i>=1;--i) { nxt[i]=fst[par[i]]; fst[par[i]]=i; }
	go(0);
	int ret=A(evn[0],odd[0]);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
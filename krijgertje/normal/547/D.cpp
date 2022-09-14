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

const int MAXP=200000;
const int MAXX=200000;
const int MAXY=200000;
const int MAXN=MAXX+MAXY+2;
const int MAXM=MAXP+(MAXX>=MAXY?MAXX:MAXY);

int np;
int px[MAXP],py[MAXP];

int n,m;
int fst[MAXN],cnt[MAXN];
int nxt[2*MAXM],to[2*MAXM];


int cur[MAXN];
bool done[MAXM];
int path[MAXM],npath;
int stck[MAXM],nstck;
void dfs(int at) {
	while(cur[at]!=-1&&done[cur[at]/2]) cur[at]=nxt[cur[at]];
	if(cur[at]!=-1) {
		stck[nstck++]=cur[at]/2;
		done[cur[at]/2]=true;
		dfs(to[cur[at]]);
		path[npath++]=stck[--nstck];
	}
}

char ret[MAXP+1];

void input() {
	scanf("%d",&np);
	REP(i,np) { scanf("%d%d",&px[i],&py[i]); --px[i],--py[i]; }
}

void solve() {
	n=MAXN,m=0;
	REP(i,n) fst[i]=-1,cnt[i]=0;
	REP(i,np) {
		int x=px[i],y=py[i]+MAXX;
		nxt[m]=fst[x]; fst[x]=m; to[m]=y; ++cnt[x]; ++m;
		nxt[m]=fst[y]; fst[y]=m; to[m]=x; ++cnt[y]; ++m;
	}
	{
		int x=0;
		while(true) {
			while(x<MAXN&&cnt[x]%2==0) ++x;
			if(x>=MAXN) break;
			int y=x<MAXX?MAXN-2:MAXN-1;
			nxt[m]=fst[x]; fst[x]=m; to[m]=y; ++cnt[x]; ++m;
			nxt[m]=fst[y]; fst[y]=m; to[m]=x; ++cnt[y]; ++m;
		}
	}

	REP(i,n) cur[i]=fst[i];
	REP(i,m/2) done[i]=false;
	npath=nstck=0;
	REP(i,n) if(cur[i]!=-1) dfs(i);
	//REP(i,npath) printf("%d-%d\n",to[2*path[i]+1],to[2*path[i]+0]);
	REP(i,npath) if(path[i]<np) ret[path[i]]="rb"[i%2]; ret[np]='\0';
}

int chk[MAXN][2];
void check() {
	memset(chk,0,sizeof(chk));
	REP(i,np) {
		int c=ret[i]=='b';
		++chk[px[i]][c],++chk[py[i]+MAXX][c];
	}
	REP(i,MAXN) assert(abs(chk[i][0]-chk[i][1])<=1);
}


void run() {
	input();
	solve();
	printf("%s\n",ret);
}

int myrand() { return rand()*(1<<15)+rand(); }

void test() {
	//srand(time(NULL));
	while(true) {
		np=MAXP;
		REP(i,np) px[i]=myrand()%MAXX,py[i]=myrand()%MAXY;
		//printf("%d\n",np); REP(i,np) printf("%d %d\n",px[i]+1,py[i]+1);
		solve();
		check();
		printf(".");
	}
}

int main() {
	run();
	//test();
	return 0;
}
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

const int MAXN=200000;
const int MAXM=200000;

int n,m;
vector<int> missing[MAXN];

int head,tail,nxt[MAXN],prv[MAXN];
int comp[MAXN],ncomp;
int ret[MAXN],nret;
int q[MAXN],qhead,qtail;

void rem(int at) {
	if(prv[at]==-1) head=nxt[at]; else nxt[prv[at]]=nxt[at];
	if(nxt[at]==-1) tail=prv[at]; else prv[nxt[at]]=prv[at];
}

void printlst() {
	printf("lst:"); for(int x=head;x!=-1;x=nxt[x]) assert(x==head&&prv[x]==-1||x!=head&&nxt[prv[x]]==x),printf(" %d",x); puts("");
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; missing[a].PB(b); missing[b].PB(a); }
	REP(i,n) sort(missing[i].begin(),missing[i].end());

	head=tail=0,prv[0]=nxt[0]=-1; FOR(i,1,n) prv[i]=tail,nxt[i]=-1,nxt[prv[i]]=i,tail=i;

	ncomp=0; REP(i,n) comp[i]=-1; qhead=qtail=0;
	REP(i,n) if(comp[i]==-1) {
		//printf("no comp for %d\n",i); printlst();
		comp[i]=ncomp++; rem(i); q[qhead++]=i;
		//printf("after setting comp\n");	printlst();
		while(qtail<qhead) {
			int at=q[qtail++],idx=0;
			for(int to=head;to!=-1;to=nxt[to]) {
				while(idx<SZ(missing[at])&&missing[at][idx]<to) ++idx;
				if(idx<SZ(missing[at])&&missing[at][idx]==to) { ++idx; continue; }
				assert(comp[to]==-1); comp[to]=comp[at]; rem(to); q[qhead++]=to;
			}
		}
	}
	
	nret=ncomp; REP(i,nret) ret[i]=0; REP(i,n) ++ret[comp[i]]; sort(ret,ret+nret);
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}
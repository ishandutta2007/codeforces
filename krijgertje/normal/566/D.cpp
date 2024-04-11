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
const int MAXQ=500000;

int n,nq;

int par[MAXN],rnk[MAXN];
int rngpar[MAXN],rngrnk[MAXN],rngnxt[MAXN];


int get(int x) { if(par[x]==x) return x; return par[x]=get(par[x]); }
int rngget(int x) { if(rngpar[x]==x) return x; return rngpar[x]=rngget(rngpar[x]); }
void unite(int x,int y) {
	x=get(x),y=get(y); if(x==y) return;
	if(rnk[x]<rnk[y]) swap(x,y);
	par[y]=x,rnk[x]+=rnk[x]==rnk[y]?1:0;
}
void uniterng(int x,int z) {
	x=rngget(x);
	while(true) {
		if(rngnxt[x]==-1||rngnxt[x]>z) break;
		int y=rngget(rngnxt[x]);
		assert(x!=y);
		unite(x,y);
		int tmp=rngnxt[y];
		if(rngrnk[x]<rngrnk[y]) swap(x,y);
		rngpar[y]=x,rngrnk[x]+=rngrnk[x]==rngrnk[y]?1:0,rngnxt[x]=tmp;
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) par[i]=i,rnk[i]=0;
	REP(i,n) rngpar[i]=i,rngrnk[i]=0,rngnxt[i]=i+1<n?i+1:-1;
	REP(qi,nq) {
		int type,x,y; scanf("%d%d%d",&type,&x,&y); --x,--y;
		if(type==1) unite(x,y);
		if(type==2) uniterng(x,y);
		if(type==3) printf("%s\n",get(x)==get(y)?"YES":"NO");
	}
}

void test() {
	REP(times,100000) {
		n=1000,nq=100;
		REP(i,n) par[i]=i,rnk[i]=0;
		REP(i,n) rngpar[i]=i,rngrnk[i]=0,rngnxt[i]=i+1<n?i+1:-1;
		REP(qi,nq) {
			int type=rand()%3+1,x=rand()%n,y=rand()%n; if(x>y) swap(x,y);
			//printf("%d %d %d\n",type,x+1,y+1);
			if(type==1) unite(x,y);
			if(type==2) uniterng(x,y);
			if(type==3) get(x),get(y);
			
		}
		printf(".");
	}
}


int main() {
	//test();
	run();
	return 0;
}
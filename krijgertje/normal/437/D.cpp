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
int cnt[100000];
int p[100000];

int fst[100000];
int nxt[200000];
int to[200000];

bool exists[100000];
int par[100000];
int rnk[100000];
int sz[100000];

bool pcmp(const int &a,const int &b) { return cnt[a]>cnt[b]; }
int find(int a) { if(par[a]==a) return a; return par[a]=find(par[a]); }

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%d",&cnt[i]);
	REP(i,n) fst[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=fst[a]; to[2*i+0]=b; fst[a]=2*i+0;
		nxt[2*i+1]=fst[b]; to[2*i+1]=a; fst[b]=2*i+1;
	}

	double ret=0;
	REP(i,n) p[i]=i; sort(p,p+n,pcmp);
	REP(i,n) exists[i]=false;
	REP(i,n) {
		int at=p[i];
		exists[at]=true; par[at]=at; rnk[at]=0; sz[at]=1;
		for(int x=fst[at];x!=-1;x=nxt[x]) {
			if(!exists[to[x]]) continue;
			int a=find(at),b=find(to[x]);
			if(a==b) continue;
			ret+=2.0*sz[a]*sz[b]*cnt[at];
			//printf("\t%d-%d -> %d*%d*%d\n",at,to[x],sz[a],sz[b],cnt[at]);
			if(rnk[a]<rnk[b]) swap(a,b);
			par[b]=a; sz[a]+=sz[b]; rnk[a]+=rnk[a]==rnk[b]?1:0;
		}
	}
	printf("%.9lf\n",ret/n/(n-1));
}

int main() {
	run();
	return 0;
}
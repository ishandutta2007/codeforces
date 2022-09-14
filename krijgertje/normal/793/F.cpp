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
#include <random>
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
const int SZ=400;
const int MAXB=(MAXN+SZ-1)/SZ;

int n,m,nq;
int nb;

int jump[MAXN][MAXB]; // jump[i][j]=k -> starting from i, if upper bound is j*SZ the highest we can get is k (only valid for i<=j*SZ)

int radj[MAXN];
vector<int> adj[MAXN];
int idx[MAXN];
int stck[MAXN],nstck;

int calc(int l,int r,int at,int done) {
	FORE(to,done+1,r) if(radj[to]!=-1&&l<=radj[to]&&radj[to]<=at) at=to;
	return at;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) adj[i].clear(),radj[i]=-1;
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); radj[b]=a; }
	REP(i,n) sort(adj[i].begin(),adj[i].end());

	nb=(n+SZ-1)/SZ;
	REP(i,n) idx[i]=0;
	REP(j,nb) {
		nstck=0;
		for(int at=min(n-1,j*SZ);at>=0;--at) {
			int to=at; // to=highest position <= j*SZ we can directly go to
			while(idx[at]+1<SZ(adj[at])&&adj[at][idx[at]+1]<=j*SZ) ++idx[at];
			if(idx[at]<SZ(adj[at])&&adj[at][idx[at]]<=j*SZ) to=adj[at][idx[at]];
			int best=to;
			while(nstck>0&&to>=stck[nstck-1]) best=jump[stck[--nstck]][j];
			jump[at][j]=best; stck[nstck++]=at;
		}
	}

	scanf("%d",&nq);
	REP(qi,nq) {
		int l,r; scanf("%d%d",&l,&r); --l,--r;
		int j=r/SZ;
		int ret=l<=j*SZ?calc(l,r,jump[l][j],j*SZ):calc(l,r,l,l);
		printf("%d\n",ret+1);
	}
}

int main() {
	run();
	return 0;
}
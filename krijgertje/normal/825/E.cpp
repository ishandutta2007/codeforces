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
const int MAXM=100000;

int n,m;
int ghead[MAXN],gnxt[MAXM],gto[MAXM];
int rhead[MAXN],rnxt[MAXM],rto[MAXM];
int indeg[MAXN],outdeg[MAXN];
bool need[MAXN];

int ret[MAXN];
priority_queue<int> pq;

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) ghead[i]=rhead[i]=-1,indeg[i]=outdeg[i]=0,need[i]=false;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[i]=ghead[a],ghead[a]=i,gto[i]=b,++outdeg[a];
		rnxt[i]=rhead[b],rhead[b]=i,rto[i]=a,++indeg[b];
	}
	memset(ret,-1,sizeof(ret));
	REP(i,n) if(outdeg[i]==0) pq.push(i);
	int now=n;
	while(SZ(pq)>0) {
		int at=pq.top(); pq.pop();
		ret[at]=now--;
		for(int x=rhead[at];x!=-1;x=rnxt[x]) {
			int to=rto[x];
			if(--outdeg[to]==0) pq.push(to);
		}
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}
#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;

int n,kwant;
vector<int> adj[MAXN];

int deg[MAXN];
bool alive[MAXN];
vector<int> cleaf;
vector<int> nleaf;

bool solve() {
	REP(i,n) deg[i]=SZ(adj[i]),alive[i]=true;
	cleaf.clear(); REP(i,n) if(deg[i]<=1) cleaf.PB(i),alive[i]=false;
	int khave=-1;
	while(SZ(cleaf)!=0) {
		++khave;
		//printf("processing %d\n",khave);
		nleaf.clear();
		REPSZ(i,cleaf) {
			int at=cleaf[i];
			REPSZ(j,adj[at]) {
				int to=adj[at][j];
				--deg[to];
				if(!alive[to]) continue;
				alive[to]=false; nleaf.PB(to);
			}
		}
		REPSZ(i,nleaf) {
			int at=nleaf[i];
			if(deg[at]>1) return false;
			if(SZ(adj[at])<deg[at]+3) return false;
		}
		if(SZ(nleaf)==0&&SZ(cleaf)!=1) return false;
		cleaf=nleaf;
	}
	return khave==kwant;
}

void run() {
	scanf("%d%d",&n,&kwant);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%s\n",solve()?"Yes":"No");
}

int main() {
	run();
	return 0;
}
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

const int MAXN=200000;
const int MAXVAL=200000;

int n,mxval;
int a[MAXN];

bool any[MAXVAL+1]; int l[MAXVAL+1],r[MAXVAL+1];
set<int> zero;
int bit[MAXN+1];
vector<int> pos[MAXVAL+1];
int bget(int idx) { ++idx; int ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }
void bmod(int idx,int by) { ++idx; while(idx<=n) { bit[idx]+=by; idx+=idx&-idx; } }

int ans[MAXN];

bool solve() {
	REPE(i,mxval) any[i]=false,l[i]=INT_MAX,r[i]=INT_MIN; REP(i,n) if(a[i]!=0) any[a[i]]=true,l[a[i]]=min(l[a[i]],i),r[a[i]]=max(r[a[i]],i);
	zero.clear(); REP(i,n) if(a[i]==0) zero.insert(i);
	REPE(i,n) bit[i]=0;
	REPE(i,mxval) pos[i].clear(); REP(i,n) if(a[i]!=0) pos[a[i]].PB(i);
	REP(i,n) ans[i]=a[i];
	bool havemx=any[mxval];
	for(int v=mxval;v>=1;--v) if(any[v]) {
		auto it=zero.lower_bound(l[v]);
		while(it!=zero.end()&&*it<=r[v]) { if(!havemx) ans[*it]=mxval,havemx=true; else ans[*it]=v; bmod(*it,+1); ++it; zero.erase(prev(it)); }
		REPSZ(i,pos[v]) bmod(pos[v][i],+1);
		int have=bget(r[v])-bget(l[v]-1),want=r[v]-l[v]+1;
		if(have!=want) return false;
	}
	while(SZ(zero)!=0) { if(!havemx) ans[*zero.begin()]=mxval,havemx=true; else ans[*zero.begin()]=1; bmod(*zero.begin(),+1); zero.erase(zero.begin()); }
	return havemx;
}

void run() {
	scanf("%d%d",&n,&mxval);
	REP(i,n) scanf("%d",&a[i]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}
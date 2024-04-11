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
typedef struct E { int idx,val; } E;
bool operator<(const E &a,const E &b) { return a.val<b.val; }

int n,m;
int nuse,nother;
E use[MAXN-1];
E other[MAXM];
int u[MAXM],v[MAXM];

void run() {
	scanf("%d%d",&n,&m);
	nuse=nother=0; REP(i,m) { int a,b; scanf("%d%d",&a,&b); if(b==0) other[nother].idx=i,other[nother].val=a,++nother; else use[nuse].idx=i,use[nuse].val=a,++nuse; }
	sort(use,use+nuse);
	sort(other,other+nother);

	int at=0;
	REP(i,nuse) {
		if(at<nother&&other[at].val<use[i].val) { printf("-1\n"); return; }
		for(int j=1;j<=i&&at<nother;++j) u[other[at].idx]=j,v[other[at].idx]=i+1,++at;
		u[use[i].idx]=0,v[use[i].idx]=i+1;
	}
	REP(i,m) printf("%d %d\n",u[i]+1,v[i]+1);
}

int main() {
	run();
	return 0;
}
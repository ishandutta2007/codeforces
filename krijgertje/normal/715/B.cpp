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

const int MAXN=1000;
const int MAXM=10000;

int n,m,want,s,t;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],len[MAXM],ret[MAXM];

int bck[MAXN]; bool use[MAXM];

ll calc(ll *d,int zlen) {
	REP(i,n) d[i]=LLONG_MAX,bck[i]=-1;
	priority_queue<pair<ll,int> > q; d[s]=0,q.push(MP(0LL,s));
	while(!q.empty()) {
		ll cur=-q.top().first; int at=q.top().second; q.pop();
		if(d[at]!=cur) continue;
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x];
			ll nxt=cur+(len[x>>1]!=0?len[x>>1]:zlen);
			if(nxt<d[to]) d[to]=nxt,bck[to]=x^1,q.push(MP(-nxt,to));
		}
	}
	return d[t];
}

ll dmx[MAXN],dmn[MAXN];

bool solve() {
	calc(dmx,want+1); if(dmx[t]<want) return false;
	calc(dmn,1); if(dmn[t]>want) return false;
	REP(i,m) ret[i]=len[i]!=0?len[i]:want+1;
	if(dmx[t]==want) return true;
	for(int at=t;at!=s;at=gto[bck[at]]) {
		int prv=gto[bck[at]];
		if(dmx[prv]+dmn[t]-dmn[prv]<=want) {
			assert(len[bck[at]>>1]==0);
			ret[bck[at]>>1]=want-dmx[prv]-dmn[t]+dmn[at];
			return true;
		}
		if(len[bck[at]>>1]==0) ret[bck[at]>>1]=1;
	}
	assert(false);
}

void run() {
	scanf("%d%d%d%d%d",&n,&m,&want,&s,&t);
	REP(i,n) ghead[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d%d",&a,&b,&len[i]);
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a;
	}
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,m) printf("%d %d %d\n",gto[2*i+1],gto[2*i+0],ret[i]);
}

int main() {
	run();
	return 0;
}
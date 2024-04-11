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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int n,m,nroad,ntrain;
int a[400000],b[400000],c[400000];

int lst[100000],prv[800000],to[800000],len[800000];
ll d[100000]; bool byroad[100000];

void run() {
	scanf("%d%d%d",&n,&nroad,&ntrain); m=nroad+ntrain;
	REP(i,nroad) { scanf("%d%d%d",&a[i],&b[i],&c[i]); --a[i],--b[i]; }
	REP(i,ntrain) { a[nroad+i]=0; scanf("%d%d",&b[nroad+i],&c[nroad+i]); --b[nroad+i]; }

	memset(lst,-1,sizeof(lst));
	REP(i,m) {
		prv[2*i+0]=lst[a[i]]; to[2*i+0]=b[i]; len[2*i+0]=c[i]; lst[a[i]]=2*i+0;
		prv[2*i+1]=lst[b[i]]; to[2*i+1]=a[i]; len[2*i+1]=c[i]; lst[b[i]]=2*i+1;
	}

	memset(d,-1,sizeof(d));
	priority_queue<pair<ll,int> > q;
	d[0]=0; byroad[0]=true; q.push(MP(-d[0],0));
	while(!q.empty()) {
		int at=q.top().second; ll cost=-q.top().first; q.pop();
		if(cost>d[at]) continue;
		for(int x=lst[at];x!=-1;x=prv[x]) {
			ll ncost=cost+len[x];
			if(d[to[x]]!=-1&&ncost>d[to[x]]) continue;
			if(ncost==d[to[x]]) { byroad[to[x]]|=x<2*nroad; continue; }
			d[to[x]]=ncost; byroad[to[x]]=x<2*nroad; q.push(MP(-d[to[x]],to[x]));
		}
	}
	//REP(i,n) printf("%d: %lld %c\n",i,d[i],byroad[i]?'V':'-');
	int ret=ntrain; REP(i,n) if(!byroad[i]) --ret; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
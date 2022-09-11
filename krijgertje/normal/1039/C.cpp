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

const int MAXN=500000;
const int MAXM=500000;
const int MOD=1000000007;
struct E { int a,b; ll c; };
bool operator<(const E &u,const E &v) { return u.c<v.c; }

int n,m,nbit;
ll val[MAXN];
E e[MAXM];

int p2[MAXN+1];

ll mark[MAXN];
bool been[MAXN];
vector<int> adj[MAXN];
int lst[MAXN],nlst;

void dfs(int at) {
	been[at]=true; REPSZ(i,adj[at]) { int to=adj[at][i]; if(!been[to]) dfs(to); }
}

void run() {
	scanf("%d%d%d",&n,&m,&nbit);
	REP(i,n) scanf("%lld",&val[i]);
	REP(i,m) { scanf("%d%d",&e[i].a,&e[i].b),--e[i].a,--e[i].b; }

	int ret=0,cnt=0;
	REP(i,m) e[i].c=val[e[i].a]^val[e[i].b];
	sort(e,e+m);
	REP(i,n) mark[i]=-1;
	p2[0]=1; FORE(i,1,n) p2[i]=(ll)p2[i-1]*2%MOD;
	for(int l=0,r=l;l<m;l=r) {
		ll c=e[l].c;
		while(r<m&&e[r].c==c) ++r;
		nlst=0;
		FOR(i,l,r) {
			int a=e[i].a,b=e[i].b;
			if(mark[a]!=c) adj[a].clear(),mark[a]=c,lst[nlst++]=a;
			if(mark[b]!=c) adj[b].clear(),mark[b]=c,lst[nlst++]=b;
			adj[a].PB(b),adj[b].PB(a);
		}
		REP(i,nlst) been[lst[i]]=false;
		int ncomp=n-nlst; REP(i,nlst) if(!been[lst[i]]) ++ncomp,dfs(lst[i]);
		ret=(ret+p2[ncomp])%MOD; ++cnt;
	}
	ret=(ret+((1LL<<nbit)-cnt)%MOD*p2[n])%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
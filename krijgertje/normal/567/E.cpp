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
const int MAXPQ=MAXN;
typedef struct E { ll val; int type,idx; } E;
bool operator<(const E &a,const E &b) { if(a.val!=b.val) return a.val<b.val; if(a.type!=b.type) return a.type<b.type; return a.idx<b.idx; }

typedef struct PQ {
	int n;
	ll *val; // idx->val
	int pos[MAXPQ]; // idx->pos
	int idx[MAXPQ]; // pos->idx

	PQ(int maxn,ll *val):val(val) { n=0; REP(i,maxn) pos[i]=-1,idx[i]=-1; }
	bool empty() { return n==0;	}
	void relax(int x,ll nval) { val[x]=nval; if(pos[x]==-1) pos[x]=n,idx[n]=x,++n; up(pos[x]); }
	int pop() { int ret=idx[0]; myswap(0,n-1); if(--n>0) down(0); return ret; }
	void myswap(int a,int b) { swap(idx[a],idx[b]); swap(pos[idx[a]],pos[idx[b]]); }
	void up(int a) {  while(a!=0) { int na=a,b=(a-1)/2; if(val[idx[b]]>val[idx[na]]) na=b; if(a==na) break; myswap(a,na); a=na; } }
	void down(int a) { while(true) { int na=a,b=2*a+1,c=2*a+2; if(b<n&&val[idx[b]]<val[idx[na]]) na=b; if(c<n&&val[idx[c]]<val[idx[na]]) na=c; if(a==na) break; myswap(a,na); a=na; } }
	void print() { REP(i,n) printf("(%d,%d,%lld)",idx[i],pos[idx[i]],val[idx[i]]); puts(""); }
} PQ;

int n,m,s,t;
int head[2][MAXN];
int from[MAXM],to[MAXM],len[MAXM],nxt[2][MAXM];
ll d[2][MAXN];
bool onany[MAXM];
bool req[MAXM];
E e[2*MAXM]; int ne;
int seq[MAXM],nseq;

void sssp(int s,int chead[MAXN],int cnxt[MAXM],int cto[MAXM],ll d[MAXN]) {
	REP(i,n) d[i]=LLONG_MAX;
	PQ pq(n,d);
	pq.relax(s,0);
	while(!pq.empty()) {
		//pq.print();
		int at=pq.pop();
		//printf("%d = %lld\n",at,d[at]); 
		for(int x=chead[at];x!=-1;x=cnxt[x]) {
			ll nd=d[at]+len[x];
			if(nd<d[cto[x]]) pq.relax(cto[x],nd);
		}
	}
}

void run() {
	scanf("%d%d%d%d",&n,&m,&s,&t); --s,--t;
	REP(i,n) head[0][i]=head[1][i]=-1;
	REP(i,m) {
		scanf("%d%d%d",&from[i],&to[i],&len[i]); --from[i],--to[i];
		nxt[0][i]=head[0][from[i]]; head[0][from[i]]=i;
		nxt[1][i]=head[1][to[i]]; head[1][to[i]]=i;
	}

	sssp(s,head[0],nxt[0],to,d[0]);
	sssp(t,head[1],nxt[1],from,d[1]);

	REP(i,m) onany[i]=d[0][from[i]]+len[i]+d[1][to[i]]==d[0][t],req[i]=false;
	ne=0; REP(i,m) if(onany[i]) e[ne].val=d[0][from[i]],e[ne].idx=i,e[ne].type=+1,++ne,e[ne].val=d[0][from[i]]+len[i],e[ne].idx=i,e[ne].type=-1,++ne;
	sort(e,e+ne);

//	REP(i,ne) printf("%d: %d %d %d\n",i,e[i].val,e[i].type,e[i].idx);
	int val=0;
	REP(i,ne) {
		val+=e[i].type;
		if(val==1&&e[i].type==+1&&(i-1<0||e[i-1].val!=e[i].val||e[i-1].type!=+1)&&(i+1>=ne||e[i+1].val!=e[i].val||e[i+1].type!=+1)) req[e[i].idx]=true;
	}

	REP(i,m) {
		if(req[i]) printf("YES\n");
		else if(d[0][from[i]]==LLONG_MAX||d[1][to[i]]==LLONG_MAX||d[0][from[i]]+d[1][to[i]]+1>=d[0][t]) printf("NO\n");
		else printf("CAN %I64d\n",len[i]-(d[0][t]-d[0][from[i]]-d[1][to[i]]-1));
	}
}

int main() {
	run();
	return 0;
}
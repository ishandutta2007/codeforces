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

const int MAXN=300000;
const int MAXE=MAXN-1;
const int MAXLOGN=18;
typedef struct X { int a,b,id; } X;
const bool operator<(const X &p,const X &q) { if(p.a!=q.a) return p.a<q.a; return p.b<q.b; }

int n,nq;
char letters[MAXN+1];
int fst[MAXN];
int nxt[2*MAXE],to[2*MAXE];

int h[MAXN];
int par[MAXN][MAXLOGN+1];
int ord[2*MAXN][MAXLOGN+1];

int q[MAXN],qhead,qtail;
X tmp[2*MAXN];

void init() {
	REP(i,n) h[i]=par[i][0]=-2;
	qhead=qtail=0; q[qhead++]=0; h[0]=0; par[0][0]=-1;
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=fst[at];x!=-1;x=nxt[x]) if(h[to[x]]==-2) {
			q[qhead++]=to[x]; h[to[x]]=h[at]+1; par[to[x]][0]=at;
		}
	}
	REP(k,MAXLOGN) REP(i,n) par[i][k+1]=par[i][k]==-1?-1:par[par[i][k]][k];
	REP(i,n) ord[i][0]=ord[i+n][0]=letters[i]-'a';
	REP(k,MAXLOGN) {
		REP(i,n) {
			tmp[i].id=i; tmp[i].a=ord[i][k]; tmp[i].b=par[i][k]==-1?-1:ord[par[i][k]][k];
			tmp[i+n].id=i+n; tmp[i+n].a=par[i][k]==-1?-1:ord[par[i][k]+n][k]; tmp[i+n].b=ord[i+n][k];
		}
		sort(tmp,tmp+2*n);
		//if(k==0) { REP(i,2*n) printf("[%d,%d,%d]",tmp[i].id,tmp[i].a,tmp[i].b); puts(""); }
		int cnt=0; REP(i,2*n) ord[tmp[i].id][k+1]=i!=0&&tmp[i].a==tmp[i-1].a&&tmp[i].b==tmp[i-1].b?cnt-1:cnt++;
	}
}

int up(int a,int n) {
	for(int k=0;(1<<k)<=n;++k) if(n&(1<<k)) a=par[a][k];
	return a;
}

int lca(int a,int b) {
	if(h[a]>h[b]) swap(a,b);
	b=up(b,h[b]-h[a]);
	for(int k=MAXLOGN;k>=0;--k) if(par[a][k]!=par[b][k]) a=par[a][k],b=par[b][k];
	return a==b?a:par[a][0];
}

int lcp(int a,int b,int len) {
	if(len==0) return 0;
	int ret=0;
	for(int k=MAXLOGN;k>=0;--k) {
		if(ret+(1<<k)>len) continue;
		int aa=a<n?a:up(a-n,len-ret-(1<<k))+n;
		int bb=b<n?b:up(b-n,len-ret-(1<<k))+n;
		if(ord[aa][k]==ord[bb][k]) {
			if(a<n) a=par[a][k]; if(b<n) b=par[b][k];
			ret+=1<<k;
		}
	}
	return ret;
}

int calc(int a,int b,int c,int d) {
	int ab=lca(a,b),cd=lca(c,d),d1,d2;
	d1=h[a]-h[ab],d2=h[c]-h[cd];
	if(d1>d2) { swap(a,c); swap(b,d); swap(ab,cd); swap(d1,d2); }
	int ret=0,cur;
	cur=lcp(a,c,d1); ret+=cur; if(cur!=d1) return ret;
	c=up(c,d1);
	d1=h[b]-h[ab]+1,d2=h[c]-h[cd]+1;
	if(d1<=d2) {
		cur=lcp(b+n,c,d1); ret+=cur; return ret;
	} else {
		int e=up(b,d1-d2);
		cur=lcp(e+n,c,d2); ret+=cur; if(cur!=d2) return ret;
		d1=h[b]-h[e],d2=h[d]-h[cd];
		if(d1<=d2) {
			d=up(d,d2-d1);
			cur=lcp(b+n,d+n,d1); ret+=cur; return ret;
		} else {
			b=up(b,d1-d2);
			cur=lcp(b+n,d+n,d2); ret+=cur; return ret;
		}
	}
}

void run() {
	scanf("%d",&n);
	scanf("%s",letters);
	REP(i,n) fst[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}
	init();
	//REPE(k,MAXLOGN) { REP(i,2*n) printf("%d ",ord[i][k]); puts(""); }

	scanf("%d",&nq);
	REP(qi,nq) {
		int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d); --a,--b,--c,--d;
		int cur=calc(a,b,c,d);
		printf("%d\n",cur);
	}

}

int main() {
	run();
	return 0;
}
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;
const int MAXNODES=15000000;
typedef struct B { int l,r; } B;
bool operator<(const B &a,const B &b) { return a.r<b.r; }

typedef struct Node { int l,r; int minval,lazy; } Node;

int n,dt;
B b[MAXN];

Node nodes[MAXNODES]; int nnode;

int create(int minval) {
	assert(nnode<MAXNODES);
	nodes[nnode].l=nodes[nnode].r=-1,nodes[nnode].minval=minval,nodes[nnode].lazy=0; return nnode++;
}
void push(int x) {
	if(nodes[x].l==-1) nodes[x].l=create(nodes[x].minval); else nodes[nodes[x].l].minval+=nodes[x].lazy,nodes[nodes[x].l].lazy+=nodes[x].lazy;
	if(nodes[x].r==-1) nodes[x].r=create(nodes[x].minval); else nodes[nodes[x].r].minval+=nodes[x].lazy,nodes[nodes[x].r].lazy+=nodes[x].lazy;
	nodes[x].lazy=0;
}

int getmin(int x,int l,int r,int BOUND) {
	if(r<=BOUND) return nodes[x].minval;
	if(nodes[x].l==-1&&nodes[x].r==-1) return nodes[x].minval;
	int m=l+(r-l)/2; push(x);
	if(BOUND<=m) return getmin(nodes[x].l,l,m,BOUND);
	int ret=getmin(nodes[x].r,m+1,r,BOUND);
	if(nodes[nodes[x].l].minval<ret) ret=nodes[nodes[x].l].minval;
	return ret;
}

pair<int,int> getfirst(int x,int l,int r,int VAL) {
	if(nodes[x].minval>VAL) return MP(-1,-1);
	if(nodes[x].l==-1&&nodes[x].r==-1) return MP(l,nodes[x].minval);
	int m=l+(r-l)/2; push(x);
	if(nodes[nodes[x].l].minval<=VAL) return getfirst(nodes[x].l,l,m,VAL);
	if(nodes[nodes[x].r].minval<=VAL) return getfirst(nodes[x].r,m+1,r,VAL);
	assert(false);
}

void inc(int x,int l,int r,int BOUND) {
	if(r<=BOUND) { nodes[x].minval++; nodes[x].lazy++; return; }
	int m=l+(r-l)/2; push(x);
	inc(nodes[x].l,l,m,BOUND); if(BOUND>m) inc(nodes[x].r,m+1,r,BOUND);
	nodes[x].minval=min(nodes[nodes[x].l].minval,nodes[nodes[x].r].minval);
}

void setval(int x,int l,int r,int BOUND,int VAL) {
	if(l>=BOUND) { nodes[x].l=nodes[x].r=-1,nodes[x].minval=VAL,nodes[x].lazy=0; return; }
	int m=l+(r-l)/2; push(x);
	if(BOUND<=m) setval(nodes[x].l,l,m,BOUND,VAL); setval(nodes[x].r,m+1,r,BOUND,VAL);
	nodes[x].minval=min(nodes[nodes[x].l].minval,nodes[nodes[x].r].minval);
}

void printtree(int x,int l,int r,int d=0) {
	int m=l+(r-l)/2;
	if(nodes[x].l!=-1) printtree(nodes[x].l,l,m,d+1);
	REP(i,d) printf("   "); printf("%d..%d -> %d (%d)\n",l,r,nodes[x].minval,nodes[x].lazy);
	if(nodes[x].r!=-1) printtree(nodes[x].r,m+1,r,d+1);
}



void run() {
	scanf("%d%d",&n,&dt);
	REP(i,n) scanf("%d%d",&b[i].l,&b[i].r);
	REP(i,n) if(b[i].l<0) b[i].l=0;
	sort(b,b+n);

	nnode=0; int root=create(0),tl=-1000000000,tr=1000000000;
	int tmax=0,ret=n;
	REP(i,n) {
		if(b[i].r<0) { --ret; continue; }
		if(tmax<b[i].r) {
			int vmin=getmin(root,tl,tr,tmax+1-dt);
			setval(root,tl,tr,tmax+1,vmin);
			while(true) {
				pair<int,int> nxt=getfirst(root,tl,tr,vmin-1);
				if(nxt.first==-1||nxt.first+dt>b[i].r) break;
				setval(root,tl,tr,nxt.first+dt,nxt.second);
				vmin=nxt.second;
			}
			tmax=b[i].r;
		}
		inc(root,tl,tr,b[i].l-1);
		//printf("after %d..%d\n",b[i].l,b[i].r); printtree(root,tl,tr);
	}
	ret-=getmin(root,tl,tr,tmax);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
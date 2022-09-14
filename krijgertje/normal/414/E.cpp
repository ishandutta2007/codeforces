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

typedef struct X {
	int id;
	int parent,childs[2];
	int nodedepth;
	int mintreedepth,maxtreedepth,treesize;
	int deltadepth;
} X;

int nx;
X x[2000000];

void print(int a,int d=0) {
	if(a==-1) return;
	print(x[a].childs[0],d+1);
	REP(i,2*d) printf(" "); printf("%d (size=%d,depth=%d,min=%d,max=%d,delta=%d) [parent=%d]\n",x[a].id,x[a].treesize,x[a].nodedepth,x[a].mintreedepth,x[a].maxtreedepth,x[a].deltadepth,x[a].parent);
	print(x[a].childs[1],d+1);
}
void printroot(int a) {
	while(x[a].parent!=-1) a=x[a].parent; print(a,0); puts("");
}

int create(int id,int depth) {
	x[nx].id=id; x[nx].parent=x[nx].childs[0]=x[nx].childs[1]=-1; x[nx].nodedepth=x[nx].mintreedepth=x[nx].maxtreedepth=depth; x[nx].treesize=1; x[nx].deltadepth=0;
	return nx++;
}

void adddepth(int a,int deltadepth) {
	assert(a!=-1);
	x[a].nodedepth+=deltadepth;
	x[a].mintreedepth+=deltadepth;
	x[a].maxtreedepth+=deltadepth;
	x[a].deltadepth+=deltadepth;
}

void push(int a) {
	assert(a!=-1);
	if(x[a].deltadepth==0) return;
	REP(z,2) if(x[a].childs[z]!=-1) adddepth(x[a].childs[z],x[a].deltadepth);
	x[a].deltadepth=0;
}

void calc(int a) {
	assert(a!=-1);
	push(a);
	x[a].treesize=1;
	x[a].mintreedepth=x[a].maxtreedepth=x[a].nodedepth;
	REP(z,2) if(x[a].childs[z]!=-1) {
		int b=x[a].childs[z];
		x[a].treesize+=x[b].treesize;
		if(x[b].mintreedepth<x[a].mintreedepth) x[a].mintreedepth=x[b].mintreedepth;
		if(x[b].maxtreedepth>x[a].maxtreedepth) x[a].maxtreedepth=x[b].maxtreedepth;
	}
}

int disconnect(int a,int z) {
	assert(a!=-1);
	assert(x[a].parent==-1);
	int b=x[a].childs[z];
	if(b!=-1) {
		push(a);
		x[a].childs[z]=-1;
		x[b].parent=-1;
		calc(a);
	}
	return b;
}

void connect(int a,int z,int b) {
	assert(a!=-1);
	assert(x[a].parent==-1);
	assert(x[a].childs[z]==-1);
	if(b!=-1) {
		assert(x[b].parent==-1);
		push(a);
		x[a].childs[z]=b;
		x[b].parent=a;
		calc(a);
	}
}

int childindex(int a,int b) {
//	printf("childindex(%d,%d)\n",a,b);
	assert(a!=-1);
	assert(b!=-1);
	if(x[a].childs[0]==b) return 0;
	if(x[a].childs[1]==b) return 1;
	assert(false);
	return -1;
}

void rotate(int a,int z) {
	int b=x[a].childs[z];
//	printf("rotate(%d,%d)\n",a,b);
	assert(a!=-1);
	assert(b!=-1);
	push(a);
	push(b);
	x[b].parent=x[a].parent; if(x[b].parent!=-1) { x[x[b].parent].childs[childindex(x[b].parent,a)]=b; }
	x[a].childs[z]=x[b].childs[1-z]; if(x[a].childs[z]!=-1) x[x[a].childs[z]].parent=a;
	x[b].childs[1-z]=a; x[a].parent=b;
	calc(a);
	calc(b);
//	int c=a; /*while(x[c].parent!=-1) c=x[c].parent; */ print(c,0); puts(""); print(x[c].parent,0); printf("%d %d %d\n",c,x[c].parent,x[x[c].parent].parent);
}

void splay(int a) {
	assert(a!=-1);
	while(x[a].parent!=-1) {
		int b=x[a].parent,zb=childindex(b,a);
		if(x[b].parent==-1) { rotate(b,zb); continue; }
		int c=x[b].parent,zc=childindex(c,b);
		if(zb==zc) { rotate(c,zc); rotate(b,zb); }
		else { rotate(b,zb); rotate(c,zc); }
	}
}

int getpos(int a) { 
	assert(a!=-1);
	return x[a].childs[0]==-1?0:x[x[a].childs[0]].treesize; 
}

int getmin(int a) {
	splay(a);
	while(x[a].childs[0]!=-1) a=x[a].childs[0];
	splay(a);
	return a;
}

int getmax(int a) {
	splay(a);
	while(x[a].childs[1]!=-1) a=x[a].childs[1];
	splay(a);
	return a;
}


int fstx[100000],lstx[100000];

int calcdist(int u,int v) {
	int a=fstx[u],b=fstx[v],ret=0;
	splay(a); ret+=x[a].nodedepth; int apos=getpos(a);
	splay(b); ret+=x[b].nodedepth; int bpos=getpos(b);
	if(apos>bpos) { swap(a,b); swap(apos,bpos); }
	
	splay(a); int left=disconnect(a,0);
	splay(b); int rght=disconnect(b,1);
	ret-=2*x[b].mintreedepth;
	connect(b,1,rght);
	splay(a);
	connect(a,0,left);

	return ret;
}

int finddepth(int a,int k) {
	assert(a!=-1);
	splay(a);
	if(k<x[a].mintreedepth||k>x[a].maxtreedepth) return -1;
	while(true) {
		push(a);
		int l=x[a].childs[0],r=x[a].childs[1];
		if(r!=-1&&x[r].mintreedepth<=k&&k<=x[r].maxtreedepth) { a=r; continue; }
		else if(x[a].nodedepth==k) { splay(a); return x[a].id; }
		else { assert(l!=-1&&x[l].mintreedepth<=k&&k<=x[l].maxtreedepth); a=l; continue; }
	}
}

void move(int u,int k) {
//	printf("moving node %d up %d levels\n",u,k);
	int a=fstx[u],b=lstx[u];
	
	splay(b); int rght=disconnect(b,1);
	splay(a); int left=disconnect(a,0);
	adddepth(a,-k);

/*	printf("after splitting for removal\n");
	printroot(left);
	printroot(a);
	printroot(rght); */

	int v=finddepth(left,x[a].nodedepth-1); assert(v!=-1);
	left=getmax(left);
	rght=getmin(rght);
	if(lstx[x[rght].id]==rght) lstx[x[rght].id]=left;
	rght=disconnect(rght,1);
	connect(left,1,rght);

/*	printf("after removal\n");
	printroot(lstx[v]); */

	rght=lstx[v];
	splay(rght);
	left=disconnect(rght,0);
	int d=create(v,x[rght].nodedepth);

/*	printf("before splitting for reconnecting\n");
	printroot(left);
	printroot(d);
	printroot(a);
	printroot(rght); */

	connect(d,0,left);
	connect(a,0,d);
	connect(rght,0,a);

/*	printf("after reconnecting\n");
	printroot(a); */
}


int n,m,nq;
int fst[100000];
int cnt[100000];
int to[100000];

int lastnode;
int addnode(int at,int depth) {
	int a=create(at,depth);
	if(lastnode==-1) return lastnode=a;
//	int b=lastnode; while(x[b].parent!=-1) b=x[b].parent; print(b); puts("");
	splay(lastnode);
	connect(lastnode,1,a);
	return lastnode=a;
}
void dfs(int at,int depth) {
	fstx[at]=lstx[at]=addnode(at,depth);
	REP(i,cnt[at]) {
		dfs(to[fst[at]+i],depth+1);
		lstx[at]=addnode(at,depth);
	}
}

void run() {
	scanf("%d%d",&n,&nq); m=0;
	REP(i,n) {
		scanf("%d",&cnt[i]); fst[i]=m;
		REP(j,cnt[i]) { scanf("%d",&to[m]); to[m]--; ++m; }
	}
	lastnode=-1;
	dfs(0,0);

	REP(i,nq) {
		int type; scanf("%d",&type);
		if(type==1) {
			int v,u; scanf("%d%d",&v,&u); --v,--u;
			printf("%d\n",calcdist(v,u));
		}
		if(type==2) {
			int v,k; scanf("%d%d",&v,&k); --v; --k;
			move(v,k);
		}
		if(type==3) {
			int k; scanf("%d",&k);
			printf("%d\n",finddepth(0,k)+1);
		}
		//printroot(lastnode);
	}

/*	REP(i,n) FOR(j,i+1,n) {
		printf("%d to %d: %d\n",i,j,calcdist(i,j));
		int a=lastnode; while(x[a].parent!=-1) a=x[a].parent; print(a,0); puts("");
	}*/

	//REP(i,n) printf("%d: %d\n",i,finddepth(0,i));

/*
	splay(lastnode);
	print(lastnode);
	puts("");
	REP(i,nx) {
		splay(i);
		print(i);
		puts("");
	} */
}

int main() {
	run();
	return 0;
}
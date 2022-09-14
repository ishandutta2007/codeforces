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
	int parent,childs[2];
	int nodeval;
	ll treesum; int maxtreeval;
	X() {}
	X(int val) { parent=childs[0]=childs[1]=-1; nodeval=treesum=maxtreeval=val; }
} X;

int nx,root;
X x[100000];

void print(int a,int d=0) {
	if(a==-1) return;
	print(x[a].childs[0],d+1);
	REP(i,2*d) printf(" "); printf("%d (nodeval=%d,treesum=%lld,maxtreeval=%d) [parent=%d]\n",a,x[a].nodeval,x[a].treesum,x[a].maxtreeval);
	print(x[a].childs[1],d+1);
}
void printroot(int a) {
	while(x[a].parent!=-1) a=x[a].parent; print(a,0); puts("");
}

void push(int a) {
	assert(a!=-1);
}

void calc(int a) {
	assert(a!=-1);
	push(a);
	x[a].treesum=x[a].nodeval;
	x[a].maxtreeval=x[a].nodeval;
	REP(z,2) if(x[a].childs[z]!=-1) {
		int b=x[a].childs[z];
		x[a].treesum+=x[b].treesum;
		if(x[b].maxtreeval>x[a].maxtreeval) x[a].maxtreeval=x[b].maxtreeval;
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
	assert(a!=-1);
	assert(b!=-1);
	if(x[a].childs[0]==b) return 0;
	if(x[a].childs[1]==b) return 1;
	assert(false);
	return -1;
}

void rotate(int a,int z) {
	int b=x[a].childs[z];
	assert(a!=-1);
	assert(b!=-1);
	push(a);
	push(b);
	x[b].parent=x[a].parent; if(x[b].parent!=-1) { x[x[b].parent].childs[childindex(x[b].parent,a)]=b; }
	x[a].childs[z]=x[b].childs[1-z]; if(x[a].childs[z]!=-1) x[x[a].childs[z]].parent=a;
	x[b].childs[1-z]=a; x[a].parent=b;
	calc(a);
	calc(b);
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

int getlast(int a) {
	splay(a);
	while(x[a].childs[1]!=-1) a=x[a].childs[1];
	splay(a);
	return a;
}


int getmaxnode(int a) {
	splay(a);
	while(true) {
		int b=x[a].childs[0],c=x[a].childs[1];
		if(b==-1||c!=-1&&x[c].maxtreeval>x[b].maxtreeval) b=c;
		if(b==-1||x[a].nodeval>=x[b].maxtreeval) break;
		a=b;
	}
	splay(a);
	return a;
}

void setval(int a,int val) {
	splay(a);
	x[a].nodeval=val;
	calc(a);
}

ll getsum(int a,int b) {
//	printroot(root); puts("");
	splay(a); int left=disconnect(a,0);
	splay(b); int rght=disconnect(b,1);
	ll ret=x[b].treesum;
	splay(b); connect(b,1,rght);
	splay(a); connect(a,0,left);
	return ret;
}

void domod(int a,int b,int mod) {
	splay(a); int left=disconnect(a,0);
	splay(b); int rght=disconnect(b,1);
	int c=getmaxnode(b);
	while(x[c].nodeval>=mod) {
		setval(c,x[c].nodeval%mod);
		c=getmaxnode(c);
	}
	splay(b); connect(b,1,rght);
	splay(a); connect(a,0,left);
}

void addnode(int a) {
	if(root==-1) { root=a; return; }
	root=getlast(root);
	connect(root,1,a);
}

void run() {
	int nq; scanf("%d%d",&nx,&nq);
	root=-1; REP(i,nx) { int val; scanf("%d",&val); x[i]=X(val); addnode(i); }
	REP(i,nq) {
		int type; scanf("%d",&type);
		if(type==1) {
			int l,r; scanf("%d%d",&l,&r); --l,--r;
			cout<<getsum(l,r)<<endl;
		} else if(type==2) {
			int l,r,x; scanf("%d%d%d",&l,&r,&x); --l,--r;
			domod(l,r,x);
		} else if(type==3) {
			int k,x; scanf("%d%d",&k,&x); --k;
			setval(k,x);
		}
	}
}

int main() {
	run();
	return 0;
}
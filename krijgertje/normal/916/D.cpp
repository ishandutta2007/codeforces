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

const int MAXQ=100000;
const int MAXPRIO=1000000000;

struct PNode {
	int l,r,val;
	PNode():l(-1),r(-1),val(-1) {}
	PNode(int val):l(-1),r(-1),val(val) {}
};
struct SNode {
	int l,r,cnt;
	SNode():l(-1),r(-1),cnt(0) {}
};

vector<PNode> p;
int proot[MAXQ+1];

vector<SNode> s;
int sroot[MAXQ+1];

int pbuild(int l,int r) {
	p.PB(PNode(-1)); int ret=SZ(p)-1;
	if(l!=r) {
		int m=l+(r-l)/2;
		{ int res=pbuild(l,m); p[ret].l=res; }
		{ int res=pbuild(m+1,r); p[ret].r=res; }
	}
	return ret;
}
int pget(int x,int l,int r,int IDX) {
	if(l==r) return p[x].val;
	int m=l+(r-l)/2;
	return IDX<=m?pget(p[x].l,l,m,IDX):pget(p[x].r,m+1,r,IDX);
}
int pset(int x,int l,int r,int IDX,int VAL) {
	p.PB(PNode(-1)); int ret=SZ(p)-1;
	if(l==r) {
		p[ret].val=VAL;
	} else {
		int m=l+(r-l)/2;
		p[ret].l=p[x].l,p[ret].r=p[x].r;
		if(IDX<=m) { int res=pset(p[ret].l,l,m,IDX,VAL); p[ret].l=res; }
		else { int res=pset(p[ret].r,m+1,r,IDX,VAL); p[ret].r=res; }
	}
	return ret;
}
void pprint(int x,int l,int r) {
	if(l==r) {
		if(p[x].val!=-1) printf(" %d=%d",l,p[x].val);
	} else {
		int m=l+(r-l)/2;
		pprint(p[x].l,l,m);
		pprint(p[x].r,m+1,r);
	}
}
int screate() { s.PB(SNode()); return SZ(s)-1; }
int smod(int x,int l,int r,int IDX,int BY) {
	int ret=screate();
	if(l==r) {
		s[ret].cnt=(x==-1?0:s[x].cnt)+BY;
	} else {
		if(x!=-1) s[ret].l=s[x].l,s[ret].r=s[x].r;
		int m=l+(r-l)/2;
		if(IDX<=m) { int res=smod(s[ret].l,l,m,IDX,BY); s[ret].l=res; }
		if(m+1<=IDX) { int res=smod(s[ret].r,m+1,r,IDX,BY); s[ret].r=res; }
		s[ret].cnt=(s[ret].l==-1?0:s[s[ret].l].cnt)+(s[ret].r==-1?0:s[s[ret].r].cnt);
	}
	return ret;
}
int sget(int x,int l,int r,int L,int R) {
	if(x==-1) return 0;
	if(L<=l&&r<=R) return s[x].cnt;
	int m=l+(r-l)/2;
	int ret=0;
	if(L<=m) ret+=sget(s[x].l,l,m,L,R);
	if(m+1<=R) ret+=sget(s[x].r,m+1,r,L,R);
	return ret;
}


int nq;
map<string,int> mp;
char op[10],name[20];

int getid() {
	if(mp.count(name)) return mp[name];
	int ret=SZ(mp); return mp[name]=ret;
}

void run() {
	scanf("%d",&nq);
	mp.clear();
	proot[0]=pbuild(0,nq-1);
	sroot[0]=screate();
	REP(i,nq) {
		scanf("%s",op);
		proot[i+1]=proot[i];
		sroot[i+1]=sroot[i];
		if(strcmp(op,"set")==0) {
			int val; scanf("%s%d",name,&val); int id=getid();
			int was=pget(proot[i+1],0,nq-1,id);
			proot[i+1]=pset(proot[i+1],0,nq-1,id,val);
			if(was!=-1) sroot[i+1]=smod(sroot[i+1],0,MAXPRIO,was,-1);
			if(val!=-1) sroot[i+1]=smod(sroot[i+1],0,MAXPRIO,val,+1);
		}
		if(strcmp(op,"query")==0) {
			scanf("%s",name); int id=getid();
			int was=pget(proot[i+1],0,nq-1,id);
			int ans=was==-1?-1:sget(sroot[i+1],0,MAXPRIO,0,was-1);
			printf("%d\n",ans); fflush(stdout);
		}
		if(strcmp(op,"remove")==0) {
			scanf("%s",name); int id=getid();
			int was=pget(proot[i+1],0,nq-1,id);
			proot[i+1]=pset(proot[i+1],0,nq-1,id,-1);
			if(was!=-1) sroot[i+1]=smod(sroot[i+1],0,MAXPRIO,was,-1);
		}
		if(strcmp(op,"undo")==0) {
			int cnt; scanf("%d",&cnt);
			proot[i+1]=proot[i-cnt];
			sroot[i+1]=sroot[i-cnt];
		}
		//printf("p%d:",i+1); pprint(proot[i+1],0,nq-1); puts("");
	}
}

int main() {
	run();
	return 0;
}
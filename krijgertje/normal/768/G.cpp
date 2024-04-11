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

int n,root;
int chead[MAXN],cnxt[MAXN];
int sz[MAXN];
int ret[MAXN];
map<int,int> csz,psz,osz,tsz; // childsizes, parentsizes, othersizes, tmpsizes

void init(int at) {
	sz[at]=1;
	for(int to=chead[at];to!=-1;to=cnxt[to]) {
		init(to);
		sz[at]+=sz[to];
	}
	osz[sz[at]]++;
}
void test(int at,map<int,int> &mp,int M,int m,int lim) { // find a node in mp with value x, so that max(lim,max(M-x,m+x)) is minimized
	//printf("test(%d,",at+1); for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it) { if(it!=mp.begin()) printf("|"); if(it->second!=1) printf("%d*",it->second); printf("%d",it->first); } printf(",%d,%d,%d)\n",M,m,lim);
	map<int,int>::iterator it=mp.lower_bound(1+(M-m)/2); // x>(M-m)/2
	{ int cur=max(lim,max(M,m)); ret[at]=min(ret[at],cur); }
	if(it!=mp.end()) { int cur=max(lim,max(M-it->first,m+it->first)); /*printf("\t%d->%d\n",it->first,cur);*/ ret[at]=min(ret[at],cur); }
	if(it!=mp.begin()) { --it; int cur=max(lim,max(M-it->first,m+it->first)); /*printf("\t%d->%d\n",it->first,cur);*/ ret[at]=min(ret[at],cur); }
}
void move(int at,map<int,int> &a,map<int,int> &b) {
	if(--a[sz[at]]==0) a.erase(sz[at]); ++b[sz[at]];
}
void moverec(int at,map<int,int> &a,map<int,int> &b) {
	move(at,a,b);
	for(int to=chead[at];to!=-1;to=cnxt[to]) moverec(to,a,b);
}
void go(int at,bool keep) { // When called, childsizes should be empty. When returning, childsizes should contain tree iff 'keep' is true
	move(at,osz,at==0?tsz:psz);
	int heavy=-1;
	int mxnonheavy=0,mxchild=0,mnchild=INT_MAX;
	for(int to=chead[at];to!=-1;to=cnxt[to]) {
		if(heavy==-1||sz[to]>sz[heavy]) {
			if(heavy!=-1) mxnonheavy=sz[heavy];
			heavy=to; mxchild=sz[to];
		} else if(sz[to]>mxnonheavy) {
			mxnonheavy=sz[to];
		}
		if(sz[to]<mnchild) mnchild=sz[to];
	}
	if(n-sz[at]>mxnonheavy) mxnonheavy=n-sz[at];
	for(int to=chead[at];to!=-1;to=cnxt[to]) if(to!=heavy) go(to,false);
	if(heavy!=-1) {
		go(heavy,true);
		int mnnonheavy=min(cnxt[chead[at]]==-1?INT_MAX:mnchild,sz[at]==n?INT_MAX:n-sz[at]);
		if(mnnonheavy!=INT_MAX) {
			move(heavy,csz,osz);
			test(at,csz,sz[heavy],mnnonheavy,mxnonheavy); // try moving a subtree from heavy child (childsizes)
			move(heavy,osz,csz);
		}
	}
	for(int to=chead[at];to!=-1;to=cnxt[to]) if(to!=heavy) moverec(to,osz,csz);
	move(at,at==0?tsz:psz,csz);
	if(mnchild!=INT_MAX) test(at,psz,n,mnchild-sz[at],mxchild); // try moving a subtree from a parent
	if(mnchild!=INT_MAX) test(at,osz,n-sz[at],mnchild,mxchild); // try moving a subtree from another node
	if(!keep) moverec(at,csz,osz);
}

void run() {
	scanf("%d",&n);
	root=-1; REP(i,n) chead[i]=-1; REP(i,n) { int a,b; scanf("%d%d",&a,&b); --a,--b; if(a==-1) cnxt[b]=-1,root=b; else cnxt[b]=chead[a],chead[a]=b; }
	csz.clear(); psz.clear(); osz.clear(); tsz.clear(); init(root);
	//REP(i,n) printf("sz[%d]=%d\n",i+1,sz[i]);
	REP(i,n) ret[i]=n-1; go(root,true);
	REP(i,n) printf("%d\n",ret[i]);
}

int main() {
	run();
	return 0;
}
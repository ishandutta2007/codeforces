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

const int MAXN=200000;
const int MAXLOGN=18;

int n;

typedef struct T {
	T *other;
	bool dead[MAXN-1];
	int to[2*(MAXN-1)];
	int killed[MAXN-1],nkilled;

	int firstedge[MAXN],nextedge[2*(MAXN-1)];
	int npos,firstpos[MAXN],lastpos[MAXN],atpos[MAXN];
	int firstval[2<<MAXLOGN],lastval[2<<MAXLOGN];
	int nval,val[2*(MAXN-1)*MAXLOGN+2*(MAXN-1)];

	void read() {
		memset(dead,false,sizeof(dead));
		memset(firstedge,-1,sizeof(firstedge));
		REP(i,n-1) {
			int a,b=i+1; scanf("%d",&a); --a;
			to[2*i+0]=b; nextedge[2*i+0]=firstedge[a]; firstedge[a]=2*i+0;
			to[2*i+1]=a; nextedge[2*i+1]=firstedge[b]; firstedge[b]=2*i+1;
		}
	}

	void dfs(int at,int prev) {
		firstpos[at]=npos; atpos[npos]=at; ++npos;
		for(int z=firstedge[at];z!=-1;z=nextedge[z]) if(to[z]!=prev) dfs(to[z],at);
		lastpos[at]=npos-1;
	}

	bool myvalcmp(const int &a,const int &b) const{
//		printf("\t\tcmp(%d,%d)\n",a,b);
		return firstpos[other->to[a]]<=firstpos[other->to[b]];
	}
	struct cmp { const T& t; cmp(const T &t):t(t) {} bool operator()(const int &a,const int &b) { return t.myvalcmp(a,b); } };

	void init(int x,int l,int r) {
		assert(x<(2<<MAXLOGN));
//		printf("initing %d=[%d,%d]\n",x,l,r);
		if(l==r) {
			firstval[x]=nval; lastval[x]=firstval[x]-1;
			for(int z=other->firstedge[atpos[l]];z!=-1;z=other->nextedge[z]) val[++lastval[x]]=z;
			nval=lastval[x]+1;
			assert(nval<2*(MAXN-1)*MAXLOGN);
			sort(val+firstval[x],val+lastval[x]+1,cmp(*this));
		} else {
			int m=(l+r)/2;
			init(2*x+1,l,m);
			init(2*x+2,m+1,r);
			firstval[x]=nval; lastval[x]=firstval[x]-1;
			int i=firstval[2*x+1],j=firstval[2*x+2];
			while(i<=lastval[2*x+1]&&j<=lastval[2*x+2]) if(myvalcmp(val[i],val[j])) val[++lastval[x]]=val[i++]; else val[++lastval[x]]=val[j++];
			while(i<=lastval[2*x+1]) val[++lastval[x]]=val[i++];
			while(j<=lastval[2*x+2]) val[++lastval[x]]=val[j++];
			nval=lastval[x]+1;
		}
//		printf("inited %d=[%d,%d]\n",x,l,r);
//		printval(x,l,r,4);
	}

	void init() {
		npos=nval=nkilled=0;
		dfs(0,-1);
		init(0,0,npos-1);
	}

	void printval(int x,int l,int r,int depth) {
		REP(i,depth) printf("  "); printf("%d=[%d,%d]:",x,l,r); FORE(i,firstval[x],lastval[x]) printf(" %d=%d->%d",val[i],other->to[val[i]^1],other->to[val[i]]); puts("");
		if(l!=r) {
			int m=(l+r)/2;
			printval(2*x+1,l,m,depth+1);
			printval(2*x+2,m+1,r,depth+1);
		}
	}
	void printval() { printval(0,0,npos-1,0); }

	void kill(int y) {
		if(other->dead[y]) return;
		other->dead[y]=true;
		other->killed[other->nkilled++]=y;
	}

	void go(int x,int l,int r,int a,int b) {
		if(r<a||l>b) return;
		//printf("going %d=[%d,%d] <%d,%d>\n",x,l,r,a,b);
		if(a<=l&&r<=b) {
			while(firstval[x]<=lastval[x]&&firstpos[other->to[val[firstval[x]]]]<a) kill(val[firstval[x]++]>>1);
			while(firstval[x]<=lastval[x]&&firstpos[other->to[val[lastval[x]]]]>b) kill(val[lastval[x]--]>>1);
		} else {
			int m=(l+r)/2;
			go(2*x+1,l,m,a,b);
			go(2*x+2,m+1,r,a,b);
		}
	}
	void go(int y) {
		int a=to[2*y+0],b=to[2*y+1];
		if(firstpos[a]>firstpos[b]) swap(a,b);
		go(0,0,npos-1,firstpos[b],lastpos[b]);
	}
} T;


T t[2];

void run() {
	scanf("%d",&n);
	REP(i,2) t[i].other=&t[1-i];
	REP(i,2) t[i].read();
	REP(i,2) t[i].init();
	//REP(i,2) { printf("Tree %d\n",i); t[i].printval(); }

	int firstkill; scanf("%d",&firstkill); firstkill--;
	t[1].kill(firstkill);
	
	int at=0;
	while(t[at].nkilled>0) {
		printf("%s\n",at==0?"Blue":"Red");
		sort(t[at].killed,t[at].killed+t[at].nkilled);
		REP(i,t[at].nkilled) { if(i!=0) printf(" "); printf("%d",t[at].killed[i]+1); } puts("");
		REP(i,t[at].nkilled) t[at].go(t[at].killed[i]);
		t[at].nkilled=0;
		at=1-at;
	}
}

int main() {
	run();
	return 0;
}
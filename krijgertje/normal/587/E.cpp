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

const int MAXN=200000;

typedef struct B {
	int v[31],nv;
	void clear() { nv=0; }
	void assign(int x) { /*printf("assigning %d\n",x);*/ nv=0; v[nv++]=x; }
	void insert(int x) { /*printf("inserting %d (%d) [%d]\n",x,nv,v[0]);*/ REP(i,nv) if(v[i]&-v[i]&x) x^=v[i]; if(x==0) return; REP(i,nv) if(x&-x&v[i]) v[i]^=x; v[nv++]=x; }
	void merge(B &b) { /*printf("merging %d and %d\n",nv,b.nv);*/ REP(i,b.nv) insert(b.v[i]); }
} B;

int n,nq;
int a[2*MAXN+1];
B b[2*MAXN];

void moda(int l,int r,int val) {
	for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
		if(l&1) a[l++]^=val;
		if(r&1) a[--r]^=val;
	}
}

int geta(int p) {
	int ret=0;
	for(p+=n;p>0;p>>=1) ret^=a[p];
	return ret;
}

void modb(int p,int val) {
	for(p+=n,b[p].assign(b[p].v[0]^val);p>1;p>>=1) { b[p>>1]=b[p]; b[p>>1].merge(b[p^1]); }
}

B getb(int l,int r) {
	B ret; ret.clear();
	for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
		if(l&1) ret.merge(b[l++]);
		if(r&1) ret.merge(b[--r]);
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&nq);
	FOR(i,1,n) a[i]=0; REP(i,n) scanf("%d",&a[n+i]); a[n+n]=0;
	REP(i,n) b[n+i].assign(a[n+i]^a[n+i+1]); for(int i=n-1;i>=1;--i) { b[i]=b[i<<1]; b[i].merge(b[i<<1|1]); }
	//printf("a:"); FOR(i,1,2*n) printf(" %d",a[i]); puts("");
	//printf("b:"); FOR(i,1,2*n) { printf(" ["); REP(j,b[i].nv) { if(j!=0) printf(","); printf("%d",b[i].v[j]); } printf("]"); } puts("");
	REP(qi,nq) {
		int type,l,r; scanf("%d%d%d",&type,&l,&r); --l;
		if(type==1) {
			int val; scanf("%d",&val);
			moda(l,r,val);
			if(l!=0) modb(l-1,val); modb(r-1,val);
			//printf("a:"); FOR(i,1,2*n) printf(" %d",a[i]); puts("");
			//printf("b:"); FOR(i,1,2*n) { printf(" ["); REP(j,b[i].nv) { if(j!=0) printf(","); printf("%d",b[i].v[j]); } printf("]"); } puts("");
		}
		if(type==2) {
			B curb=getb(l,r-1);
			int cura=geta(l);
			//printf("%d,[",cura); REP(j,curb.nv) { if(j!=0) printf(","); printf("%d",curb.v[j]); } printf("]");
			curb.insert(cura);
			//printf(" -> ["); REP(j,curb.nv) { if(j!=0) printf(","); printf("%d",curb.v[j]); } printf("]"); puts("");
			printf("%d\n",1<<curb.nv);
		}
	}
}

int main() {
	run();
	return 0;
}
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
#include <complex>
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

const int MAXN=2500;
const int MAXM=MAXN*(MAXN-1)/2;
typedef struct E { int a,b,c; } E;
bool operator<(const E &p,const E &q) { return p.c<q.c; }

int n;
int d[MAXN][MAXN];
E e[MAXM]; int m;

int p[MAXN];
int nxt[MAXN],lst[MAXN];

int find(int x) { if(p[x]<0) return x; return p[x]=find(p[x]); }
void unite(int x,int y) {
	if(-p[x]<-p[y]) swap(x,y);
	p[x]+=p[y]; p[y]=x;
	nxt[lst[x]]=y; lst[x]=lst[y];
}


bool test() {
	REP(i,n) if(d[i][i]!=0) return false;
	REP(i,n) FOR(j,i+1,n) if(d[i][j]!=d[j][i]) return false;
	m=0; REP(i,n) FOR(j,i+1,n) e[m].a=i,e[m].b=j,e[m].c=d[i][j],++m; sort(e,e+m);
	REP(i,n) p[i]=-1,nxt[i]=-1,lst[i]=i;
	REP(i,m) {
		int a=find(e[i].a),b=find(e[i].b);
		if(a==b) continue;
		for(int x=a;x!=-1;x=nxt[x]) for(int y=b;y!=-1;y=nxt[y]) if(e[i].c<d[x][y]) return false;
		unite(a,b);
	}
	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n) REP(j,n) scanf("%d",&d[i][j]);
	printf("%s\n",test()?"MAGIC":"NOT MAGIC");
}

int main() {
	run();
	return 0;
}
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
const int MAXM=200000;
typedef struct E { int a,b,c,idx; } E;
bool operator<(const E &p,const E &q) { return p.c<q.c; }

int n,m;
E e[MAXM];

int par[MAXN],sz[MAXN],val[MAXN];

ll ret;
int extra[MAXM];
int process(int a,int b,int c) {
	int mx=0; //int aa=a,bb=b;
	while((par[a]!=a||par[b]!=b)&&a!=b) { if(par[b]==b||par[a]!=a&&sz[a]<=sz[b]) mx=max(mx,val[a]),a=par[a]; else mx=max(mx,val[b]),b=par[b]; }
	//printf("%d %d -> %d %d\n",aa,bb,a,b);
	if(a==b) return c-mx;
	if(sz[a]<sz[b]) swap(a,b);
	sz[a]+=sz[b]; par[b]=a; val[b]=c; ret+=c;
	return 0;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c),--e[i].a,--e[i].b,e[i].idx=i;
	sort(e,e+m);

	ret=0; REP(i,n) par[i]=i,sz[i]=1;
	REP(i,m) extra[e[i].idx]=process(e[i].a,e[i].b,e[i].c);
	REP(i,m) printf("%I64d\n",ret+extra[i]);
}

int main() {
	run();
	return 0;
}
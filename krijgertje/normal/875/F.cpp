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

const int MAXA=200000;
const int MAXB=200000;
typedef struct B { int a1,a2,val; } B;
bool operator<(const B &p,const B &q) { return p.val>q.val; }

int na,nb;
B b[MAXB];

int par[MAXA],sz[MAXA]; bool istree[MAXA];
int find(int x) { if(par[x]==x) return x; return par[x]=find(par[x]); }
bool unite(int x,int y) {
	x=find(x),y=find(y);
	//printf("%d (%s) and %d (%s)\n",x,istree[x]?"tree":"cyc",y,istree[y]?"tree":"cyc");
	if(x==y) {
		if(!istree[x]) return false;
		istree[x]=false; return true;
	} else {
		if(!istree[x]&&!istree[y]) return false;
		if(!istree[x]||!istree[y]) istree[x]=istree[y]=false;
		if(sz[x]<sz[y]) swap(x,y);
		par[y]=x; sz[x]+=sz[y];
		return true;
	}
}

void run() {
	scanf("%d%d",&na,&nb);
	REP(i,nb) scanf("%d%d%d",&b[i].a1,&b[i].a2,&b[i].val),--b[i].a1,--b[i].a2;
	sort(b,b+nb);
	//REP(i,nb) printf("%d %d %d\n",b[i].a1,b[i].a2,b[i].val);
	REP(i,na) par[i]=i,sz[i]=1,istree[i]=true;
	ll ret=0;
	REP(i,nb) if(unite(b[i].a1,b[i].a2)) ret+=b[i].val;
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}
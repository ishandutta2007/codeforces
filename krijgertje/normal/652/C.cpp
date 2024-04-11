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

const int MAXN=300000;
const int MAXP=300000;
typedef struct P { int a,b; } P;
bool operator<(const P &u,const P &v) { return u.b<v.b; }

int n,np;
int x[MAXN],inv[MAXN];
bool dead[MAXN]; int head[MAXN],nxt[MAXP];
P p[MAXP];

void run() {
	scanf("%d%d",&n,&np);
	REP(i,n) scanf("%d",&x[i]),--x[i];
	REP(i,np) scanf("%d%d",&p[i].a,&p[i].b),--p[i].a,--p[i].b;
	REP(i,n) inv[x[i]]=i;
	REP(i,np) p[i].a=inv[p[i].a],p[i].b=inv[p[i].b];
	REP(i,np) if(p[i].a>p[i].b) swap(p[i].a,p[i].b);
	sort(p,p+np);
	REP(i,n) dead[i]=false,head[i]=-1; REP(i,np) { nxt[i]=head[p[i].a]; head[p[i].a]=i; }

	int at=0; ll ret=0;
	REP(i,n) {
		while(at<np&&dead[at]) ++at;
		ret+=(at<np?p[at].b:n)-i;
		for(int x=head[i];x!=-1;x=nxt[x]) dead[x]=true;
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}
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
const int MAXM=100000;

typedef struct S { int idx,num,den; } S;
bool operator<(const S &a,const S &b) { ll diff=(ll)a.num*b.den-(ll)b.num*a.den; if(diff!=0) return diff<0; return a.idx<b.idx; }

int n,m,nfort;
bool isfort[MAXN];
int head[MAXN],nxt[2*MAXM],to[2*MAXM];

S s[MAXN];
set<S> have;

S rets; int retcnt;
int order[MAXN],norder;

void run() {
	scanf("%d%d%d",&n,&m,&nfort);
	memset(isfort,false,sizeof(isfort));
	REP(i,nfort) { int x; scanf("%d",&x); --x; isfort[x]=true; }
	memset(head,-1,sizeof(head));
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a;
	}
	have.clear();
	REP(i,n) if(!isfort[i]) { s[i].idx=i,s[i].num=s[i].den=0; for(int x=head[i];x!=-1;x=nxt[x]) s[i].num+=!isfort[to[x]]?1:0,++s[i].den; have.insert(s[i]); }

	rets.num=-1,rets.den=1,rets.idx=-1,retcnt=0,norder=0;
	while(SZ(have)>0) {
		set<S>::iterator it=have.begin();
		if(rets<*it) { rets=*it; retcnt=SZ(have); }
		//printf("at=%d (%d/%d)\n",it->idx,it->num,it->den);
		int at=it->idx; have.erase(it); isfort[at]=true; order[norder++]=at;
		for(int x=head[at];x!=-1;x=nxt[x]) if(!isfort[to[x]]) {
			have.erase(s[to[x]]);
			s[to[x]].num--;
			have.insert(s[to[x]]);
		}
	}
	printf("%d\n",retcnt);
	REP(i,retcnt) { if(i!=0) printf(" "); printf("%d",order[norder-i-1]+1); } puts("");
}

int main() {
	run();
	return 0;
}
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
typedef struct E { int la,ra,lb,rb,c; } E;

int n,m,s;
E e[MAXM];

ll dplanet[MAXN];
ll dedge[MAXM];
priority_queue<pair<ll,int> > q;
set<int> todo;

int z[100],nz;
vector<int> sval[4*MAXN];
void sadd(int x,int l,int r,int L,int R,int VAL) {
	if(L<=l&&r<=R) { 
		//printf("[%d to %d..%d (%d,%d)]\n",VAL,l,r,L,R);
		sval[x].PB(VAL); return;
	}
	int m=l+(r-l)/2;
	if(L<=m) sadd(2*x+1,l,m,L,R,VAL);
	if(m+1<=R) sadd(2*x+2,m+1,r,L,R,VAL);
}
void sget(int x,int l,int r,int IDX) {
	z[nz++]=x;
	//printf("\t\t\t(%d..%d)\n",l,r);
	if(l==r) return;
	int m=l+(r-l)/2;
	if(IDX<=m) sget(2*x+1,l,m,IDX); else sget(2*x+2,m+1,r,IDX);
}

void process(int l,int r,ll c) {
	set<int>::iterator it=todo.lower_bound(l);
	while(it!=todo.end()&&*it<=r) {
		int at=*it;
		//printf("\tp%d=%lld\n",at,c);
		dplanet[at]=c;
		nz=0; sget(0,0,n-1,at);
		REP(i,nz) {
			int zz=z[i];
			REPSZ(j,sval[zz]) {
				int idx=sval[zz][j];
				ll nc=c+e[idx].c;
				//printf("\t\t->e%d=%lld\n",idx,nc);
				if(nc<dedge[idx]) { dedge[idx]=nc; q.push(MP(-nc,idx)); }
			}
			sval[zz].clear();
		}
		set<int>::iterator rem=it++; todo.erase(rem);
	}
}

void run() {
	scanf("%d%d%d",&n,&m,&s); --s;
	REP(i,m) {
		int t; scanf("%d",&t);
		if(t==1) { int v,u,w; scanf("%d%d%d",&v,&u,&w); --v,--u; e[i].la=e[i].ra=v; e[i].lb=e[i].rb=u; e[i].c=w; }
		if(t==2) { int v,l,r,w; scanf("%d%d%d%d",&v,&l,&r,&w); --v,--l,--r; e[i].la=e[i].ra=v; e[i].lb=l,e[i].rb=r; e[i].c=w; }
		if(t==3) { int v,l,r,w; scanf("%d%d%d%d",&v,&l,&r,&w); --v,--l,--r; e[i].la=l,e[i].ra=r; e[i].lb=e[i].rb=v; e[i].c=w; }
	}
	REP(i,4*n) sval[i].clear(); REP(i,m) sadd(0,0,n-1,e[i].la,e[i].ra,i);

	REP(i,n) dplanet[i]=LLONG_MAX; REP(i,m) dedge[i]=LLONG_MAX; q=priority_queue<pair<ll,int> >(); todo=set<int>(); REP(i,n) todo.insert(i);
	process(s,s,0);
	while(!q.empty()) {
		ll c=-q.top().first; int idx=q.top().second; q.pop();
		if(c>dedge[idx]) continue;
		process(e[idx].lb,e[idx].rb,c);
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%lld",dplanet[i]==LLONG_MAX?-1:dplanet[i]); } puts("");
}

int main() {
	run();
	return 0;
}
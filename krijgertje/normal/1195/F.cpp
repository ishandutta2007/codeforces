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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXPOL=100000;
const int MAXQ=100000;
const int MAXPTOT=300000;
struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
struct Q { int l,r,id; };
bool operator<(const Q &a,const Q &b) { return a.l>b.l; }

int npol;
vector<P> pol[MAXPOL];
int nq;
Q q[MAXQ];
int qans[MAXQ];


map<pair<int,int>,int> mp;
int lst[MAXPTOT],nlst;
int off[MAXPOL+1];

pair<int,int> o[MAXPTOT];
int nxt[MAXPTOT];

int bit[MAXPTOT+1];
void bmod(int idx,int by) { ++idx; while(idx<=nlst) { bit[idx]+=by; idx+=idx&-idx; } }
int bget(int idx) { ++idx; int ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }

void solve() {
	nlst=0; off[0]=0; mp.clear();
	REP(i,npol) {
		REPSZ(j,pol[i]) {
			P a=pol[i][j],b=pol[i][(j+1)%SZ(pol[i])];
			P d=b-a; int g=gcd(abs(d.x),abs(d.y)); d.x/=g,d.y/=g;
			pair<int,int> key=MP(d.x,d.y);
			int id; if(!mp.count(key)) { id=SZ(mp); mp[key]=id; } else id=mp[key];
			lst[nlst++]=id;
		}
		off[i+1]=nlst;
	}
	//printf("lst:"); REP(i,nlst) printf(" %d",lst[i]); puts("");
	REP(i,nlst) o[i]=MP(lst[i],i); sort(o,o+nlst); REP(i,nlst) nxt[o[i].second]=i+1<nlst&&o[i+1].first==o[i].first?o[i+1].second:-1;
	//printf("nxt:"); REP(i,nlst) printf(" %d",nxt[i]); puts("");

	sort(q,q+nq);
	int at=nlst; REPE(i,nlst) bit[i]=0;
	REP(i,nq) {
		int to=off[q[i].l];
		while(at>to) { --at; bmod(at,+1); if(nxt[at]!=-1) bmod(nxt[at],-1); }
		qans[q[i].id]=bget(off[q[i].r+1]-1);
	}
}

void run() {
	scanf("%d",&npol);
	REP(i,npol) { int cnt; scanf("%d",&cnt); pol[i]=vector<P>(cnt); REPSZ(j,pol[i]) scanf("%d%d",&pol[i][j].x,&pol[i][j].y); }
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d",&q[i].l,&q[i].r),--q[i].l,--q[i].r,q[i].id=i;
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}
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

const int MAXN=3000;
typedef struct P { int x,y; } P;
typedef struct Q { int idx,y; } Q;
bool operator<(const P &a,const P &b) { return a.x<b.x; }
bool operator<(const Q &a,const Q &b) { return a.y<b.y; }

int h,w,n,want;
P p[MAXN];
Q q[MAXN]; int nq;

int prv[MAXN],nxt[MAXN],sy[MAXN],yy[MAXN],ty[MAXN];
ll calc(int idx) { return (ll)(yy[idx]-sy[idx]+1)*(w-ty[idx]); }

void input() {
	scanf("%d%d%d%d",&h,&w,&n,&want);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].y),--p[i].x,--p[i].y;
}

ll calc() {
	sort(p,p+n);
	ll ret=0;
	REP(sx,h) {
		nq=0; REP(i,n) if(p[i].x>=sx) q[nq].idx=i,q[nq].y=p[i].y,++nq; sort(q,q+nq);
		ll cur=0; // sum((yy-sy+1)*(w-ty)), ty=yy[nxt{want-1}]
		REP(i,nq) {
			int idx=q[i].idx;
			prv[idx]=i-1<0?-1:q[i-1].idx,nxt[idx]=i+1>=nq?-1:q[i+1].idx,sy[idx]=i==0?0:q[i-1].y+1,yy[idx]=q[i].y,ty[idx]=i+want-1>=nq?w:q[i+want-1].y;
			cur+=calc(idx);
		}
		int at=n-1,fst=nq==0?-1:q[0].idx;
		for(int tx=h;tx>sx;--tx) {
			while(at>=0&&p[at].x==tx) {
				//printf("\tremoving(%d,%d)\n",p[at].x,p[at].y);
				cur-=calc(at);
				if(nxt[at]!=-1) {
					cur-=calc(nxt[at]);
					sy[nxt[at]]=sy[at];
					cur+=calc(nxt[at]);
					prv[nxt[at]]=prv[at];
				}
				if(prv[at]!=-1) nxt[prv[at]]=nxt[at];
				if(fst==at) fst=nxt[at];
				if(want!=1) for(int a=prv[at],b=prv[at],d=0;a!=-1;a=prv[a],++d) {
					while(nxt[b]!=-1&&d<want-1) b=nxt[b],++d;
					if(d>want-1) if(prv[b]==prv[at]) break; else b=prv[b],--d;
					cur-=calc(a);
					ty[a]=d==want-1?yy[b]:w;
					cur+=calc(a);
				}
				--at;
			}
			//printf("%d..%d:",sx,tx-1); for(int i=fst;i!=-1;i=nxt[i]) printf(" [%d..%d/%d]",sy[i],yy[i],ty[i]); printf(" = %lld\n",cur);
			ret+=cur;
		}
	}
	return ret;
}
void run() {
	input();
	ll ret=calc();
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}
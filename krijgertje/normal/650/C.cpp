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

const int MAXN=1000000;

int h,w,n;
int a[MAXN];
int b[MAXN];


int p[MAXN];
bool done[MAXN];
bool acmp(const int &x,const int &y) { if(a[x]!=a[y]) return a[x]<a[y]; return x<y; }

int cur[MAXN],ncur;
int rmx[MAXN],cmx[MAXN];
int lt[MAXN],rt[MAXN],up[MAXN],dn[MAXN],r[MAXN],nr;

void run() {
	scanf("%d%d",&h,&w); n=h*w; REP(i,n) scanf("%d",&a[i]);
	REP(i,n) p[i]=i,done[i]=false; sort(p,p+n,acmp);
	REP(x,h) {
		nr=0; REP(y,w) r[nr++]=x*w+y; sort(r,r+nr,acmp);
		REP(i,nr) lt[r[i]]=i==0||a[r[i-1]]!=a[r[i]]?-1:r[i-1];
		REP(i,nr) rt[r[i]]=i+1>=nr||a[r[i+1]]!=a[r[i]]?-1:r[i+1];
	}
	REP(y,w) {
		nr=0; REP(x,h) r[nr++]=x*w+y; sort(r,r+nr,acmp);
		REP(i,nr) up[r[i]]=i==0||a[r[i-1]]!=a[r[i]]?-1:r[i-1];
		REP(i,nr) dn[r[i]]=i+1>=nr||a[r[i+1]]!=a[r[i]]?-1:r[i+1];
	}
	REP(x,h) rmx[x]=0; REP(y,w) cmx[y]=0;
	REP(i,n) if(!done[p[i]]) {
		ncur=0; cur[ncur++]=p[i]; done[p[i]]=true; int val=1;
		REP(j,ncur) {
			int idx=cur[j],x=idx/w,y=idx%w;
			if(lt[idx]!=-1&&!done[lt[idx]]) cur[ncur++]=lt[idx],done[lt[idx]]=true;
			if(rt[idx]!=-1&&!done[rt[idx]]) cur[ncur++]=rt[idx],done[rt[idx]]=true;
			if(up[idx]!=-1&&!done[up[idx]]) cur[ncur++]=up[idx],done[up[idx]]=true;
			if(dn[idx]!=-1&&!done[dn[idx]]) cur[ncur++]=dn[idx],done[dn[idx]]=true;
			if(rmx[x]+1>val) val=rmx[x]+1; if(cmx[y]+1>val) val=cmx[y]+1;
		}
		//REP(j,ncur) printf(" %d",cur[j]); puts("");
		REP(j,ncur) { int idx=cur[j],x=idx/w,y=idx%w; b[idx]=val; if(val>rmx[x]) rmx[x]=val; if(val>cmx[y]) cmx[y]=val; }
	}
	REP(x,h) { REP(y,w) { if(y!=0) printf(" "); printf("%d",b[x*w+y]); } puts(""); }
}

int main() {
	run();
	return 0;
}
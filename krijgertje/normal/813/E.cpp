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
const int MAXLG=17;
const int MAXS=4*MAXN+(MAXLG+1)*2*MAXN;

int n,mx;
int a[MAXN];
int nq;

pair<int,int> o[MAXN];
int nxt[MAXN];

int sroot[MAXN+1];

int ns;
int sval[MAXS],sl[MAXS],sr[MAXS];

int screate(int val) {
	assert(ns<MAXS);
	sval[ns]=val,sl[ns]=sr[ns]=-1; return ns++;
}
int screate(int l,int r) {
	assert(ns<MAXS);
	sval[ns]=sval[l]+sval[r],sl[ns]=l,sr[ns]=r; return ns++;
}

int sinit(int l,int r) {
	if(l==r) return screate(0);
	int m=l+(r-l)/2;
	return screate(sinit(l,m),sinit(m+1,r));
}

int smod(int x,int l,int r,int IDX,int BY) {
	if(l==r) {
		return screate(sval[x]+BY);
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) return screate(smod(sl[x],l,m,IDX,BY),sr[x]);
		else return screate(sl[x],smod(sr[x],m+1,r,IDX,BY));
	}
}

int sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) return sval[x];
	int m=l+(r-l)/2;
	int ret=0;
	if(L<=m) ret+=sget(sl[x],l,m,L,R);
	if(m+1<=R) ret+=sget(sr[x],m+1,r,L,R);
	return ret;
}

void run() {
	scanf("%d%d",&n,&mx);
	REP(i,n) scanf("%d",&a[i]);
	//n=MAXN; mx=1; REP(i,n) a[i]=rand()%1000;


	REP(i,n) o[i]=MP(a[i],i); sort(o,o+n);
	REP(i,n) nxt[o[i].second]=i+mx<n&&o[i+mx].first==o[i].first?o[i+mx].second:-1;
	//REP(i,n) printf("%d ",nxt[i]); puts("");

	ns=0;
	sroot[n]=sinit(0,n-1);
	for(int i=n-1;i>=0;--i) {
		sroot[i]=smod(sroot[i+1],0,n-1,i,+1);
		if(nxt[i]!=-1) sroot[i]=smod(sroot[i],0,n-1,nxt[i],-1);
	}
	//printf("ns=%d (%.9lf)\n",ns,1.0*ns/MAXS);

	scanf("%d",&nq); int last=0;
	//nq=0;
	REP(i,nq) {
		int x,y; scanf("%d%d",&x,&y);
		int l=(x+last)%n,r=(y+last)%n; if(l>r) swap(l,r);

		int ans=sget(sroot[l],0,n-1,0,r);
		printf("%d\n",ans);
		last=ans;
	}
}

int main() {
	run();
	return 0;
}
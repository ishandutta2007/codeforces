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
typedef struct R { int p,s,id,z,zp; } R;
bool pcmp(const R &a,const R &b) { return a.p>b.p; }
bool scmp(const R &a,const R &b) { return a.s>b.s; }
bool spcmp(const R &a,const R &b) { return a.s-a.p>b.s-b.p; }
bool zcmp(const R &a,const R &b) { return a.zp-a.s>b.zp-b.s; }

int n,np,ns;
R r[MAXN];
R p[MAXN];
R s[MAXN];

void solvep() {
	sort(p,p+np,spcmp);
}

R a[MAXN],b[MAXN]; bool done[MAXN];
void solves() {
	REP(i,ns) a[i]=s[i]; sort(a,a+ns,scmp); reverse(a,a+ns);
	REP(i,ns) b[i]=s[i]; sort(b,b+ns,spcmp); reverse(b,b+ns);
	memset(done,false,sizeof(done)); int aa=0,bb=0,rr=0;
	priority_queue<pair<int,int> > pq;
	REP(i,ns) {
		while(aa<ns&&done[a[aa].id]) ++aa;
		while(bb<ns&&done[b[bb].id]) ++bb;
		int ss=SZ(pq)==0?i:pq.top().second;
		// b[bb].p-b[bb].s | r[rr].p-a[aa].s | s[ss].p-a[aa].s
		int v1=bb>=ns?INT_MIN:b[bb].p-b[bb].s; 
		int v2=rr>=n||aa>=ns?INT_MIN:r[rr].p-a[aa].s;
		int v3=ss>=i||aa>=ns?INT_MIN:s[ss].p-a[aa].s;
		//if(i<15) printf("%d: %d %d %d\n",i,v1,v2,v3);
		if(v1>=v2&&v1>=v3) {
			done[b[bb].id]=true; s[i]=b[bb]; s[i].z=i,s[i].zp=b[bb].p;
		} else if(v2>=v3) {
			done[a[aa].id]=true; s[i]=a[aa]; s[i].z=-1,s[i].zp=r[rr].p; ++rr; pq.push(MP(a[aa].p,i));
		} else {
			done[a[aa].id]=true; s[i]=a[aa]; s[i].z=ss,s[i].zp=s[ss].p; pq.pop(); pq.push(MP(a[aa].p,i));
		}
	}
}

int ans[MAXN];
void run() {
	scanf("%d%d%d",&n,&np,&ns); REP(i,n) r[i].id=i; REP(i,n) scanf("%d",&r[i].p); REP(i,n) scanf("%d",&r[i].s);
	sort(r,r+n,pcmp); REP(i,np) p[i]=r[i]; REP(i,n-np) r[i]=r[np+i]; n-=np;
	sort(r,r+n,scmp); REP(i,ns) s[i]=r[i]; REP(i,n-ns) r[i]=r[ns+i]; n-=ns;
	sort(r,r+n,pcmp);
	solvep();
	solves();
	//REP(i,np) printf("p%2d: %d %d (%d) <%d>\n",i,p[i].p,p[i].s,p[i].s-p[i].p,p[i].id+1);
	//REP(i,min(ns,15)) printf("s%2d: %d %d (%d) [%d=%d] <%d>\n",i,s[i].p,s[i].s,s[i].zp-s[i].s,s[i].z,s[i].zp,s[i].id+1);
	//REP(i,min(n,5)) printf("r%2d: %d %d <%d>\n",i,r[i].p,r[i].s,r[i].id+1);
	int ret=0,retx=0; REP(i,np) ret+=p[i].p; REP(i,ns) ret+=s[i].s;
	int cur=ret; //printf("%d = %d\n",0,cur);
	FORE(x,1,min(np,ns)) {
		int a=x-1,b=np+x-1;
		cur+=p[x-1].s-p[x-1].p+s[x-1].zp-s[x-1].s;
		if(cur>ret) ret=cur,retx=x;
		//printf("%d = %d\n",x,cur);
	}

	memset(ans,-1,sizeof(ans));
	REP(i,retx) ans[p[i].id]=1;
	REP(i,np-retx) ans[p[retx+i].id]=0;
	REP(i,retx) if(s[i].z!=-1) ans[s[s[i].z].id]=0;
	REP(i,ns-retx) ans[s[retx+i].id]=1;
	int nr=0; REP(i,retx) if(s[i].z==-1) ++nr; REP(i,nr) ans[r[i].id]=0;

	printf("%d\n",ret);
	{ bool first=true; REP(i,np+ns+n) if(ans[i]==0) { if(first) first=false; else printf(" "); printf("%d",i+1); } puts(""); }
	{ bool first=true; REP(i,np+ns+n) if(ans[i]==1) { if(first) first=false; else printf(" "); printf("%d",i+1); } puts(""); }

	//{ REP(j,np) { int x; scanf("%d",&x); --x; REP(i,np) if(p[i].id==x) printf("p%d ",i); REP(i,ns) if(s[i].id==x) printf("s%d ",i); REP(i,n) if(r[i].id==x) printf("r%d ",i); } puts(""); }
	//{ REP(j,ns) { int x; scanf("%d",&x); --x; REP(i,np) if(p[i].id==x) printf("p%d ",i); REP(i,ns) if(s[i].id==x) printf("s%d ",i); REP(i,n) if(r[i].id==x) printf("r%d ",i); } puts(""); }
}

int main() {
	run();
	return 0;
}
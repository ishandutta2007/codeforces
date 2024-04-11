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

const int MAXQ=100000;
const int MAXU=100000;
const int MAXLG=16;
const int MAXTNODE=1+(MAXLG+1)*MAXQ;
struct TNode { int c[2],mn; };

int nq;
int qkind[MAXQ],qu[MAXQ],qx[MAXQ],qk[MAXQ],qs[MAXQ];
int ans[MAXQ];

int pmn[MAXU+1];
vector<int> dv[MAXU+1];

bool seen[MAXU+1];
vector<int> qidx[MAXU+1];

TNode t[MAXTNODE]; int nt,troot;
int maket() { assert(nt<MAXTNODE); int ret=nt++; t[ret].c[0]=t[ret].c[1]=-1,t[ret].mn=INT_MAX; return ret; }

void run() {
	scanf("%d",&nq); REP(i,nq) { scanf("%d",&qkind[i]); if(qkind[i]==1) scanf("%d",&qu[i]); else scanf("%d%d%d",&qx[i],&qk[i],&qs[i]); }

	memset(pmn,-1,sizeof(pmn)); FORE(i,2,MAXU) if(pmn[i]==-1) for(int j=i;j<=MAXU;j+=i) if(pmn[j]==-1) pmn[j]=i;

	dv[1].PB(1); FORE(i,2,MAXU) { int p=pmn[i]; int x=i,cnt=0; while(x%p==0) x/=p,++cnt; REPSZ(j,dv[x]) { int cur=dv[x][j]; REPE(k,cnt) { dv[i].PB(cur); cur*=p; } } }
	//FORE(i,1,100) { printf("%d:",i); REPSZ(j,dv[i]) printf(" %d",dv[i][j]); puts(""); }
	//int mx=1; FORE(i,1,MAXU) if(SZ(dv[i])>SZ(dv[mx])) mx=i; printf("SZ(dv[%d])=%d\n",mx,SZ(dv[mx]));

	memset(seen,false,sizeof(seen));
	REP(i,nq) {
		if(qkind[i]==1) { int u=qu[i]; if(seen[u]) continue; seen[u]=true; REPSZ(j,dv[u]) qidx[dv[u][j]].PB(i); }
		if(qkind[i]==2) qidx[qk[i]].PB(i);
	}

	FORE(k,1,MAXU) if(SZ(qidx[k])!=0) {
		//printf("k=%d ->",k); REPSZ(i,qidx[k]) { int idx=qidx[k][i]; if(qkind[idx]==1) printf(" %d",qu[idx]); else printf(" q%d",idx); } puts("");
		nt=0; troot=maket();
		REPSZ(i,qidx[k]) {
			int idx=qidx[k][i];
			if(qkind[idx]==1) {
				int u=qu[idx];
				int at=troot; t[at].mn=min(t[at].mn,u);
				for(int j=MAXLG;j>=0;--j) {
					int z=(u>>j)&1;
					if(t[at].c[z]==-1) t[at].c[z]=maket();
					at=t[at].c[z]; t[at].mn=min(t[at].mn,u);
				}
			}
			if(qkind[idx]==2) {
				int lim=qs[idx]-qx[idx],x=qx[idx];
				if(t[troot].mn>lim||x%k!=0) { ans[idx]=-1; continue; }
				int at=troot; ans[idx]=0;
				for(int j=MAXLG;j>=0;--j) {
					//printf("at=%d mn=%d lim=%d",at,t[at].mn,lim); REP(l,2) if(t[at].c[l]==-1) printf(" X"); else printf(" %d=%d",t[at].c[l],t[t[at].c[l]].mn); puts("");
					bool found=false;
					REP(zz,2) {
						int z=(x>>j)&1; if(zz==0) z=1-z;
						if(t[at].c[z]==-1||t[t[at].c[z]].mn>lim) continue;
						found=true; at=t[at].c[z]; if(z==1) ans[idx]+=1<<j; break;
					}
					assert(found);
				}
			}
		}
	}
	
	REP(i,nq) if(qkind[i]==2) printf("%d\n",ans[i]);
}

int main() {
	run();
	return 0;
}
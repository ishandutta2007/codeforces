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

const int MAXN=4000;
const int MAXX=6139038;

int n;
int val[MAXN];
ll sval[MAXN+1];

int nx;
int xl[MAXX],xr[MAXX],xk[MAXX],xt[MAXX];
int xa[MAXX],xb[MAXX];
ll res[MAXX];
int para[MAXX],parb[MAXX];


int id[MAXN][MAXN+1][2]; short mark[MAXN][MAXN+1][2],curmark;

int addstate(int l,int r,int k,int t) { assert(nx<MAXX); xl[nx]=l,xr[nx]=r,xk[nx]=k,xt[nx]=t,xa[nx]=-1,xb[nx]=-1; return nx++; }
void genstates() {
	memset(mark,-1,sizeof(mark)); curmark=0;
	nx=0; int sx=0; mark[0][n][0]=curmark,id[0][n][0]=addstate(0,n,1,0);
	while(sx<nx) {
		FOR(at,sx,nx) {
			assert(xa[at]==-1);
			int l=xl[at],r=xr[at],k=xk[at],t=xt[at];
			int nl=l+(t==0?k:0),nr=r-(t==1?k:0),nk=k,nt=1-t;
			if(nl<=nr) {
				if(mark[nl][nr][nt]!=curmark) mark[nl][nr][nt]=curmark,id[nl][nr][nt]=addstate(nl,nr,nk,nt);
				xa[at]=id[nl][nr][nt]; assert(xa[at]!=-1);
			}
		}
		int tx=nx; ++curmark;
		FOR(at,sx,tx) {
			assert(xb[at]==-1);
			int l=xl[at],r=xr[at],k=xk[at],t=xt[at];
			int nl=l+(t==0?k+1:0),nr=r-(t==1?k+1:0),nk=k+1,nt=1-t;
			if(nl<=nr) {
				if(mark[nl][nr][nt]!=curmark) mark[nl][nr][nt]=curmark,id[nl][nr][nt]=addstate(nl,nr,nk,nt);
				assert(xa[at]!=-1);
				xb[at]=id[nl][nr][nt]; assert(xb[at]!=-1);
			}
		}
		sx=tx;
	}
	//printf("%d\n",nx);
	//REP(i,nx) printf("%d %d %d %d\n",xl[i],xr[i],xk[i],xt[i]);
}

/*int bf(int l,int r,int k,int t) {
	if(r-l<k) return 0;
	if(t==0) {
		int ret=sval[l+k]-sval[l]-bf(l+k,r,k,1),fst=ret,fst1=sval[l+k]-sval[k];
		if(r-l>=k+1) { int other=sval[l+k+1]-sval[l]-bf(l+k+1,r,k+1,1); if(other>ret) ret=other; }
		REP(i,nx) if(xl[i]==l&&xr[i]==r&&xk[i]==k&&xt[i]==t&&res[i]!=ret) { printf("err: %d %d %d %d (%d(%d|%d|%d) vs %lld) [%lld:%lld]\n",l,r,k,t,ret,fst,fst1,val[l],res[i],sval[l+k],sval[l]); exit(0); }
		return ret;
	} else {
		int ret=sval[r]-sval[r-k]-bf(l,r-k,k,0);
		if(r-l>=k+1) { int other=sval[r]-sval[r-k-1]-bf(l,r-k-1,k+1,0); if(other>ret) ret=other; }
		REP(i,nx) if(xl[i]==l&&xr[i]==r&&xk[i]==k&&xt[i]==t&&res[i]!=ret) { printf("err: %d %d %d %d (%d vs %lld)\n",l,r,k,t,ret,res[i]); }
		return ret;
	}
}*/

int q[MAXX],qhead,qtail;
int lft[MAXX];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&val[i]); sval[0]=0; REP(i,n) sval[i+1]=sval[i]+val[i];
	genstates();
	memset(para,-1,sizeof(para)); memset(parb,-1,sizeof(parb));
	REP(i,nx) if(xa[i]!=-1) { assert(para[xa[i]]==-1); para[xa[i]]=i; }
	REP(i,nx) if(xb[i]!=-1) { assert(parb[xb[i]]==-1); parb[xb[i]]=i; }

	qhead=qtail=0; memset(lft,0,sizeof(lft)); REP(i,nx) if(xa[i]!=-1) ++lft[i]; REP(i,nx) if(xb[i]!=-1) ++lft[i]; REP(i,nx) if(lft[i]==0) q[qhead++]=i;
	while(qtail<qhead) {
		int i=q[qtail++];
		int l=xl[i],r=xr[i],k=xk[i],t=xt[i];
		if(xa[i]==-1) {
			res[i]=0;
		} else {
			REP(dk,2) {
				int j=dk==0?xa[i]:xb[i]; if(j==-1) continue;
				ll cura=t==0?(sval[l+k+dk]-sval[l]):(sval[r]-sval[r-k-dk]);
				//ll chk=0; REP(j,k+dk) chk+=t==0?val[l+j]:val[r-j-1]; assert(chk==cura);
				ll curb=res[j];
				ll cur=cura-curb;
				//printf("\t%lld-%lld=%lld [%d]\n",cura,curb,cur,j);
				if(dk==0||cur>res[i]) res[i]=cur;
			}
			//printf("%d: %d %d %d %d = %lld (%d)\n",i,xl[i],xr[i],xk[i],xt[i],res[i],xb[i]==-1?1:2);
		}
		if(para[i]!=-1&&--lft[para[i]]==0) q[qhead++]=para[i];
		if(parb[i]!=-1&&--lft[parb[i]]==0) q[qhead++]=parb[i];
	}
	assert(qhead==nx);
	//printf("bf=%d\n",bf(0,n,1,0));
	printf("%lld\n",res[0]);
}

int main() {
	run();
	return 0;
}
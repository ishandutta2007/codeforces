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

const int MAXSN=1000;
const int MAXSM=MAXSN-1;
const int MAXTN=12;
const int MAXTM=MAXTN-1;
const int MOD=1000000007;


int sn;
int shead[MAXSN],snxt[2*MAXSM],sto[2*MAXSM];
int tn;
int thead[MAXTN],tnxt[2*MAXTM],tto[2*MAXTM];

int tsz[2*MAXTM];
int calctsz(int x) {
	if(tsz[x]!=0) return tsz[x]; else tsz[x]=1;
	int at=tto[x];
	for(int y=thead[at];y!=-1;y=tnxt[y]) if((y^1)!=x) tsz[x]+=calctsz(y);
	return tsz[x];
}

int memst[MAXSN+2*MAXSM][MAXTN+2*MAXTM];
int memtt[MAXTN+2*MAXTM][MAXTN+2*MAXTM];
int z[MAXTN],nz;
int dp[1<<MAXTN];
int calcst(int av,int pax,int bv,int pbx) {
	int aid=pax==-1?av:sn+pax,bid=pbx==-1?bv:tn+pbx;
	int &ret=memst[aid][bid];
	if(ret==-1) {
		ret=0;
		for(int ax=shead[av];ax!=-1;ax=snxt[ax]) if(pax==-1||(ax^1)!=pax) {
			int aw=sto[ax];
			for(int bx=thead[bv];bx!=-1;bx=tnxt[bx]) if(pbx==-1||(bx^1)!=pbx) {
				int bw=tto[bx];
				calcst(aw,ax,bw,bx);
			}
		}
		int bx1=-1,nbx1=0,bx2=-1,nbx2=0; nz=0;
		for(int bx=thead[bv];bx!=-1;bx=tnxt[bx]) if(pbx==-1||(bx^1)!=pbx) {
			if(tsz[bx]==1) bx1=bx,nbx1++; else if(tsz[bx]==2) bx2=bx,nbx2++; else z[nz++]=bx;
		}
		int n=(nbx1+1)*(nbx2+1)*(1<<nz);
		REP(i,n) dp[i]=0; dp[0]=1;
		for(int ax=shead[av];ax!=-1;ax=snxt[ax]) if(pax==-1||(ax^1)!=pax) {
			int aw=sto[ax];
			for(int k1=nbx1;k1>=0;--k1) for(int k2=nbx2;k2>=0;--k2) for(int kz=(1<<nz)-1;kz>=0;--kz) {
				int k=k1+(nbx1+1)*(k2+(nbx2+1)*kz); if(dp[k]==0) continue;
				REP(j,nz+2) {
					int nk1=k1,nk2=k2,nkz=kz,times=1;
					int bx=j<nz?z[j]:j==nz?bx1:bx2; if(bx==-1) continue; int bw=tto[bx];
					int cur=calcst(aw,ax,bw,bx);
					if(j<nz) if(kz&(1<<j)) continue; else nkz|=1<<j; 
					if(j==nz) if(k1==nbx1) continue; else ++nk1,times*=nbx1-k1;
					if(j==nz+1) if(k2==nbx2) continue; else ++nk2,times*=nbx2-k2;
					int nk=nk1+(nbx1+1)*(nk2+(nbx2+1)*nkz);
					dp[nk]=(dp[nk]+(ll)dp[k]*cur*times)%MOD;
				}
			}
		}
		ret=dp[n-1];
		//printf("calcst(%d,%d,%d,%d)=%d\n",av+1,pax==-1?0:sto[pax^1]+1,bv+1,pbx==-1?0:tto[pbx^1]+1,ret);
	}
	return ret;
}
int calctt(int av,int pax,int bv,int pbx) {
	int aid=pax==-1?av:tn+pax,bid=pbx==-1?bv:tn+pbx;
	int &ret=memtt[aid][bid];
	if(ret==-1) {
		ret=0;
		for(int ax=thead[av];ax!=-1;ax=tnxt[ax]) if(pax==-1||(ax^1)!=pax) {
			int aw=tto[ax];
			for(int bx=thead[bv];bx!=-1;bx=tnxt[bx]) if(pbx==-1||(bx^1)!=pbx) {
				int bw=tto[bx];
				calctt(aw,ax,bw,bx);
			}
		}
		int bx1=-1,nbx1=0,bx2=-1,nbx2=0; nz=0;
		for(int bx=thead[bv];bx!=-1;bx=tnxt[bx]) if(pbx==-1||(bx^1)!=pbx) {
			if(tsz[bx]==1) bx1=bx,nbx1++; else if(tsz[bx]==2) bx2=bx,nbx2++; else z[nz++]=bx;
		}
		int n=(nbx1+1)*(nbx2+1)*(1<<nz);
		REP(i,n) dp[i]=0; dp[0]=1;
		for(int ax=thead[av];ax!=-1;ax=tnxt[ax]) if(pax==-1||(ax^1)!=pax) {
			int aw=tto[ax];
			for(int k1=nbx1;k1>=0;--k1) for(int k2=nbx2;k2>=0;--k2) for(int kz=(1<<nz)-1;kz>=0;--kz) {
				int k=k1+(nbx1+1)*(k2+(nbx2+1)*kz); if(dp[k]==0) continue;
				REP(j,nz+2) {
					int nk1=k1,nk2=k2,nkz=kz,times=1;
					int bx=j<nz?z[j]:j==nz?bx1:bx2; if(bx==-1) continue; int bw=tto[bx];
					int cur=calctt(aw,ax,bw,bx);
					if(j<nz) if(kz&(1<<j)) continue; else nkz|=1<<j; 
					if(j==nz) if(k1==nbx1) continue; else ++nk1,times*=nbx1-k1;
					if(j==nz+1) if(k2==nbx2) continue; else ++nk2,times*=nbx2-k2;
					int nk=nk1+(nbx1+1)*(nk2+(nbx2+1)*nkz);
					dp[nk]=(dp[nk]+(ll)dp[k]*cur*times)%MOD;
				}
			}
		}
		ret=dp[n-1];
		//printf("calctt(%d,%d,%d,%d)=%d\n",av+1,pax==-1?0:tto[pax^1]+1,bv+1,pbx==-1?0:tto[pbx^1]+1,ret);
	}
	return ret;
}


int mypow(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
void run() {
	scanf("%d",&sn); REP(i,sn) shead[i]=-1; REP(i,sn-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; snxt[2*i+0]=shead[a],shead[a]=2*i+0,sto[2*i+0]=b,snxt[2*i+1]=shead[b],shead[b]=2*i+1,sto[2*i+1]=a; }
	scanf("%d",&tn); REP(i,tn) thead[i]=-1; REP(i,tn-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; tnxt[2*i+0]=thead[a],thead[a]=2*i+0,tto[2*i+0]=b,tnxt[2*i+1]=thead[b],thead[b]=2*i+1,tto[2*i+1]=a; }

	memset(tsz,0,sizeof(tsz)); REP(i,2*(tn-1)) calctsz(i);
	//REP(i,2*(tn-1)) printf("%d->%d = %d\n",tto[i^1]+1,tto[i]+1,tsz[i]);
	int cnt=0; memset(memst,-1,sizeof(memst));
	REP(i,sn) {
		int cur=calcst(i,-1,0,-1);
		if((cnt+=cur)>=MOD) cnt-=MOD;
	}
	int times=0; memset(memtt,-1,sizeof(memtt));
	REP(i,tn) {
		int cur=calctt(i,-1,0,-1);
		if((times+=cur)>=MOD) times-=MOD;
	}
	int ret=(ll)cnt*mypow(times,MOD-2)%MOD;
	//printf("cnt=%d times=%d\n",cnt,times);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
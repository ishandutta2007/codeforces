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

const int MAXGYM=100000;
const int MAXTYPE=1000000;
const int MAXCNT=500000;
const int MOD=1000000007;

int ngym,ntype;
int off[MAXGYM+1];
int type[MAXCNT];

int id[MAXTYPE],nid,idcnt[MAXTYPE];
int amark[MAXTYPE],ahead[MAXTYPE],anxt[MAXCNT],acnt[MAXTYPE];
int b[MAXTYPE],nb;
int cmark[MAXCNT+1],chead[MAXCNT+1],cnxt[MAXTYPE];
int d[MAXCNT],nd;
int emark[MAXTYPE],ecnt[MAXTYPE];
int fmark[MAXTYPE],f[MAXTYPE];
int fac[MAXTYPE+1];


void run() {
	scanf("%d%d",&ngym,&ntype);
	off[0]=0; REP(i,ngym) { off[i+1]=off[i]; int ncur; scanf("%d",&ncur); REP(j,ncur) { int x; scanf("%d",&x); --x; type[off[i+1]++]=x; } }

	memset(amark,-1,sizeof(amark)); memset(cmark,-1,sizeof(cmark)); memset(id,0,sizeof(id)); memset(emark,-1,sizeof(emark)); memset(fmark,-1,sizeof(fmark)); nid=1; idcnt[0]=ntype;
	REP(i,ngym) {
		//printf("processing gym %d\n",i+1);
		nb=0;
		FOR(j,off[i],off[i+1]) {
			if(amark[type[j]]!=i) amark[type[j]]=i,ahead[type[j]]=-1,acnt[type[j]]=0,b[nb++]=type[j];
			anxt[j]=ahead[type[j]],ahead[type[j]]=j,acnt[type[j]]++;
		}
		//REP(j,nb) printf("\t%d appears %d times\n",b[j]+1,acnt[b[j]]);
		nd=0;
		REP(j,nb) {
			if(cmark[acnt[b[j]]]!=i) cmark[acnt[b[j]]]=i,chead[acnt[b[j]]]=-1,d[nd++]=acnt[b[j]];
			cnxt[b[j]]=chead[acnt[b[j]]],chead[acnt[b[j]]]=b[j];
		}
		REP(j,nd) {
			//printf("\tnodes that appear %d times:",d[j]); for(int x=chead[d[j]];x!=-1;x=cnxt[x]) printf(" %d",x+1); puts("");
			for(int x=chead[d[j]];x!=-1;x=cnxt[x]) {
				if(emark[id[x]]!=off[i]+j) emark[id[x]]=off[i]+j,ecnt[id[x]]=0;
				++ecnt[id[x]];
			}
			for(int x=chead[d[j]];x!=-1;x=cnxt[x]) {
				//printf("\t\t%d has id %d, appears %d times (which %d out of %d do)\n",x+1,id[x],d[j],ecnt[id[x]],idcnt[id[x]]);
				if(ecnt[id[x]]==idcnt[id[x]]) continue;
				if(fmark[id[x]]!=off[i]+j) fmark[id[x]]=off[i]+j,idcnt[nid]=0,f[id[x]]=nid++;
				//printf("\t\t->%d\n",f[id[x]]);
				--ecnt[id[x]]; --idcnt[id[x]]; id[x]=f[id[x]]; ++idcnt[id[x]];
			}
		}
	}
	fac[0]=1; FORE(i,1,MAXTYPE) fac[i]=(ll)fac[i-1]*i%MOD;
	int ret=1; REP(i,nid) ret=(ll)ret*fac[idcnt[i]]%MOD; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
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

const int MAXN=2000;

int n,s,t;
int x[MAXN];

int dplst[MAXN]; // dplst[i]=minimum # moves to write all numbers <= x[i], ending at i
int fst[MAXN]; // fst[i]=first position with value x[i] which was written (leading to dp[i])
int dir[MAXN]; // dir[i]=direction from fst[i] to i

int dpfst[MAXN]; // dpfst[i]=minimum # movesto write all numbers less than x[i] followed by x[i]
int prv[MAXN]; // prv[i]=last position written with value less than x[i] which was written

int vals[MAXN],nvals;
int pos[MAXN],npos;

int dst(int a,int b) { int d=abs(a-b); return min(d,n-d); }
int sdst(int a,int b) { int d=abs(a-b); return d<=n-d?a<=b?+d:-d:a<=b?d-n:n-d; }

int ret[MAXN],nret;

void run() {
	scanf("%d%d",&n,&s); --s; REP(i,n) scanf("%d",&x[i]);
	//REP(i,n) printf("%d ",x[i]); puts("");

	REP(i,n) vals[i]=x[i]; sort(vals,vals+n); nvals=unique(vals,vals+n)-vals;

	memset(prv,-1,sizeof(prv)); memset(dpfst,0,sizeof(dpfst));
	memset(fst,-1,sizeof(fst)); memset(dplst,0,sizeof(dplst)); memset(dir,0,sizeof(dir));
	REP(i,nvals) {
		int v=vals[i];
		npos=0; REP(j,n) if(x[j]==v) pos[npos++]=j;
		REP(j,npos) {
			int p=pos[j]; dpfst[p]=INT_MAX;
			if(i==0) { dpfst[p]=dst(p,s); continue; }
			REP(k,n) if(x[k]==vals[i-1]&&dplst[k]+dst(k,p)<dpfst[p]) dpfst[p]=dplst[k]+dst(k,p),prv[p]=k;
		}
		REP(j,npos) {
			int p=pos[j]; dplst[p]=INT_MAX;
			if(npos==1) { fst[p]=p,dplst[p]=dpfst[p]; continue; }
			REP(k,npos) if(k!=j) {
				int pk=k==0?npos-1:k-1,nk=k==npos-1?0:k+1;
				int up=dpfst[pos[k]]-pos[k]+pos[pk]+(k==0?0:n)+dst(pos[pk],pos[j]);
				if(up<dplst[p]) dplst[p]=up,fst[p]=pos[k],dir[p]=+1;
				int dn=dpfst[pos[k]]+pos[k]-pos[nk]+(nk==0?0:n)+dst(pos[nk],pos[j]);
				if(dn<dplst[p]) dplst[p]=dn,fst[p]=pos[k],dir[p]=-1;
			}
		}
		//REP(j,npos) printf("%d: %d (%d) %d (%d,%d)\n",pos[j],dpfst[pos[j]],prv[pos[j]],dplst[pos[j]],fst[pos[j]],dir[pos[j]]);
	}
	t=-1; REP(i,n) if(x[i]==vals[nvals-1]&&(t==-1||dplst[i]<dplst[t])) t=i;
	printf("%d\n",dplst[t]);

	nret=0;
	for(int at=t;at!=-1;at=prv[fst[at]]) {
		npos=0; REP(j,n) if(x[j]==x[at]) pos[npos++]=j;
		int cur=at,idx=-1; REP(j,npos) if(pos[j]==fst[at]) idx=j;
		while(true) {
			idx-=dir[at]; if(idx<0) idx+=npos; if(idx>=npos) idx-=npos;
			if(pos[idx]!=cur) ret[nret++]=sdst(pos[idx],cur),cur=pos[idx];
			if(cur==fst[at]) break;
		}
		ret[nret++]=sdst(prv[fst[at]]==-1?s:prv[fst[at]],fst[at]);
	}
	reverse(ret,ret+nret); REP(i,nret) printf("%c%d\n",ret[i]>=0?'+':'-',abs(ret[i]));
}

int main() {
	run();
	return 0;
}
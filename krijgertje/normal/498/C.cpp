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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

typedef struct MF {
	int n,m,s,t;
	int fst[102];
	int nxt[400];
	int to[400];
	int cap[400];

	int flow[102],prv[102];
	int q[102],qhead,qtail;

	void addedge(int a,int b,int c) {
		nxt[m]=fst[a]; fst[a]=m; to[m]=b; cap[m]=c; m++;
		nxt[m]=fst[b]; fst[b]=m; to[m]=a; cap[m]=0; m++;
	}

	int calc() {
		int ret=0;
		while(true) {
//			printf("\tflow=%d\n",ret);
			memset(flow,0,sizeof(flow)); memset(prv,-1,sizeof(prv)); qhead=qtail=0;
			flow[s]=INT_MAX; prv[s]=-2; q[qhead++]=s;
			while(qtail<qhead) {
				int at=q[qtail++];
//				printf("\t\tat=%d\n",at);
				for(int x=fst[at];x!=-1;x=nxt[x]) if(cap[x]>0&&flow[to[x]]==0) {
					flow[to[x]]=min(flow[at],cap[x]); prv[to[x]]=x^1; q[qhead++]=to[x];					
				}
			}
//			printf("\taddflow=%d\n",flow[t]);
			if(flow[t]==0) return ret;
			ret+=flow[t];
			for(int at=t;at!=s;at=to[prv[at]]) {
//				printf("\t\trev=%d\n",at);
				cap[prv[at]]+=flow[t];
				cap[prv[at]^1]-=flow[t];
			}
		}
	}
} MF;
MF mf;


int nvals,npairs;
int val[100],evn[100],odd[100];

int q[3000],nq;






void run() {
	scanf("%d%d",&nvals,&npairs);
	REP(i,nvals) scanf("%d",&val[i]);
	REP(i,npairs) { scanf("%d%d",&odd[i],&evn[i]); --odd[i],--evn[i]; if(odd[i]%2==0) swap(odd[i],evn[i]); assert(odd[i]%2==1&&evn[i]%2==0); }

	nq=0;
	REP(i,nvals) { int x=val[i]; for(int j=2;j*j<=x;++j) if(x%j==0) { q[nq++]=j; while(x%j==0) x/=j; } if(x!=1) q[nq++]=x; }
	{ sort(q,q+nq);  int nnq=0; REP(qi,nq) if(nnq==0||q[qi]!=q[nnq-1]) q[nnq++]=q[qi]; nq=nnq; }


	int ret=0;
	REP(qi,nq) {
//		printf("q %d: %d\n",qi,q[qi]);
		mf.n=nvals+2; mf.m=0; mf.s=nvals; mf.t=nvals+1; memset(mf.fst,-1,sizeof(mf.fst));
		REP(i,nvals) {
			int cnt=0,x=val[i]; while(x%q[qi]==0) ++cnt,x/=q[qi];
			if(i%2==0) mf.addedge(mf.s,i,cnt); else mf.addedge(i,mf.t,cnt);
		}
		REP(i,npairs) mf.addedge(evn[i],odd[i],100);
		int cur=mf.calc();
		ret+=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
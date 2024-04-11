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

const int MAXN=50000;
const int MAXM=100000;
const int MAXOPT=20;
const int MAXT=1000000;
const int MAXSUMOPT=MAXN*MAXOPT;

int n,m,nt;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];
int cnt[MAXN],opt[MAXN][MAXOPT];
int thead[MAXT],tnxt[MAXSUMOPT];

int icol[MAXN];


int lft;
bool done[MAXN];
int tcol[MAXT];
int trem[MAXT][2];
int irem[MAXN];
int res[MAXN];

int q[MAXT],qhead,qtail;
void mark(int i,int t) {
	done[i]=true; --lft; res[i]=t;
	REP(j,cnt[i]) if(--trem[opt[i][j]][icol[i]]==0&&tcol[opt[i][j]]==-1) q[qhead++]=2*opt[i][j]+1-icol[i],tcol[opt[i][j]]=1-icol[i];
}
bool assign(int st,int scol) {
	//printf("assign(%d,%d) {%d,%d,%d}\n",st,scol,tcol[st],trem[st][0],trem[st][1]); printf("irem:"); REP(i,n) printf(" %d",irem[i]); puts("");
	qhead=qtail=0; q[qhead++]=2*st+scol,tcol[st]=scol;
	while(qtail<qhead) {
		int t=q[qtail]/2,col=q[qtail]%2; ++qtail; //printf("\t(%d,%d)\n",t,col);
		for(int x=thead[t];x!=-1;x=tnxt[x]) {
			int i=x/MAXOPT; if(done[i]) continue;
			//printf("\t\t[%d,%d]\n",i,icol[i]);
			if(icol[i]==tcol[t]) { mark(i,t); continue; }
			--irem[i];
			if(irem[i]==0) return false;
			if(irem[i]==1) { int to=-1; REP(j,cnt[i]) if(tcol[opt[i][j]]==-1) { assert(to==-1); to=opt[i][j]; } if(to!=-1) q[qhead++]=2*to+icol[i],tcol[to]=icol[i]; }
		}
	}
	return true;
}

// randomly choose color for next team -> satisfies some trainers
// queue trainers with only one remaining option -> color it
bool solve() {
	lft=n; int at=0; memset(tcol,-1,sizeof(tcol)); memset(done,false,sizeof(done)); memset(trem,0,sizeof(trem)); memset(irem,0,sizeof(irem));
	REP(i,n) REP(j,cnt[i]) ++trem[opt[i][j]][icol[i]],++irem[i];
	while(lft>0) {
		while(at<nt&&(tcol[at]!=-1||trem[at][0]==0&&trem[at][1]==0)) ++at;
		assert(at<nt);
		if(!assign(at,trem[at][0]==0?1:trem[at][1]==0?0:rand()%2)) return false;
	}
	for(;at<nt;++at) if(tcol[at]==-1) tcol[at]=0;
	return true;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) ghead[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a;
	}
	REP(i,n) { scanf("%d",&cnt[i]); REP(j,cnt[i]) { scanf("%d",&opt[i][j]); --opt[i][j]; } }
	nt=0; REP(i,n) REP(j,cnt[i]) if(opt[i][j]>=nt) nt=opt[i][j]+1;
	REP(i,nt) thead[i]=-1; REP(i,n) REP(j,cnt[i]) { int k=i*MAXOPT+j; tnxt[k]=thead[opt[i][j]]; thead[opt[i][j]]=k; }
	//REP(i,nt) if(thead[i]!=-1) { printf("%d: ",i); for(int x=thead[i];x!=-1;x=tnxt[x]) printf(" %d",x/MAXOPT); puts(""); }

	memset(icol,-1,sizeof(icol));
	REP(i,n) {
		int n0=0,n1=0;
		for(int x=ghead[i];x!=-1;x=gnxt[x]) { int to=gto[x]; if(icol[to]==0) ++n0; else if(icol[to]==1) ++n1; }
		icol[i]=n0>n1?1:0;
	}

	while(true) if(solve()) break;
	REP(i,n) { if(i!=0) printf(" "); printf("%d",res[i]+1); } puts("");
	REP(i,nt) { if(i!=0) printf(" "); printf("%d",tcol[i]+1); } puts("");


	
}

int main() {
	run();
	return 0;
}
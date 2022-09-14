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

const int MAXN=20;

int n;
int a[MAXN][MAXN],b[MAXN][MAXN];

int res;
int c[MAXN][MAXN];
int lx[MAXN],ly[MAXN];
int xy[MAXN],yx[MAXN],yxx[MAXN],ycc[MAXN];
int q[MAXN],qhead,qtail;
bool S[MAXN],T[MAXN];

bool process(int y) {
	if(yx[y]!=-1) { q[qhead++]=yx[y]; S[yx[y]]=T[y]=true; return false; }
	for(int cx=yxx[y],cy=y,ny=xy[cx];cx!=-1;cy=ny,cx=cy==-1?-1:yxx[cy],ny=cx==-1?-1:xy[cx]) { yx[cy]=cx; xy[cx]=cy; res+=c[cx][cy]-(ny==-1?0:c[cx][ny]); }
	return true;
}
void augment(int sx) {
	lx[sx]=0; REP(y,n) if(c[sx][y]>lx[sx]) lx[sx]=c[sx][y];
	qhead=qtail=0; memset(S,false,sizeof(S)); memset(T,false,sizeof(T)); memset(yxx,-1,sizeof(yxx));
	q[qhead++]=sx; S[sx]=true;
	while(true) {
		while(qtail<qhead) {
			int x=q[qtail++];
			REP(y,n) if(!T[y]) {
				int cc=lx[x]+ly[y]-c[x][y];
				if(yxx[y]==-1||cc<ycc[y]) yxx[y]=x,ycc[y]=cc;
				if(cc!=0) continue;
				if(process(y)) return;
			}
		}
		int delta=INT_MAX; REP(y,n) if(!T[y]&&ycc[y]<delta) delta=ycc[y];
		//printf("\t\t\tdelta=%d ",delta); REP(x,n) printf("%c",S[x]?'V':'.'); printf(" "); REP(y,n) printf("%c",T[y]?'V':'.'); REP(qi,qhead) printf(" %d",q[qi]); puts("");
		REP(qi,qhead) lx[q[qi]]-=delta;
//		REP(y,n) if(T[y]) ly[y]+=delta; else if((ycc[y]-=delta)==0&&process(y)) return;
		REP(y,n) if(T[y]) ly[y]+=delta; else ycc[y]-=delta;
		REP(y,n) if(!T[y]&&ycc[y]==0&&process(y)) return;
	}
}
void undo(int sx) {
	int sy=xy[sx];
	res-=c[sx][sy];
	xy[sx]=yx[sy]=-1;
}

int calc(int at,int na,int nb) {
	if(at>=n) return res;
	int ret=INT_MIN;
	if(2*na<n) {
		REP(j,n) c[at][j]=a[at][j];
		augment(at);
		//REP(i,na+nb) printf("  "); printf("a=%d",res); REPE(i,at) printf(" %d",xy[i]); puts("");
		//REP(i,na+nb) printf("  "); printf("lx:"); REPE(x,at) printf(" %d",lx[x]); puts("");
		//REP(i,na+nb) printf("  "); printf("ly:"); REP(y,n) printf(" %d",ly[y]); puts("");
		//REPE(x,at) { REP(i,na+nb) printf("  "); REP(y,n) printf(" %5d",lx[x]+ly[y]-c[x][y]); puts(""); }
		int cur=calc(at+1,na+1,nb);
		if(cur>ret) ret=cur;
		undo(at);
	}
	if(2*nb<n) {
		REP(j,n) c[at][j]=b[at][j];
		augment(at);
		//REP(i,na+nb) printf("  "); printf("b=%d",res); REPE(i,at) printf(" %d",xy[i]); puts("");
		//REP(i,na+nb) printf("  "); printf("lx:"); REPE(x,at) printf(" %d",lx[x]); puts("");
		//REP(i,na+nb) printf("  "); printf("ly:"); REP(y,n) printf(" %d",ly[y]); puts("");
		//REPE(x,at) { REP(i,na+nb) printf("  "); REP(y,n) printf(" %5d",lx[x]+ly[y]-c[x][y]); puts(""); }
		int cur=calc(at+1,na,nb+1);
		if(cur>ret) ret=cur;
		undo(at);
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) REP(j,n) scanf("%d",&a[i][j]);
	REP(i,n) REP(j,n) scanf("%d",&b[i][j]);

	res=0;
	REP(i,n) xy[i]=yx[i]=-1;
	int ret=calc(0,0,0);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
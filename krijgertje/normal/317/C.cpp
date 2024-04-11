#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

int n,m;
int maxvol;

int d[300][300];
int nxt[300][300];

int have[300],want[300];

int nans;
int ans[180000][3];

int ndelay;
int delay[300][3];

void input() {
	scanf("%d%d%d",&n,&maxvol,&m);
	REP(i,n) REP(j,n) { d[i][j]=i==j?0:INT_MAX; nxt[i][j]=-1; }
	REP(i,n) scanf("%d",&have[i]);
	REP(i,n) scanf("%d",&want[i]);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; d[a][b]=d[b][a]=1; nxt[a][b]=b; nxt[b][a]=a; }
}

bool solve() {
	REP(k,n) REP(i,n) REP(j,n) if(d[i][k]!=INT_MAX&&d[k][j]!=INT_MAX&&d[i][k]+d[k][j]<d[i][j]) { d[i][j]=d[i][k]+d[k][j]; nxt[i][j]=nxt[i][k]; }

	nans=0;
	while(true) {
		int from=-1; REP(i,n) if(have[i]>want[i]) { from=i; break; } if(from==-1) break;
		int to=-1; REP(i,n) if(have[i]<want[i]&&d[from][i]!=INT_MAX&&(to==-1||d[from][i]<d[from][to])) to=i; if(to==-1) break;
		int amount=min(have[from]-want[from],want[to]-have[to]);
		ndelay=0;
		for(int prev=from,at=nxt[from][to];at!=-1;prev=at,at=nxt[at][to]) {
			int now=min(amount,maxvol-have[at]);
			if(now>0) {
				have[prev]-=now; have[at]+=now;
				assert(nans<180000); ans[nans][0]=prev; ans[nans][1]=at; ans[nans][2]=now; ++nans;
			}
			if(amount>now) {
				have[prev]-=(amount-now); have[at]+=(amount-now); // TODO: store at end
				assert(ndelay<300); delay[ndelay][0]=prev; delay[ndelay][1]=at; delay[ndelay][2]=amount-now; ++ndelay;
			}
		}
		for(int i=ndelay-1;i>=0;--i) {
			assert(nans<180000); ans[nans][0]=delay[i][0]; ans[nans][1]=delay[i][1]; ans[nans][2]=delay[i][2]; ++nans;
		}
	}

	REP(i,n) if(have[i]!=want[i]) return false;
	return true;
}

void output(bool solved) {
	if(!solved) { printf("NO\n"); return; }
	printf("%d\n",nans); REP(i,nans) printf("%d %d %d\n",ans[i][0]+1,ans[i][1]+1,ans[i][2]);
}

void run(int casenr) {
	input();
	bool ret=solve();
	output(ret);
}

int oldhave[300];

void test() {
	int seed=1371310971; //time(NULL); printf("%d\n",seed);
	srand(seed);
	n=100; m=1000; maxvol=1000;
	REP(i,n) REP(j,n) { d[i][j]=i==j?0:INT_MAX; nxt[i][j]=-1; }
	REP(i,m) { int a=rand()%n,b=rand()%n; if(a==b) continue; d[a][b]=d[b][a]=1; nxt[a][b]=b; nxt[b][a]=a; }
	int sum=maxvol*n*9/10;
	{ int left=sum; REP(i,n) { int maxrem=(n-i-1)*maxvol; int minnow=left>maxrem?left-maxrem:0; int x=min(maxvol-minnow-50,left); have[i]=x<=0?minnow:minnow+rand()%x; left-=have[i]; } }
	{ int left=sum; REP(i,n) { int maxrem=(n-i-1)*maxvol; int minnow=left>maxrem?left-maxrem:0; int x=min(maxvol-minnow-50,left); want[i]=x<=0?minnow:minnow+rand()%x; left-=want[i]; } }
//	REP(i,n) printf("%d: %d -> %d\n",i,have[i],want[i]);
//	REP(i,n) FOR(j,i+1,n) if(d[i][j]==1) printf("%d %d\n",i,j);
	REP(i,n) oldhave[i]=have[i];
	if(!solve()) { printf("not solved\n"); return; }
	REP(i,n) have[i]=oldhave[i];
//	REP(j,nans) printf("%d %d %d\n",ans[j][0],ans[j][1],ans[j][2]);
	REP(i,nans) {
//		printf("doing %d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
//		REP(j,n) printf("%d: %d -> %d\n",j,have[j],want[j]); puts("");
		int a=ans[i][0],b=ans[i][1],c=ans[i][2];
		assert(d[a][b]==1);
		assert(have[a]>=c);
		have[a]-=c; have[b]+=c;
		assert(have[b]<=maxvol);
	}
	REP(i,n) assert(have[i]==want[i]);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
//	test();


	return 0;
}
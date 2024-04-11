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

const int MAXN=1000000+2;

int len,n1,n2,treload;
int x1[MAXN],x2[MAXN];

int x[MAXN],nx;
bool blocked[MAXN][2];

int dp[MAXN][2];
int pi[MAXN][2];
int pj[MAXN][2];
int pkind[MAXN][2];
int pshoot[MAXN][2];

int changes[2*MAXN],nchanges;
pair<int,int> shots[2*MAXN]; int nshots;

void upd(int ni,int nj,int i,int j,int val,int kind,int shoot) {
	if(val>=dp[ni][nj]) return;
	dp[ni][nj]=val,pi[ni][nj]=i,pj[ni][nj]=j,pkind[ni][nj]=kind,pshoot[ni][nj]=shoot;
}

void run() {
	scanf("%d%d%d%d",&len,&n1,&n2,&treload); REP(i,n1) scanf("%d",&x1[i]); REP(i,n2) scanf("%d",&x2[i]);
	//len=1000000000; n1=n2=(MAXN-1)/2; treload=1; REP(i,n1) x1[i]=(rand()%1000*1000000+rand()%1000*1000+rand()%1000)%len; REP(i,n2) x2[i]=(rand()%1000*1000000+rand()%1000*1000+rand()%1000)%len;
	
	nx=0; REP(i,n1) x[nx++]=x1[i]; REP(i,n2) x[nx++]=x2[i]; x[nx++]=0; x[nx++]=len+1; sort(x,x+nx); nx=unique(x,x+nx)-x;
	REP(i,nx) blocked[i][0]=blocked[i][1]=false; REP(i,n1) { int idx=lower_bound(x,x+nx,x1[i])-x; blocked[idx][0]=true; } REP(i,n2) { int idx=lower_bound(x,x+nx,x2[i])-x; blocked[idx][1]=true; }


	REP(i,nx) dp[i][0]=dp[i][1]=INT_MAX;
	dp[0][0]=dp[0][1]=treload;
	REP(i,nx-1) {
		//printf("%d: %c%c",x[i],blocked[i][0]?'#':'.',blocked[i][1]?'#':'.'); REP(j,2) if(dp[i][j]!=INT_MAX) printf(" %3d",dp[i][j]); else printf(" XXX"); puts("");
		REP(j,2) if(dp[i][j]!=INT_MAX) {
			// keep lane
			{
				int val=dp[i][j];
				if(!blocked[i+1][j]) {
					upd(i+1,j,i,j,val,0,-1);
				} else if(dp[i][j]<x[i+1]) {
					upd(i+1,j,i,j,val+treload,0,val);
				}
			}
			// switch lane
			bool candirect=!blocked[i][1-j];
			if(x[i]+1<x[i+1]||candirect) {
				int val=max(dp[i][j],x[i]+(!candirect?1:0));
				if(!blocked[i+1][1-j]) {
					upd(i+1,1-j,i,j,val,candirect?1:2,-1);
				} else if(val<x[i+1]) {
					upd(i+1,1-j,i,j,val+treload,candirect?1:2,val);
				}
			}
		}
	}

	int ti=nx-1,tj=-1; REP(j,2) if(dp[ti][j]!=INT_MAX) { tj=j; break; }
	if(tj==-1) { printf("No\n"); return; }
	printf("Yes\n");
	nchanges=0,nshots=0;
	{
		int i=ti,j=tj;
		while(true) {
			if(i==0) { if(j==1) changes[nchanges++]=x[i]; break; }
			int ii=pi[i][j],jj=pj[i][j],kind=pkind[i][j],shoot=pshoot[i][j];
			if(shoot!=-1) shots[nshots++]=MP(shoot,j+1);
			i=ii,j=jj; if(kind==1) changes[nchanges++]=x[i]; if(kind==2) changes[nchanges++]=x[i]+1;
		}
		reverse(changes,changes+nchanges);
		reverse(shots,shots+nshots);
		printf("%d\n",nchanges); REP(i,nchanges) { if(i!=0) printf(" "); printf("%d",changes[i]); } puts("");
		printf("%d\n",nshots); REP(i,nshots) printf("%d %d\n",shots[i].first,shots[i].second);
	}


	
}

int main() {
	run();
	return 0;
}
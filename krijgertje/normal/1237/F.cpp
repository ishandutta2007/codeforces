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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXDIM=3600;
const int MAXN=2400;
const int MOD=998244353;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int h,w,n;
int dom[MAXN][4];

int dp[MAXDIM+1][MAXDIM+1];


int fac[MAXDIM+1];
int choose[MAXDIM+1][MAXDIM+1];

void calcways(char state[MAXDIM+1],int dim,int ways[MAXDIM+1][MAXDIM+1]) {
	//printf("%s\n",state);
	memset(dp,0,sizeof(dp));
	inc(dp[0][0],1);
	REP(i,dim) REPE(j,dim/2) if(dp[i][j]!=0) {
		inc(dp[i+1][j],dp[i][j]);
		if(i+1<dim&&state[i]=='.'&&state[i+1]=='.') inc(dp[i+2][j+1],dp[i][j]);
	}
	//printf("double:"); REPE(a,dim/2) printf(" %d",dp[dim][a]); puts("");
	memset(ways,0,sizeof(ways));
	int nfree=0; REP(i,dim) if(state[i]=='.') ++nfree;
	REPE(a,dim/2) { int cur=dp[dim][a]; if(cur==0) continue; cur=(ll)cur*fac[a]%MOD; REPE(b,nfree-2*a) ways[a][b]=(ll)cur*choose[nfree-2*a][b]%MOD; }
	//REPE(a,dim/2) REPE(b,nfree-2*a) if(ways[a][b]>0) printf("(%d,%d)=%d\n",a,b,ways[a][b]);
}

char rowstate[MAXDIM+1];
char colstate[MAXDIM+1];

int rowways[MAXDIM+1][MAXDIM+1];
int colways[MAXDIM+1][MAXDIM+1];

int solve() {
	fac[0]=1; FORE(i,1,MAXDIM) fac[i]=(ll)fac[i-1]*i%MOD;
	REPE(i,MAXDIM) { choose[i][0]=choose[i][i]=1; FOR(j,1,i) { choose[i][j]=choose[i-1][j-1]; inc(choose[i][j],choose[i-1][j]); } }

	REP(i,h) rowstate[i]='.'; rowstate[h]='\0';
	REP(i,w) colstate[i]='.'; colstate[w]='\0';
	REP(i,n) { int lx=dom[i][0],hx=dom[i][2]; FORE(x,lx,hx) rowstate[x]='#'; }
	REP(i,n) { int ly=dom[i][1],hy=dom[i][3]; FORE(y,ly,hy) colstate[y]='#'; }
	calcways(rowstate,h,rowways);
	calcways(colstate,w,colways);
	int ret=0; REPE(a,MAXDIM/2) REPE(b,MAXDIM-2*a) ret=(ret+(ll)rowways[a][b]*colways[b][a])%MOD; return ret;
}

void run() {
	scanf("%d%d%d",&h,&w,&n);
	REP(i,n) REP(j,4) scanf("%d",&dom[i][j]),--dom[i][j];
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
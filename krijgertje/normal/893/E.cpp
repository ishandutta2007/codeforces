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

const int MAXX=1000000;
const int MAXY=1000000;
const int MAXCNT=20;
const int MOD=1000000007;

int dmn[MAXX+1];
int p2[MAXY+1];
int C[MAXY+MAXCNT+1][MAXCNT+1];

int calc(int nparts,int cnt) {
	return C[cnt+nparts-1][cnt];
}

void run() {
	memset(dmn,-1,sizeof(dmn)); FORE(i,2,MAXX) if(dmn[i]==-1) for(int j=i;j<=MAXX;j+=i) if(dmn[j]==-1) dmn[j]=i;
	p2[0]=1; FORE(i,1,MAXY) p2[i]=(ll)p2[i-1]*2%MOD;
	REPE(i,MAXY+MAXCNT) { C[i][0]=1; if(i<=MAXCNT) C[i][i]=1; FOR(j,1,min(i,MAXCNT+1)) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD; }
	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		int x,y; scanf("%d%d",&x,&y);
		int ans=p2[y-1];
		while(x!=1) { int p=dmn[x],cnt=0; while(dmn[x]==p) x/=p,++cnt; ans=(ll)ans*calc(y,cnt)%MOD; }
		printf("%d\n",ans);
	}
}

int main() {
	run();
	return 0;
}
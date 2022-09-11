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

const int MAXN=47;
const int MAXM=MAXN/2; // 23

int n;
char g[MAXN][MAXN+1];

bool same[MAXN][MAXN];
int comp[MAXN],compsz[MAXN],ncomp;

int m;
int mp[MAXN];
bool conn[MAXM][MAXM];

int one[1<<MAXM];
int sub[1<<MAXM];

ll ways[MAXM+1];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%s",g[i]);

	REP(i,n) REP(j,n) same[i][j]=i==j||g[i][j]=='A';
	REP(k,n) REP(i,n) REP(j,n) if(same[i][k]&&same[k][j]) same[i][j]=true;

	ncomp=0; REP(i,n) comp[i]=-1; REP(i,n) if(comp[i]==-1) { int c=ncomp++; compsz[c]=0; REP(j,n) if(same[i][j]) comp[j]=c,++compsz[c]; }
	REP(i,n) REP(j,n) if(g[i][j]=='X'&&comp[i]==comp[j]) { printf("-1\n"); return; }

	m=0; REP(i,ncomp) if(compsz[i]==1) mp[i]=-1; else mp[i]=m++;
	REP(i,m) REP(j,m) conn[i][j]=true;
	REP(i,n) REP(j,n) if(g[i][j]=='X'&&mp[comp[i]]!=-1&&mp[comp[j]]!=-1) conn[mp[comp[i]]][mp[comp[j]]]=false;

	one[0]=1; FOR(mask,1,1<<m) { int i=0; while((mask&(1<<i))==0) ++i; one[mask]=one[mask^(1<<i)]; REP(j,m) if((mask&(1<<j))!=0&&!conn[i][j]) one[mask]=0; }
	REP(mask,1<<m) sub[mask]=one[mask]; REP(i,m) REP(mask,1<<m) if(mask&(1<<i)) sub[mask]+=sub[mask^(1<<i)];

	REPE(i,m) ways[i]=0;
	REP(mask,1<<m) {
		int cnt=0; REP(i,m) if(mask&(1<<i)) ++cnt; ll times=cnt%2==m%2?+1:-1;
		REPE(i,m) {
			ways[i]+=times;
			times*=sub[mask];
		}
	}
	int need=0; while(need<m&&ways[need]==0) ++need;
	int singles=0; REP(i,ncomp) if(compsz[i]==1) ++singles;
	int ret=(n-singles)+need+singles-1;
	//printf("need=%d singles=%d\n",need,singles);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
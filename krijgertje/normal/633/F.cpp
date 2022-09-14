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

const int MAXN=100000;
const int MAXM=MAXN-1;

int n;
int val[MAXN];
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];

ll dp[MAXN][3][3]; // dp[at][i][j]=maximum in subtree if we can choose i 'free' paths and j paths to root
ll tmp[3][3];

void update(ll &a,ll b) { if(b>a) a=b; }
void go(int at,int par) {
	REP(i,3) REP(j,3) dp[at][i][j]=0;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		go(to,at);
		REP(i,3) REP(j,3) tmp[i][j]=dp[at][i][j],dp[at][i][j]=0;
		REP(i,3) REP(j,2) REP(ii,3-i) REP(jj,3-j) update(dp[at][ii+i][jj+j],tmp[ii][jj]+dp[to][i][j]);
	}
	REP(i,3) REP(j,3) tmp[i][j]=dp[at][i][j],dp[at][i][j]=0;
	REP(i,3) REP(j,2) update(dp[at][i][j],tmp[i][j]);
	REP(i,3-1) REP(j,3) update(dp[at][i+1][0],tmp[i][j]+val[at]);
	REP(i,3) REP(j,2) update(dp[at][i][1],tmp[i][j]+val[at]);
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&val[i]);
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	go(0,-1);
	printf("%I64d\n",dp[0][2][0]);
}

int main() {
	run();
	return 0;
}
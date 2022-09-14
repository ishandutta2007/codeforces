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


const int MAXN=150;
const int MAXSUM=MAXN*(MAXN-1)/2;

int n,want,have;
int x[MAXN];

int dp[2][MAXN+1][MAXSUM+1];
int xsum[MAXN+1];


void run() {
	scanf("%d%d%d",&n,&want,&have);
	REP(i,n) scanf("%d",&x[i]);
	xsum[0]=0; REP(i,n) xsum[i+1]=xsum[i]+x[i];

	int at=0,ret=xsum[want];
	REPE(j,want) dp[at][j][0]=0;
	FOR(i,0,n-want) { // i == #items chosen before
		memset(dp[1-at],0,sizeof(dp[1-at]));
		FORE(k,(0+i-1)*i/2,(want+i-1+want)*i/2) { // k == sum of those items
			int mx=0;
			FORE(j,i,want+i) {
				if(k>(j-1+j-i)*i/2) continue;
				if(dp[at][j][k]>mx) mx=dp[at][j][k];
				dp[1-at][j+1][k+j]=x[j]+mx;
			}
		}
		//printf("%d:",i+1); FORE(j,i,want+i) { printf(" %d(%d)[",j+1,(0+i-1)*i/2+j); FORE(k,(0+i-1)*i/2,(want+i-1+want)*i/2) { if(k!=(0+i-1)*i/2) printf(","); printf("%d",dp[1-at][j+1][k+j]); } printf("]"); } puts("");

		FORE(j,i,want+i) FORE(k,(0+i-1)*i/2,(want+i-1+want)*i/2) {
			if(k>(j-1+j-i)*i/2) continue;
			int ni=i+1,nj=j+1,nk=k+j,cur=xsum[want+ni]-dp[1-at][nj][nk],need=ni*(want+ni-1)-nk-(0+ni-1)*ni/2;
			//printf("ni=%d, nj=%d, nk=%d -> need=%d and cur=%d\n",ni,nj,nk,need,cur);
			if(need<=have&&cur<ret) ret=cur;
		}
		at=1-at;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
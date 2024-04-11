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

const int MAXN=7000;

int n;
int nopt[2],opt[2][MAXN];

int res[2][MAXN];
int nmoves[2][MAXN]; // nmoves[i][j] number of moves player i has when monster is on position j
int q[2*MAXN],qhead,qtail;

void run() {
	scanf("%d",&n);
	REP(i,2) { scanf("%d",&nopt[i]); REP(j,nopt[i]) scanf("%d",&opt[i][j]); }

	memset(res,-1,sizeof(res)); qhead=qtail=0;
	REP(i,2) REP(j,n) nmoves[i][j]=nopt[i];

	res[0][0]=1; q[qhead++]=0+2*0;
	res[1][0]=0; q[qhead++]=1+2*0;
	while(qtail<qhead) {
		int t=q[qtail]%2,x=q[qtail]/2; ++qtail;
		REP(i,nopt[1-t]) {
			int d=opt[1-t][i];
			int px=(x-d+n)%n;
			//printf("(%d,%d) -> (%d,%d) [%d %d]\n",1-t,px,t,x,res[1-t][px],nmoves[1-t][px]);
			if(res[1-t][px]!=-1) continue;
			if(res[t][x]==1-t) { res[1-t][px]=1-t; q[qhead++]=1-t+2*px; }
			if(res[t][x]==t&&--nmoves[1-t][px]==0) { res[1-t][px]=t; q[qhead++]=1-t+2*px; }
		}
	}
	REP(i,2) { FOR(j,1,n) { if(j!=1) printf(" "); printf("%s",res[i][j]==i?"Win":res[i][j]==1-i?"Lose":"Loop"); } puts(""); }
}

int main() {
	run();
	return 0;
}
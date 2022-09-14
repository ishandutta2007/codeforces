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

const int MAXH=30;
const int MAXW=30;
const int MAXK=50;

int cost[MAXH+1][MAXW+1][MAXK+1];

void run() {
	int h,w,k; scanf("%d%d%d",&h,&w,&k); printf("%d\n",cost[h][w][k]);
}

int main() {
	REPE(x,MAXH) REPE(k,MAXK) cost[x][0][k]=k==0?0:INT_MAX;
	REPE(y,MAXH) REPE(k,MAXK) cost[0][y][k]=k==0?0:INT_MAX;
	FORE(x,1,MAXH) FORE(y,1,MAXW) REPE(k,MAXK) {
		cost[x][y][k]=x*y==k||k==0?0:INT_MAX;
		FOR(xx,1,x) REPE(kk,k) if(cost[xx][y][kk]!=INT_MAX&&cost[x-xx][y][k-kk]!=INT_MAX&&cost[xx][y][kk]+cost[x-xx][y][k-kk]+y*y<cost[x][y][k]) cost[x][y][k]=cost[xx][y][kk]+cost[x-xx][y][k-kk]+y*y;
		FOR(yy,1,y) REPE(kk,k) if(cost[x][yy][kk]!=INT_MAX&&cost[x][y-yy][k-kk]!=INT_MAX&&cost[x][yy][kk]+cost[x][y-yy][k-kk]+x*x<cost[x][y][k]) cost[x][y][k]=cost[x][yy][kk]+cost[x][y-yy][k-kk]+x*x;
		//if(cost[x][y][k]!=INT_MAX&&x*y!=k) printf("%d %d %d = %d\n",x,y,k,cost[x][y][k]);
	}

	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}
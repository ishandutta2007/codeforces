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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=50;

int n;
int g[MAXN][MAXN];

int rowpref[MAXN][MAXN];
int colpref[MAXN][MAXN];
int invcolpref[MAXN][MAXN];

int rowpos[MAXN];
int colmatch[MAXN];
int rowmatch[MAXN];


void solve() {
	printf("B\n"); fflush(stdout);
	char alicedir; int startidx; scanf(" %c%d",&alicedir,&startidx); --startidx;

	bool rowprefersmall=startidx<n?alicedir=='I':alicedir=='D',colprefersmall=!rowprefersmall;
	REP(i,n) {
		REP(j,n) rowpref[i][j]=colpref[i][j]=j;
		sort(rowpref[i],rowpref[i]+n,[&i,&rowprefersmall](const int &a,const int &b) { return rowprefersmall?g[i][a]<g[i][b]:g[i][a]>g[i][b]; });
		sort(colpref[i],colpref[i]+n,[&i,&colprefersmall](const int &a,const int &b) { return colprefersmall?g[a][i]<g[b][i]:g[a][i]>g[b][i]; });
		REP(j,n) invcolpref[i][colpref[i][j]]=j;
	}
	//REP(i,n) { printf("rowpref%d:",i); REP(j,n) printf(" %d",rowpref[i][j]); puts(""); }
	//REP(i,n) { printf("colpref%d:",i); REP(j,n) printf(" %d",colpref[i][j]); puts(""); }

	queue<int> q; REP(i,n) rowpos[i]=0,q.push(i),colmatch[i]=-1;
	while(!q.empty()) {
		int atrow=q.front(); q.pop();
		assert(rowpos[atrow]<n); int tocol=rowpref[atrow][rowpos[atrow]++];
		if(colmatch[tocol]==-1||invcolpref[tocol][atrow]<invcolpref[tocol][colmatch[tocol]]) {
			if(colmatch[tocol]!=-1) q.push(colmatch[tocol]);
			colmatch[tocol]=atrow;
		} else {
			q.push(atrow);
		}
	}
	REP(i,n) rowmatch[colmatch[i]]=i;
	//printf("rowmatch:"); REP(i,n) printf(" %d",rowmatch[i]); puts("");
	//printf("colmatch:"); REP(i,n) printf(" %d",colmatch[i]); puts("");

	for(int at=startidx,me,opp;at!=-1;at=opp) {
		if(at==-2) exit(0);
		me=at<n?n+rowmatch[at]:colmatch[at-n];
		printf("%d\n",me+1); fflush(stdout);
		scanf("%d",&opp); if(opp>=0) --opp;
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) REP(j,n) scanf("%d",&g[i][j]);
	solve();
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(casenr,1,ncase) run();
	return 0;
}
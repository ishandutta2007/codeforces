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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

typedef struct Song { double p; int t; } Song;

int nsongs,T;
Song songs[5000];

double dp[2][5001]; 
double a[2][5001];
double b[2][5001];
// dp[i][j] = expected number of songs if we start to listen to song i with j seconds remaining (dp[i][j]=0 when j<0)
// dp[i][j] = a[i][j]+b[i][j]
// a[i][j] = sum((1-songs[i].p)^(k-1)*songs[i].p*(1+dp[i+1][j-k]), k=1..songs[i].t)
// b[i][j] = (1-songs[i].p)^(songs[i].t)*(1+dp[i+1][j-songs[j].t])
// a[i][j] =  (1-songs[i].p)*a[i][j-1] + songs[i].p*(1+dp[i+1][j-1]) - songs[i].p*b[i][j-1]


void run() {
	scanf("%d%d",&nsongs,&T);
	REP(i,nsongs) { int p; scanf("%d%d",&p,&songs[i].t); songs[i].p=0.01*p; }

	int at=0,to=1;
	REPE(j,T) dp[at][j]=0;
	for(int i=nsongs-1;i>=0;--i) {
		double pt=1; REP(j,songs[i].t) pt*=1-songs[i].p;
		REPE(j,T) {
			a[to][j]=j==0?0:(1-songs[i].p)*a[to][j-1]+songs[i].p*(1+dp[at][j-1])-songs[i].p*b[to][j-1];
			b[to][j]=j<songs[i].t?0:pt*(1+dp[at][j-songs[i].t]);
			dp[to][j]=a[to][j]+b[to][j];
			//printf("%d %d -> %.9lf %.9lf %.9lf [%.9lf]\n",i,j,a[to][j],b[to][j],dp[to][j],pt);
		}
		at=1-at; to=1-to;
	}
	printf("%.9lf\n",dp[at][T]);
}

int main() {
	run();
	return 0;
}
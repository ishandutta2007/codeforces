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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int n,m;

int road[500][500];
int dist[500][500];
int nfirst[500][500];
int ntotal[500][500];

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) REP(j,n) road[i][j]=-1;
	REP(i,m) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; road[a][b]=road[b][a]=c; }
	REP(i,n) REP(j,n) dist[i][j]=i==j?0:road[i][j];
	REP(k,n) REP(i,n) REP(j,n) if(dist[i][k]!=-1&&dist[k][j]!=-1&&(dist[i][j]==-1||dist[i][k]+dist[k][j]<dist[i][j])) dist[i][j]=dist[i][k]+dist[k][j];
	REP(i,n) REP(j,n) { nfirst[i][j]=0; REP(k,n) if(road[i][k]!=-1&&dist[k][j]!=-1&&road[i][k]+dist[k][j]==dist[i][j]) ++nfirst[i][j]; }
	REP(i,n) REP(j,n) { ntotal[i][j]=0; REP(k,n) if(dist[i][k]!=-1&&dist[k][j]!=-1&&dist[i][k]+dist[k][j]==dist[i][j]) ntotal[i][j]+=nfirst[k][j]; }
	bool first=true; REP(i,n) FOR(j,i+1,n) { if(!first) printf(" "); else first=false; printf("%d",ntotal[i][j]); } puts("");

}

int main() {
	run();
	return 0;
}
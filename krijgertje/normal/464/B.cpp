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

int perm[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
int p[8][3];

int q[8][3];
int r[8];


bool can[8][4];
bool been[8];
int match[4];
bool augment(int at) {
	if(been[at]) return false; else been[at]=true;
	REP(to,4) if(can[at][to]&&(match[to]==-1||augment(match[to]))) {
		match[to]=at;
		return true;
	}
	return false;
}
int maxmatch() {
	int ret=0;
	REP(i,4) match[i]=-1;
	REP(i,8) {
		memset(been,false,sizeof(been));
		if(augment(i)) ++ret;
	}
	return ret;
}

void run() {
	REP(i,8) REP(j,3) scanf("%d",&p[i][j]);

	REP(j,3) q[0][j]=p[0][j];
	FOR(a,1,8) FOR(b,a+1,8) FOR(c,b+1,8) REP(pa,6) REP(pb,6) REP(pc,6) {
		REP(j,3) q[1][j]=p[a][perm[pa][j]];
		REP(j,3) q[2][j]=p[b][perm[pb][j]];
		REP(j,3) q[3][j]=p[c][perm[pc][j]];
		ll da2=0; REP(j,3) da2+=(ll)(q[0][j]-q[1][j])*(q[0][j]-q[1][j]);
		ll db2=0; REP(j,3) db2+=(ll)(q[0][j]-q[2][j])*(q[0][j]-q[2][j]);
		ll dc2=0; REP(j,3) dc2+=(ll)(q[0][j]-q[3][j])*(q[0][j]-q[3][j]);
		if(da2==0||db2!=da2||dc2!=da2) continue;
		ll ab=0; REP(j,3) ab+=(ll)(q[1][j]-q[0][j])*(q[2][j]-q[0][j]);
		ll bc=0; REP(j,3) bc+=(ll)(q[2][j]-q[0][j])*(q[3][j]-q[0][j]);
		ll ca=0; REP(j,3) ca+=(ll)(q[3][j]-q[0][j])*(q[1][j]-q[0][j]);
		if(ab!=0||bc!=0||ca!=0) continue;
		REP(j,3) q[4][j]=q[1][j]+(q[2][j]-q[0][j]);
		REP(j,3) q[5][j]=q[2][j]+(q[3][j]-q[0][j]);
		REP(j,3) q[6][j]=q[3][j]+(q[1][j]-q[0][j]);
		REP(j,3) q[7][j]=q[1][j]+(q[2][j]-q[0][j])+(q[3][j]-q[0][j]);
		//REP(i,8) { REP(j,3) printf("%d ",q[i][j]); printf("- "); } puts("");

		memset(can,false,sizeof(can));
		REP(s,8) if(s!=0&&s!=a&&s!=b&&s!=c) REP(t,4) REP(ps,6) {
			bool ok=true; REP(j,3) if(q[4+t][j]!=p[s][perm[ps][j]]) ok=false; if(ok) can[s][t]=true;
		}
		if(maxmatch()!=4) continue;

		REP(i,8) r[i]=-1; r[0]=0; r[a]=1; r[b]=2; r[c]=3; REP(i,4) r[match[i]]=4+i; REP(i,8) assert(r[i]!=-1);
		printf("YES\n"); REP(i,8) printf("%d %d %d\n",q[r[i]][0],q[r[i]][1],q[r[i]][2]); return;
	}
	printf("NO\n");
}

int main() {
	run();
	return 0;
}
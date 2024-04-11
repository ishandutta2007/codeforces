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

const int MAXN=1000;

int n,m;
int p[2*MAXN];
int e[MAXN][2];
int me;

int match[2*MAXN];
bool chosen[2*MAXN];

void solve() {
	int turn=1,nchosen=0,last=-1;
	REP(i,2*n) chosen[i]=false;
	REP(i,2*n) match[i]=-1; REP(i,m) REP(j,2) match[e[i][j]]=e[i][1-j];
	while(nchosen<2*n) {
		if(turn==me) {
			int cur=-1;
			if(last!=-1&&match[last]!=-1&&!chosen[match[last]]) {
				cur=match[last];
			}
			if(cur==-1) REP(i,2*n) if(!chosen[i]&&match[i]!=-1) {
				cur=p[i]>p[match[i]]?i:match[i];
				break;
			}
			if(cur==-1) REP(i,2*n) if(!chosen[i]&&(cur==-1||p[i]>p[cur])) cur=i;
			assert(cur!=-1);
			chosen[cur]=true; last=cur; ++nchosen;
			printf("%d\n",cur+1); fflush(stdout);
		} else {
			int cur; scanf("%d",&cur); if(cur==-1) exit(0); --cur;
			chosen[cur]=true; last=cur; ++nchosen;
		}
		turn=3-turn;
	}
}


void run() {
	scanf("%d%d",&n,&m);
	REP(i,2*n) scanf("%d",&p[i]);
	REP(i,m) REP(j,2) scanf("%d",&e[i][j]),--e[i][j];
	scanf("%d",&me);
	solve();
}

int main() {
	run();
	return 0;
}
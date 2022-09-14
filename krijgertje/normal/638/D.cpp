

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

const int MAXN=100;
const int MAXM=100;
const int MAXK=100;

int n,m,k;
char g[MAXN][MAXM][MAXK+1];

bool test(int x,int y,int z) {
	REP(pd,3) {
		int px=x-(pd==0?1:0),py=y-(pd==1?1:0),pz=z-(pd==2?1:0);
		if(px<0||py<0||pz<0||g[px][py][pz]!='1') continue;
		REP(nd,3) {
			int nx=x+(nd==0?1:0),ny=y+(nd==1?1:0),nz=z+(nd==2?1:0);
			if(nx>=n||ny>=m||nz>=k||g[nx][ny][nz]!='1') continue;
			if(pd==nd) return true;
			int xx=px+(nd==0?1:0),yy=py+(nd==1?1:0),zz=pz+(nd==2?1:0);
			if(g[xx][yy][zz]=='0') return true; else continue;
		}
	}
	return false;
}

void run() {
	scanf("%d%d%d",&n,&m,&k);
	REP(x,n) REP(y,m) scanf("%s",g[x][y]);

	int ret=0;
	REP(x,n) REP(y,m) REP(z,k) if(g[x][y][z]=='1') {
		if(test(x,y,z)) ++ret;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
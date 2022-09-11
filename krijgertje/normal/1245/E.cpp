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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXH=10;
const int MAXW=10;

int h=MAXH,w=MAXW;
int ladder[MAXH][MAXW];

double E[MAXH][MAXW];

vector<pair<int,int>> order;

double solve() {
	REP(x,h) REP(y,w) E[x][y]=1e200; E[0][0]=0.0;
	{ order.clear(); int x=h-1,y=0,dy=+1; while(true) { order.PB(MP(x,y)); int nx=x,ny=y+dy; if(ny>=w||ny<0) ny=y,--nx,dy=-dy; if(nx<0) break; x=nx,y=ny; } }
	for(int i=SZ(order)-2;i>=0;--i) {
		int x=order[i].first,y=order[i].second;
		int movecnt=0; double Esum=0;
		FORE(die,1,6) {
			int j=i+die; if(j>=SZ(order)) continue;
			++movecnt;
			int nx=order[j].first,ny=order[j].second;
			double cur=E[nx][ny];
			if(ladder[nx][ny]!=0) cur=min(cur,E[nx-ladder[nx][ny]][ny]);
			Esum+=cur;
		}
		//E[x][y]=1+(1-movecnt/6)*E[x][y]+1/6*Esum -> E[x][y]=(6+Esum)/movecnt
		assert(movecnt>0); E[x][y]=(6+Esum)/movecnt;
	}
	return E[h-1][0];
}


void run() {
	REP(x,h) REP(y,w) scanf("%d",&ladder[x][y]);
	printf("%.15lf\n",solve());
}

int main() {
	run();
	return 0;
}
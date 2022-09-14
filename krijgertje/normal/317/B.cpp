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

const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};
int n,nq;

int cnt[201][201];

void run(int casenr) {
	scanf("%d%d",&n,&nq);
	queue<pair<int,int> > q;
	memset(cnt,0,sizeof(cnt)); cnt[100][100]=n; if(n>=4) q.push(MP(100,100));
	int ops=0;
	while(!q.empty()) {
		int x=q.front().first,y=q.front().second; q.pop();
		int cur=cnt[x][y]; if(cur<4) continue; ++ops;
		int times=cur/4;
		cnt[x][y]=cur%4;
		REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k];
			int old=cnt[nx][ny];
			cnt[nx][ny]+=times;
			if(old<4&&old+times>=4) q.push(MP(nx,ny));
		}
	}
//	FORE(x,-30,+30) { FORE(y,-30,+30) printf("%d",cnt[100+x][100+y]); puts(""); }
	REP(qi,nq) {
		int x,y; scanf("%d%d",&x,&y);
		printf("%d\n",x<-100||x>100||y<-100||y>100?0:cnt[100+x][100+y]);
	}
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
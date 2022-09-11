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

const int DX[]={-2,-2,-1,-1,+1,+1,+2,+2};
const int DY[]={-1,+1,-2,+2,-2,+2,-1,+1};
int n;

int h,w;
vector<vector<int>> g;
int nused,nresult;

vector<pair<int,int>> ans;
queue<pair<int,int>> q;


void put(int sx,int sy) {
	if(g[sx][sy]==-1) return;
	++nused; ans.PB(MP(sx,sy));
	q=queue<pair<int,int>>();
	q.push(MP(sx,sy)); g[sx][sy]=-1;
	//printf("putting (%d,%d)\n",sx,sy);
	while(!q.empty()) {
		int x=q.front().first,y=q.front().second; q.pop();
		//printf("\t->(%d,%d)\n",x,y);
		++nresult;
		REP(k,8) {
			int nx=x+DX[k],ny=y+DY[k]; if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]==-1) continue;
			++g[nx][ny]; if(g[nx][ny]==4) g[nx][ny]=-1,q.push(MP(nx,ny));
		}
	}
}

void solve() {
	int sz;
	nused=nresult=0; ans.clear();
	if(n<=7) {
		sz=h=w=4;
		g=vector<vector<int>>(h,vector<int>(w,0));
	} else if(n<=13) {
		sz=h=w=7;
		g=vector<vector<int>>(h,vector<int>(w,0));
		put(0,3),put(2,3),put(4,3),put(6,3);
		put(3,0),put(3,2),put(3,4),put(3,6);
	} else {
		sz=n/2; //if(sz%2==0) --sz;
		h=w=sz;
		g=vector<vector<int>>(h,vector<int>(w,0));
		REP(x,sz) put(x,sz/2);
		REP(y,sz) put(sz/2,y);
		if(nused<n) put(sz/2+2,sz/2);
	}
	//printf("n=%d nused=%d nresult=%d\n",n,nused,nresult);
	REP(x,sz) REP(y,sz) if(nused<n) put(x,y);
}

void run() {
	scanf("%d",&n);
	solve();
	REP(i,n) printf("%d %d\n",ans[i].first,ans[i].second);
}

void research() {
	double worst=1e100;
	for(n=1;n<=1000;++n) {
		solve();
		double cur=1.0*nresult/n/n;
		if(cur<worst||cur<0.1) { printf("n=%d nused=%d nresult=%d -> %lf\n",n,nused,nresult,cur); worst=cur; }
		assert(nresult>=n*n/10);
		assert(nused<=n);
	}
}

int main() {
	//research();
	run();
	return 0;
}
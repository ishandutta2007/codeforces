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

const int MAXH=2000;
const int MAXW=2000;
const int DX[]={-1,0,+1,0},DY[]={0,-1,0,+1};

int h,w;
int sx,sy;
int canleft,canright;
char g[MAXH][MAXW+1];

int dst[MAXH][MAXW];
deque<pair<int,int>> q;

int solve() {
	q.clear(); REP(x,h) REP(y,w) dst[x][y]=INT_MAX;
	dst[sx][sy]=0; q.PB(MP(sx,sy));
	int ret=0;
	while(!q.empty()) {
		int x=q.front().first,y=q.front().second; q.pop_front(); ++ret;
		//printf("(%d,%d)=%d\n",x,y,dst[x][y]);
		REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k];
			if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]=='*'||dst[nx][ny]!=INT_MAX) continue;
			int ndst=dst[x][y]+(ny!=y?1:0);
			int extra=ndst-abs(ny-sy); assert(extra%2==0);
			if(extra/2+max(0,ny-sy)>canright) continue;
			if(extra/2+max(0,sy-ny)>canleft) continue;
			dst[nx][ny]=ndst; if(ndst==dst[x][y]) q.push_front(MP(nx,ny)); else q.PB(MP(nx,ny));
		}
	}
	return ret;
}

void run() {
	scanf("%d%d",&h,&w);
	scanf("%d%d",&sx,&sy),--sx,--sy;
	scanf("%d%d",&canleft,&canright);
	REP(x,h) scanf("%s",g[x]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
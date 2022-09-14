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

const int MAXN=30;
const int MAXT=5;
const int MAXX=MAXT*MAXN;

int n;
int t[MAXN];
bool g[MAXN+1][2*MAXX+1][2*MAXX+1][8];
bool vis[2*MAXX+1][2*MAXX+1];

int DX[]={-1,-1,0,+1,+1,+1,0,-1},DY[]={0,+1,+1,+1,0,-1,-1,-1};

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&t[i]); --t[0];
	memset(g,false,sizeof(g)); memset(vis,false,sizeof(vis));
	g[0][MAXX][MAXX][0]=true; vis[MAXX][MAXX]=true;
	REP(i,n) {
		REPE(x,2*MAXX) REPE(y,2*MAXX) REP(k,8) if(g[i][x][y][k]) {
			int cx=x,cy=y;
			REP(j,t[i]) {
				cx+=DX[k],cy+=DY[k]; assert(cx>=0&&cx<=2*MAXX&&cy>=0&&cy<=2*MAXX); vis[cx][cy]=true;
			}
			g[i+1][cx][cy][(k+1)%8]=g[i+1][cx][cy][(k+7)%8]=true;
		}
	}
	int mnx=MAXX,mxx=MAXX,mny=MAXX,mxy=MAXX; REPE(x,2*MAXX) REPE(y,2*MAXX) if(vis[x][y]) mnx=min(mnx,x),mxx=max(mxx,x),mny=min(mny,y),mxy=max(mxy,y);
	//FORE(x,mnx,mxx) { FORE(y,mny,mxy) printf("%c",x==MAXX&&y==MAXX?'#':vis[x][y]?'*':'-'); puts(""); }
	int ret=0; REPE(x,2*MAXX) REPE(y,2*MAXX) if(vis[x][y]) ++ret; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
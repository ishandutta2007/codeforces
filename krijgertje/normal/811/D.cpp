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

const int MAXH=100;
const int MAXW=100;
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1}; const char DC[]={'U','R','D','L'};

int h,w;
char g[MAXH][MAXW+1];

int d[MAXH][MAXW+1];
int qx[MAXH*MAXW],qy[MAXH*MAXW],qhead,qtail;
bool know[2],inv[2];

void go(char c,int &nx,int &ny) {
	printf("%c\n",c); fflush(stdout);
	scanf("%d%d",&nx,&ny); if(nx==-1&&ny==-1) exit(0); --nx,--ny;
}

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) scanf("%s",g[x]);
	REP(x,h) REP(y,w) d[x][y]=INT_MAX; qhead=qtail=0;
	REP(tx,h) REP(ty,w) if(g[tx][ty]=='F') {
		d[tx][ty]=0; qx[qhead]=tx,qy[qhead]=ty,++qhead;
		while(qtail<qhead) {
			int x=qx[qtail],y=qy[qtail]; ++qtail; //printf("(%d,%d)=%d\n",x,y,d[x][y]);
			REP(k,4) {
				int nx=x+DX[k],ny=y+DY[k]; if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]=='*'||d[nx][ny]!=INT_MAX) continue;
				d[nx][ny]=d[x][y]+1; qx[qhead]=nx,qy[qhead]=ny,++qhead;
			}
		}
	}
	int cx=0,cy=0; know[0]=know[1]=false;
	assert(d[cx][cy]!=INT_MAX);
	while(d[cx][cy]!=0) {
		int ck=-1;
		REP(k,4) { int nx=cx+DX[k],ny=cy+DY[k]; if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]=='*'||d[nx][ny]!=d[cx][cy]-1) continue; ck=k; break; } assert(ck!=-1);
		if(!know[ck%2]) {
			int nx,ny; go(DC[ck],nx,ny);
			if(nx==cx+DX[ck]&&ny==cy+DY[ck]) {
				know[ck%2]=true,inv[ck%2]=false;
				cx=nx,cy=ny;
			} else {
				know[ck%2]=true,inv[ck%2]=true;
			}
		} else {
			int nx,ny; go(DC[!inv[ck%2]?ck:(ck^2)],nx,ny);
			assert(nx==cx+DX[ck]&&ny==cy+DY[ck]);
			cx=nx,cy=ny;
		}
	}
}

int main() {
	run();
	return 0;
}
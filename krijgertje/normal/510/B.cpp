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

int h,w;
char g[50][51];
int id[50][50],nid;
int par[50][50];
const int DX[4]={-1,0,+1,0},DY[]={0,+1,0,-1};

int qx[50*50],qy[50*50],qhead,qtail;

void run() {
	scanf("%d%d",&h,&w);
	REP(i,h) scanf("%s",g[i]);

	REP(x,h) REP(y,w) id[x][y]=-1,par[x][y]=-2; nid=0;
	REP(sx,h) REP(sy,w) if(id[sx][sy]==-1) {
		//printf("(%d,%d)\n",sx,sy);
		qhead=qtail=0; qx[qhead]=sx; qy[qhead]=sy; ++qhead; par[sx][sy]=-1; id[sx][sy]=nid++;
		while(qtail<qhead) {
			int x=qx[qtail],y=qy[qtail]; ++qtail;
			//printf("\t(%d,%d)\n",x,y);
			REP(k,4) {
				int nx=x+DX[k],ny=y+DY[k];
				if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]!=g[x][y]||id[nx][ny]!=-1&&par[x][y]==id[nx][ny]) continue;
				//printf("\t\t(%d,%d)\n",nx,ny);
				if(id[nx][ny]!=-1) { printf("Yes\n"); return; }
				qx[qhead]=nx; qy[qhead]=ny; ++qhead; par[nx][ny]=id[x][y]; id[nx][ny]=nid++;
			}
		}
	}
	printf("No\n");
}

int main() {
	run();
	return 0;
}
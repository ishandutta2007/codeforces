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

const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

int h,w;
char g[500][501];
int sx,sy,tx,ty;

int qx[500*500],qy[500*500],qhead,qtail;
bool been[500][500];

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) scanf("%s",g[x]);
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty); --sx,--sy,--tx,--ty;

	memset(been,false,sizeof(been));
	qhead=qtail=0; qx[qhead]=sx,qy[qhead]=sy,been[sx][sy]=true,++qhead;
	bool ret=false;
	while(qtail<qhead) {
		int x=qx[qtail],y=qy[qtail]; ++qtail;
		REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k];
			if(nx<0||nx>=h||ny<0||ny>=w) continue;
			if(nx==tx&&ny==ty) {
				if(g[tx][ty]=='X') {
					ret=true;
				} else {
					REP(kk,4) {
						int xx=nx+DX[kk],yy=ny+DY[kk];
						if(xx<0||xx>=h||yy<0||yy>=w||xx==x&&yy==y||g[xx][yy]=='X') continue;
						ret=true;
					}
				}
			} else if(g[nx][ny]=='.'&&!been[nx][ny]) {
				qx[qhead]=nx,qy[qhead]=ny,been[nx][ny]=true,++qhead;
			}
		}
	}
	printf("%s\n",ret?"YES":"NO");
}

int main() {
	run();
	return 0;
}
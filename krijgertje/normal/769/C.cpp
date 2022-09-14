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

const int MAXH=1000;
const int MAXW=1000;
const int MAXLEN=1000000;
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1}; const char DC[]={'U','R','D','L'};

int h,w,len;
char g[MAXH][MAXW+1];
int d[MAXH][MAXW];
int qx[MAXH*MAXW],qy[MAXH*MAXW],qhead,qtail;
char ret[MAXLEN+1];

void run() {
	scanf("%d%d%d",&h,&w,&len);
	REP(x,h) scanf("%s",g[x]);
	int sx=-1,sy=-1; REP(x,h) REP(y,w) if(g[x][y]=='X') sx=x,sy=y,g[x][y]='.';
	memset(d,-1,sizeof(d)); qhead=qtail=0; d[sx][sy]=0; qx[qhead]=sx,qy[qhead]=sy,++qhead;
	while(qtail<qhead) {
		int x=qx[qtail],y=qy[qtail]; ++qtail;
		REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k];
			if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]=='*'||d[nx][ny]!=-1) continue;
			d[nx][ny]=d[x][y]+1; qx[qhead]=nx,qy[qhead]=ny,++qhead;
		}
	}
	for(int x=sx,y=sy,i=0;i<len;++i) {
		int bx=-1,by=-1; char bc='?'; int rem=len-i-1;
		REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k]; char nc=DC[k];
			if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]=='*'||d[nx][ny]==-1||d[nx][ny]>rem||bc!='?'&&nc>=bc) continue;
			bc=nc,bx=nx,by=ny;
		}
		//printf("-> %d %d (%c)\n",bx,by,bc);
		if(bc=='?') { printf("IMPOSSIBLE\n"); return; }
		ret[i]=bc,x=bx,y=by;
	}
	ret[len]='\0'; printf("%s\n",ret);
}

int main() {
	run();
	return 0;
}
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
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

int h,w;
char g[MAXH][MAXW+1];

int id[MAXH][MAXW],nid,cnt[MAXH*MAXW];
int qx[MAXH*MAXW],qy[MAXH*MAXW],qhead,qtail;


void run() {
	scanf("%d%d",&h,&w); REP(x,h) scanf("%s",g[x]);
	memset(id,-1,sizeof(id)); nid=0;
	REP(sx,h) REP(sy,w) if(g[sx][sy]=='.'&&id[sx][sy]==-1) {
		id[sx][sy]=nid++; qhead=qtail=0; qx[qhead]=sx,qy[qhead]=sy,++qhead;
		while(qtail<qhead) {
			int x=qx[qtail],y=qy[qtail]; ++qtail;
			REP(k,4) {
				int nx=x+DX[k],ny=y+DY[k]; if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]!='.'||id[nx][ny]!=-1) continue;
				id[nx][ny]=id[x][y]; qx[qhead]=nx,qy[qhead]=ny,++qhead;
			}
		}
		cnt[id[sx][sy]]=qhead;
	}
	REP(x,h) REP(y,w) if(g[x][y]!='.') {
		int cur[4],ncur=0;
		REP(k,4) {
			int nx=x+DX[k],ny=y+DY[k]; if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]!='.') continue;
			cur[ncur++]=id[nx][ny];
		}
		sort(cur,cur+ncur); ncur=unique(cur,cur+ncur)-cur;
		int sum=1; REP(k,ncur) sum+=cnt[cur[k]]; g[x][y]='0'+sum%10;
	}
	REP(x,h) printf("%s\n",g[x]);
}

int main() {
	run();
	return 0;
}
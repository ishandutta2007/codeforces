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

const int MAXH=400;
const int MAXW=400;
const int MAXR=400;
const int MAXC=400;
const int NBIT=64;
const int MAXBW=(MAXW+NBIT-1)/NBIT;
const int MAXTBW=(3*MAXW+NBIT-1)/NBIT;

int h,w,bw;
char g[MAXH][MAXW+1];
int r,c;
char p[MAXR][MAXC+1];

ull ret[MAXH][MAXBW];
ull msk[26][MAXH][MAXTBW];

void printmsk(ull val) { REP(i,NBIT) printf("%c",(val&(1ULL<<(i%NBIT)))?'1':'0'); }
void run() {
	scanf("%d%d",&h,&w); REP(x,h) scanf("%s",g[x]);
	scanf("%d%d",&r,&c); REP(x,r) scanf("%s",p[x]);
	//h=300,w=300,r=300,c=300; REP(x,h) REP(y,w) g[x][y]='a'; g[173][14]='b'; REP(x,r) REP(y,c) p[x][y]=(x+y)%2==0?'?':'a';
	/*if(h==300&&w==300) {
		REP(x,h) REP(y,w) if(g[x][y]!='a') printf("g[%d][%d]=%c\n",x,y,g[x][y]);
		printf("r=%d c=%d\n",r,c);
		REP(x,r) REP(y,c) if(p[x][y]!=((x+y)%2==0?'?':'a')) printf("p[%d][%d]=%c\n",x,y,p[x][y]);
	}*/
	

	bw=(w+NBIT-1)/NBIT;
	memset(ret,false,sizeof(ret));
	REP(x,h) REP(y,w) ret[x][y/NBIT]|=1ULL<<(y%NBIT);
	memset(msk,0,sizeof(msk));
	REP(x,h) REP(y,w) msk[g[x][y]-'a'][x][y/NBIT]|=1ULL<<(y%NBIT);
	REP(x,h) REP(y,w) msk[g[x][y]-'a'][x][(w+y)/NBIT]|=1ULL<<((w+y)%NBIT);
	REP(x,h) REP(y,w) msk[g[x][y]-'a'][x][(w+w+y)/NBIT]|=1ULL<<((w+w+y)%NBIT);
	REP(z,26) REP(x,h) REP(y,MAXTBW) FOR(b,NBIT,64) msk[z][x][y]|=1ULL<<b;

	
	REP(dx,r) REP(dy,c) if(p[dx][dy]!='?') {
		int z=p[dx][dy]-'a'; int DX=dx%h,DY=dy%w;
		REP(x,h) {
			int xx=x+DX; if(xx>=h) xx-=h;
			REP(i,bw) {
				int a=i+DY/NBIT,ashft=DY%NBIT; //if(dx==173&&dy==14&&x==0&&i==0) { printf("c=%c (%d,%d) %d %d msk=",p[dx][dy],x,i,a,ashft); printmsk(~((~msk[z][xx][a])>>ashft)); puts(""); }
				ret[x][i]&=~((~msk[z][xx][a])>>ashft);
				if(ashft==0) continue;
				int b=a+1,bshft=NBIT-ashft;
				ret[x][i]&=~((~msk[z][xx][b])<<bshft);
				// dy=0: ret[x][i]&=msk[z][xx][i]
				// dy=1: ret[x][i]&=msk[z][xx][i]>>1 ret[x][i]&=msk[z][xx][i+1]<<63
			}
		}
	}

	REP(x,h) { REP(y,w) printf("%c",(ret[x][y/NBIT]&(1ULL<<(y%NBIT)))?'1':'0'); puts(""); }
}

int main() {
	run();
	return 0;
}
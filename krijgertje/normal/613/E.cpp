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

const int MAXW=2000;
const int MAXLEN=2000;
const int MOD=1000000007;

int w,len;
char g[2][MAXW+1];
char s[MAXLEN+1];

int matchlft[2][MAXW][MAXLEN]; // matchlft[x][y][z]: number of matches with s[z..] if we go left from (x,y)
int matchrgt[2][MAXW][MAXLEN]; // matchrgt[x][y][z]: number of matches with s[z..] if we go right from (x,y)

int wayslft[2][MAXW][MAXLEN]; // wayslft[x][y][z]: ways to make if we are at (x,y) need to match s[z..] and are only allowed to use cells with cy<=y
int waysrgt[2][MAXW][MAXLEN]; // waysrgt[x][y][z]: ways to make if we are at (x,y) need to match s[z..] and are only allowed to use cells with cy>=y

inline void inc(int &a,const int &b) { if((a+=b)>=MOD) a-=MOD; }
void run() {
	scanf("%s%s%s",g[0],g[1],s); w=min(strlen(g[0]),strlen(g[1])); len=strlen(s);
	
	memset(matchlft,0,sizeof(matchlft));
	for(int z=len-1;z>=0;--z) REP(x,2) REP(y,w) matchlft[x][y][z]=g[x][y]!=s[z]?0:1+(z==len-1||y==0?0:matchlft[x][y-1][z+1]);
	for(int z=len-1;z>=0;--z) REP(x,2) REP(y,w) matchrgt[x][y][z]=g[x][y]!=s[z]?0:1+(z==len-1||y==w-1?0:matchrgt[x][y+1][z+1]);
	//REP(z,len) REP(x,2) REP(y,w) if(matchlft[x][y][z]!=0) printf("%d: (%d,%d) lft %d\n",z,x,y,matchlft[x][y][z]);
	//REP(z,len) REP(x,2) REP(y,w) if(matchrgt[x][y][z]!=0) printf("%d: (%d,%d) rgt %d\n",z,x,y,matchrgt[x][y][z]);

	memset(wayslft,0,sizeof(wayslft));
	REP(y,w) REP(x,2) REP(z,len) {
		if(g[x][y]!=s[z]) continue;
		int rem=len-z;
		if(rem==1) inc(wayslft[x][y][z],1);
		else if(rem>=2&&y!=0) inc(wayslft[x][y][z],wayslft[x][y-1][z+1]);
		if(g[1-x][y]==s[z+1]) {
			if(rem==2) inc(wayslft[x][y][z],1);
			else if(rem>=3&&y!=0) inc(wayslft[x][y][z],wayslft[1-x][y-1][z+2]);
		}
		if(rem>=4&&rem%2==0&&y-rem/2+1>=0&&matchlft[x][y][z]>=rem/2&&matchrgt[1-x][y-rem/2+1][z+rem/2]>=rem/2) inc(wayslft[x][y][z],1);
	}
	memset(waysrgt,0,sizeof(waysrgt));
	for(int y=w-1;y>=0;--y) REP(x,2) REP(z,len) {
		if(g[x][y]!=s[z]) continue;
		int rem=len-z;
		if(rem==1) inc(waysrgt[x][y][z],1);
		else if(rem>=2&&y!=w-1) inc(waysrgt[x][y][z],waysrgt[x][y+1][z+1]);
		if(g[1-x][y]==s[z+1]) {
			if(rem==2) inc(waysrgt[x][y][z],1);
			else if(rem>=3&&y!=w-1) inc(waysrgt[x][y][z],waysrgt[1-x][y+1][z+2]);
		}
		if(rem>=4&&rem%2==0&&y+rem/2-1<w&&matchrgt[x][y][z]>=rem/2&&matchlft[1-x][y+rem/2-1][z+rem/2]>=rem/2) inc(waysrgt[x][y][z],1);
	}
	//REP(z,len) REP(x,2) REP(y,w) if(wayslft[x][y][z]!=0) printf("%d: (%d,%d) lft = %d\n",z,x,y,wayslft[x][y][z]);
	//REP(z,len) REP(x,2) REP(y,w) if(waysrgt[x][y][z]!=0) printf("%d: (%d,%d) rgt = %d\n",z,x,y,waysrgt[x][y][z]);

	int ret=0;
	REP(x,2) REP(y,w) {
		if(g[x][y]!=s[0]) continue;
		if(len==1) { inc(ret,1); continue; }
		if(y!=0) inc(ret,wayslft[x][y-1][1]);
		FORE(i,2,y+1) if(len>=2*i&&matchlft[x][y][0]>=i&&matchrgt[1-x][y-i+1][i]>=i) inc(ret,len==2*i?1:y==w-1?0:waysrgt[1-x][y+1][2*i]);
		if(y!=w-1) inc(ret,waysrgt[x][y+1][1]);
		FORE(i,2,w-y+1) if(len>=2*i&&matchrgt[x][y][0]>=i&&matchlft[1-x][y+i-1][i]>=i) inc(ret,len==2*i?1:y==0?0:wayslft[1-x][y-1][2*i]);
		if(g[1-x][y]!=s[1]) continue;
		if(len==2) { inc(ret,1); continue; }
		if(y!=0) inc(ret,wayslft[1-x][y-1][2]);
		if(y!=w-1) inc(ret,waysrgt[1-x][y+1][2]);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
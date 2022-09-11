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

const int MAXH=50;
const int MAXW=50;

int a,b,c,d;

int h,w;
char g[MAXH][MAXW+1];

void run() {
	scanf("%d%d%d%d",&a,&b,&c,&d);

	--a,--c;
	w=MAXW;
	int eachblock=w/2;
	int topblocks=(c+d+eachblock-1)/eachblock;
	int botblocks=(a+b+eachblock-1)/eachblock;
	h=topblocks*2+botblocks*2;

	REP(x,h) { REP(y,w) g[x][y]=x<2*topblocks?'A':'C'; g[x][w]='\0'; }
	for(int x=0;x<2*topblocks;x+=2) for(int y=1;y<w;y+=2) if(c>0) g[x][y]='C',--c; else if(d>0) g[x][y]='D',--d;
	for(int x=h-1;x>h-2*botblocks;x-=2) for(int y=1;y<w;y+=2) if(a>0) g[x][y]='A',--a; else if(b>0) g[x][y]='B',--b;
	
	printf("%d %d\n",h,w);
	REP(x,h) printf("%s\n",g[x]);
}

int main() {
	run();
	return 0;
}
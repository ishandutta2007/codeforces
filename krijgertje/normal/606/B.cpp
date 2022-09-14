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

const int MAXH=500;
const int MAXW=500;
const int MAXLEN=100000;

int h,w;
int x,y;
char s[MAXLEN+1]; int slen;
bool been[MAXH][MAXW];
int ret[MAXLEN+1];


void run() {
	scanf("%d%d%d%d%s",&h,&w,&x,&y,s); --x,--y; slen=strlen(s);
	memset(been,false,sizeof(been));
	memset(ret,0,sizeof(ret)); ret[slen]=h*w;
	been[x][y]=true; ret[0]++; ret[slen]--;
	REP(i,slen) {
		int nx=x,ny=y;
		if(s[i]=='L') --ny; else if(s[i]=='R') ++ny; else if(s[i]=='U') --nx; else if(s[i]=='D') ++nx;
		if(0<=nx&&nx<h&&0<=ny&&ny<w) x=nx,y=ny;
		if(!been[x][y]) { been[x][y]=true; ret[i+1]++; ret[slen]--; }
	}
	REPE(i,slen) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");


}

int main() {
	run();
	return 0;
}
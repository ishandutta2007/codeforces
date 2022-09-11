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
#include <chrono>
#include <chrono>
#include <random>
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

int h,w,nchicken;
char g[MAXH][MAXW+1];
char ans[MAXH][MAXW+1];

void solve() {
	int nrice=0; REP(x,h) REP(y,w) if(g[x][y]=='R') ++nrice;
	int each=nrice/nchicken,rem=nrice%nchicken;
	int x=0,y=0,dx=+1;
	REP(x,h) REP(y,w) ans[x][y]='?'; REP(x,h) ans[x][w]='\0';
	REP(i,nchicken) {
		int want=each+(i<rem?1:0);
		int have=0;
		char c=i<26?'A'+i:i<52?'a'+(i-26):'0'+(i-52);
		while(y<w) {
			int cur=g[x][y]=='R'?1:0;
			if(have+cur>want) break;
			ans[x][y]=c;
			have+=cur;
			if(x+dx>=0&&x+dx<h) x+=dx; else ++y,dx=-dx;
		}
		assert(have==want);
	}
	assert(y>=w);
}

void run() {
	scanf("%d%d%d",&h,&w,&nchicken);
	REP(x,h) scanf("%s",g[x]);
	solve();
	REP(x,h) printf("%s\n",ans[x]);
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}
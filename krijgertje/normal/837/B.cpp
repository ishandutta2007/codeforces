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

int h,w;
char g[MAXH][MAXW+1];

bool solve() {
	int sz=h*w; if(sz%3!=0) return false; sz/=3;
	map<char,int> cnt; REP(x,h) REP(y,w) ++cnt[g[x][y]];
	if(cnt['R']!=sz||cnt['B']!=sz||cnt['G']!=sz) return false;
	pair<int,int> shape; bool any=false;
	for(auto it=cnt.begin();it!=cnt.end();++it) {
		int lx=INT_MAX,hx=INT_MIN,ly=INT_MAX,hy=INT_MIN;
		REP(x,h) REP(y,w) if(g[x][y]==it->first) {
			if(x<lx) lx=x; if(x>hx) hx=x; if(y<ly) ly=y; if(y>hy) hy=y;
		}
		int area=(hx-lx+1)*(hy-ly+1); if(area!=it->second) return false;
		if(!any) shape=MP(hx-lx+1,hy-ly+1),any=true; else if(shape!=MP(hx-lx+1,hy-ly+1)) return false;
	}
	return true;
}

void run() {
	scanf("%d%d",&h,&w); REP(x,h) scanf("%s",g[x]);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}
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
const int MAXN=100;
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

int h,w;
char g[MAXH][MAXW+1];
char s[MAXN+1]; int n;


void run() {
	scanf("%d%d",&h,&w); REP(x,h) scanf("%s",g[x]); scanf("%s",s); n=strlen(s);
	int sx=-1,sy=-1; REP(x,h) REP(y,w) if(g[x][y]=='S') sx=x,sy=y;
	vector<int> p(4); REP(i,4) p[i]=i; int ret=0;
	do {
		int x=sx,y=sy; bool crash=false,exit=false;
		REP(i,n) {
			int k=p[s[i]-'0'];
			int nx=x+DX[k],ny=y+DY[k]; if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]=='#') { crash=true; break; }
			x=nx,y=ny;
			if(g[x][y]=='E') { exit=true; break; }
		}
		if(exit) ++ret;
	} while(next_permutation(p.begin(),p.end()));
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
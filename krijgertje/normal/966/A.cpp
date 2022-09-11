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

const int MAXN=100000;

int h,w,na,nb,v;
int ay[MAXN];
int by[MAXN];

int calc(int dx,int ly,int hy,int my,int v) {
	return abs(ly-my)+abs(my-hy)+(dx+v-1)/v;
}

int solve(int dx,int ly,int hy,int *py,int n,int v) {
	int idx=lower_bound(py,py+n,ly)-py;
	int ret=INT_MAX;
	if(idx<n) ret=min(ret,calc(dx,ly,hy,py[idx],v));
	if(idx-1>=0) ret=min(ret,calc(dx,ly,hy,py[idx-1],v));
	return ret;
}

void run() {
	scanf("%d%d%d%d%d",&h,&w,&na,&nb,&v); REP(i,na) scanf("%d",&ay[i]); REP(i,nb) scanf("%d",&by[i]);
	
	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		int sx,sy,tx,ty; scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
		int dx=abs(sx-tx),ly=min(sy,ty),hy=max(sy,ty);
		int ans=min(solve(dx,ly,hy,ay,na,1),solve(dx,ly,hy,by,nb,v));
		if(dx==0) ans=min(ans,abs(sy-ty));
		printf("%d\n",ans);
	}
}

int main() {
	run();
	return 0;
}
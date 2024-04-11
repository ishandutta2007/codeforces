#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=132674;

int n;
int lx[MAXN],ly[MAXN],hx[MAXN],hy[MAXN];

int preflx[MAXN],prefly[MAXN],prefhx[MAXN],prefhy[MAXN]; // pref??[i] is extremum for all rectangles < i
int sufflx[MAXN],suffly[MAXN],suffhx[MAXN],suffhy[MAXN]; // suff??[i] is extremum for all rectangles > i


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d%d%d",&lx[i],&ly[i],&hx[i],&hy[i]);

	preflx[0]=INT_MIN,prefly[0]=INT_MIN,prefhx[0]=INT_MAX,prefhy[0]=INT_MAX;
	REP(i,n-1) preflx[i+1]=max(preflx[i],lx[i]),prefly[i+1]=max(prefly[i],ly[i]),prefhx[i+1]=min(prefhx[i],hx[i]),prefhy[i+1]=min(prefhy[i],hy[i]);
	sufflx[n-1]=INT_MIN,suffly[n-1]=INT_MIN,suffhx[n-1]=INT_MAX,suffhy[n-1]=INT_MAX;
	for(int i=n-1;i>=1;--i) sufflx[i-1]=max(sufflx[i],lx[i]),suffly[i-1]=max(suffly[i],ly[i]),suffhx[i-1]=min(suffhx[i],hx[i]),suffhy[i-1]=min(suffhy[i],hy[i]);

	REP(i,n) {
		int clx=max(preflx[i],sufflx[i]),cly=max(prefly[i],suffly[i]),chx=min(prefhx[i],suffhx[i]),chy=min(prefhy[i],suffhy[i]);
		if(clx<=chx&&cly<=chy) { printf("%d %d\n",clx,cly); return; }
	}
	assert(false);
}

int main() {
	run();
	return 0;
}
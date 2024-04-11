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

const int MAXSIDE=173;

int d[3][2];

char ret[MAXSIDE][MAXSIDE];

void run() {
	REP(i,3) scanf("%d%d",&d[i][0],&d[i][1]);
	int area=0; REP(i,3) area+=d[i][0]*d[i][1];
	int side=0; while(side*side<area) ++side; if(side*side!=area) { printf("-1\n"); return; }
	
	bool stripes=true; REP(i,3) if(d[i][0]!=side&&d[i][1]!=side) stripes=false;
	if(stripes) {
		int at=0;
		REP(i,3) REP(j,2) if(d[i][j]==side) { REP(h,d[i][1-j]) REP(w,d[i][j]) ret[at+h][w]='A'+i; at+=d[i][1-j]; break; }
		printf("%d\n",side); REP(i,side) { REP(j,side) printf("%c",ret[i][j]); puts(""); }
		return;
	}
	REP(i,3) REP(j,2) if(d[i][j]==side) {
		bool ok=true;
		REP(k,3) if(k!=i&&d[k][0]!=side-d[i][1-j]&&d[k][1]!=side-d[i][1-j]) ok=false;
		if(!ok) continue;
		REP(h,d[i][1-j]) REP(w,d[i][j]) ret[h][w]='A'+i;
		int at=0;
		REP(k,3) REP(l,2) if(k!=i&&d[k][l]==side-d[i][1-j]) { REP(h,d[k][l]) REP(w,d[k][1-l]) ret[d[i][1-j]+h][at+w]='A'+k; at+=d[k][1-l]; break; }
		printf("%d\n",side); REP(i,side) { REP(j,side) printf("%c",ret[i][j]); puts(""); }
		return;
	}
	printf("-1\n");
}

int main() {
	run();
	return 0;
}
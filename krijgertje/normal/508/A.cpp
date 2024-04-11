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

int nrow,ncol,nmove;
bool black[1000][1000];

void run() {
	scanf("%d%d%d",&nrow,&ncol,&nmove);
	memset(black,false,sizeof(black));
	int ret=0;
	FORE(i,1,nmove) {
		int r,c; scanf("%d%d",&r,&c); --r,--c;
		black[r][c]=true;
		if(ret==0) {
			if(r+1<nrow&&c+1<ncol&&	black[r][c]&&black[r][c+1]&&black[r+1][c]&&black[r+1][c+1]) ret=i;
			if(r+1<nrow&&c-1>=0&&	black[r][c-1]&&black[r][c]&&black[r+1][c-1]&&black[r+1][c]) ret=i;
			if(r-1>=0&&c+1<ncol&&	black[r-1][c]&&black[r-1][c+1]&&black[r][c]&&black[r][c+1]) ret=i;
			if(r-1>=0&&c-1>=0&&		black[r-1][c-1]&&black[r-1][c]&&black[r][c-1]&&black[r][c]) ret=i;
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
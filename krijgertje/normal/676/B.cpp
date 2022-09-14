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

const int MAXN=10;

int n,t;
int have[MAXN][MAXN];

void run() {
	scanf("%d%d",&n,&t);
	memset(have,0,sizeof(have));
	int cap=1<<n,ret=0;
	have[0][0]=cap*t;
	REP(i,n) REPE(j,i) if(have[i][j]>=cap) {
		assert((have[i][j]-cap)%2==0);
		if(i+1<n) have[i+1][j]+=(have[i][j]-cap)/2,have[i+1][j+1]+=(have[i][j]-cap)/2;
		have[i][j]=cap;
		++ret;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
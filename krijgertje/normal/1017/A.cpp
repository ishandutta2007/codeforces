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

const int MAXN=1000;

int n;
int score[MAXN][4];

pair<int,int> o[MAXN];

void run() {
	scanf("%d",&n);
	REP(i,n) REP(j,4) scanf("%d",&score[i][j]);

	REP(i,n) { int sum=0; REP(j,4) sum+=score[i][j]; o[i]=MP(-sum,i); }
	sort(o,o+n);
	int idx=-1; REP(i,n) if(o[i].second==0) idx=i;
	printf("%d\n",idx+1);
}

int main() {
	run();
	return 0;
}
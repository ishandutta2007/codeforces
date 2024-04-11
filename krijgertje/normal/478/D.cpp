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

const int MOD=1000000007;

int r,g;
int ways[2][200001];

void run() {
	scanf("%d%d",&r,&g);

	int at=0,h=0,need=0; ways[at][0]=1;
	while(true) {
		int nat=1-at,nh=h+1,nneed=need+nh,lim=min(r,nneed);
		REPE(i,lim) {
			ways[nat][i]=ways[at][i];
			if(i>=nh) { ways[nat][i]+=ways[at][i-nh]; if(ways[nat][i]>=MOD) ways[nat][i]-=MOD; }
		}
		bool ok=false; REPE(i,lim) if(ways[nat][i]!=0&&nneed-i<=g) ok=true; if(!ok) break;
		at=nat,h=nh,need=nneed;
	}
	{
		int ret=0,lim=min(r,need);
		REPE(i,lim) if(ways[at][i]!=0&&need-i<=g) { ret+=ways[at][i]; if(ret>=MOD) ret-=MOD; }
		printf("%d\n",ret);
	}
}

int main() {
	run();
	return 0;
}
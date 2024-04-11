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

const int MAXN=200000;

int n,me;
int have[MAXN];
int gain[MAXN];

void run() {
	scanf("%d%d",&n,&me); --me;
	REP(i,n) scanf("%d",&have[i]);
	REP(i,n) scanf("%d",&gain[i]);

	int meafter=have[me]+gain[0];
	int ans=1,at=1;
	for(int i=me-1;i>=0;--i) {
		while(at<n&&have[i]+gain[at]>meafter) ++at;
		if(at>=n) ++ans; else ++at;
	}
	printf("%d\n",ans);
}

int main() {
	run();
	return 0;
}
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

int n,cap;
int a[MAXN];

int ans[MAXN];

void run() {
	scanf("%d%d",&n,&cap);
	REP(i,n) scanf("%d",&a[i]);

	int rem=cap;
	REP(i,n) {
		ans[i]=0;
		int left=a[i];
		while(left>0) {
			if(rem==cap&&left>=cap) {
				int full=left/cap;
				left-=full*cap;
				ans[i]+=full;
			} else {
				int cur=min(rem,left);
				rem-=cur; left-=cur;
				if(rem==0) ++ans[i],rem=cap;
			}
		}
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}
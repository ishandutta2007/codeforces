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
#include <bitset>
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

const int MAXANS=40;

int have;
int ans[MAXANS],nans;

void solve() {
	nans=0; int cur=have;
	while(true) {
		//if(nans>=MAXANS) { printf("err\n"); break; }
		int bit=cur&-cur;
		int idx=0; while((1<<idx)<bit) ++idx; assert((1<<idx)==bit);
		//printf("bit=%d cur=%d\n",bit,cur);
		if(cur==bit) {
			ans[nans++]=idx;
			cur+=bit-1;
			break;
		} else {
			ans[nans++]=idx;
			ans[nans++]=-1;
			cur+=bit;
		}
	}
}

void run() {
	scanf("%d",&have);
	solve();
	printf("%d\n",nans);
	REP(i,nans) if(i%2==0) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}
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

const int MAXN=300000;

int n;
int p[MAXN];
int nans;
int ans[5*MAXN][2];

int pos[MAXN];

void op(int x,int y) {
	assert(abs(x-y)>=n/2);
	swap(p[x],p[y]);
	swap(pos[p[x]],pos[p[y]]);
	ans[nans][0]=x,ans[nans][1]=y,++nans;
}

void solve() {
	nans=0;
	REP(i,n) pos[p[i]]=i;
	FORE(i,1,n-2) {
		int at=pos[i];
		if(at==i) continue;
		int x=i<n/2?n-1:0;
		int y=n-1-x;
		if(abs(at-i)>=n/2) {
			op(at,i);
		} else if(abs(at-x)>=n/2) {
			op(at,x);
			op(x,i);
		} else {
			assert(abs(at-y)>=n/2);
			op(at,y);
			op(y,x);
			op(x,i);
		}
	}
	if(p[0]!=0) op(0,n-1);
	REP(i,n) assert(p[i]==i);
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&p[i]),--p[i];
	solve();
	printf("%d\n",nans);
	REP(i,nans) printf("%d %d\n",ans[i][0]+1,ans[i][1]+1);
}

int main() {
	run();
	return 0;
}
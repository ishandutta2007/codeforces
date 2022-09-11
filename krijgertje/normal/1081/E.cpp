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

const int MAXN=100000;

int n;
int x[MAXN];
ll ans[MAXN];

ll sq[MAXN];

bool solve() {
	for(int i=n-1;i>=0;i-=2) {
		for(int b=1;;++b) {
			//printf("testing %d for %d\n",b,x[i]);
			if(b*b>=x[i]) return false;
			if((x[i]-b*b)%(2*b)!=0) continue;
			int a=(x[i]-b*b)/(2*b);
			if(i!=n-1&&a+b>=sq[i+1]) continue;
			sq[i]=a+b; sq[i-1]=a;
			//printf("sq[%d]=%d sq[%d]=%d\n",i,a+b,i-1,a);
			break;
		}
	}
	REP(i,n) ans[i]=sq[i]*sq[i]-(i==0?0:sq[i-1]*sq[i-1]);
	return true;
}


void run() {
	scanf("%d",&n);
	REP(i,n) if(i%2==0) x[i]=-1; else scanf("%d",&x[i]);
	if(!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%lld",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}
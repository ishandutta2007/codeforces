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

const int MAXN=10000;

int n,nq;
int mark[MAXN],curmark,mask[MAXN];

void run() {
	scanf("%d%d",&n,&nq);
	memset(mark,-1,sizeof(mark)); curmark=-1;
	REP(i,nq) {
		int cnt; scanf("%d",&cnt); ++curmark; bool ok=false;
		REP(j,cnt) {
			int x; scanf("%d",&x);
			int cmask=0; if(x<0) cmask|=1; if(x>0) cmask|=2;
			x=abs(x)-1;
			if(mark[x]!=curmark) mark[x]=curmark,mask[x]=0;
			mask[x]|=cmask; if(mask[x]==3) ok=true;
		}
		if(!ok) { printf("YES\n"); return; }
	}
	printf("NO\n");
}

int main() {
	run();
	return 0;
}
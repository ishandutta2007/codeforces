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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=1000000;

int n;
int bst[MAXN+1];
int prv[MAXN+1];

void run() {
	scanf("%d",&n);
	REPE(i,n) bst[i]=-1; bst[0]=0; prv[0]=-1;
	FOR(mask,1,1<<7) {
		int nr=0; for(int i=0,now=1;i<7;++i,now*=10) if(mask&(1<<i)) nr+=now;
		FORE(i,nr,n) if(bst[i-nr]!=-1&&(bst[i]==-1||bst[i-nr]+1<bst[i])) bst[i]=bst[i-nr]+1,prv[i]=i-nr;
	}
	printf("%d\n",bst[n]);
	bool first=true; for(int x=n;x!=0;x=prv[x]) { if(first) first=false; else printf(" "); printf("%d",x-prv[x]); } puts("");

}

int main() {
	run();
	return 0;
}
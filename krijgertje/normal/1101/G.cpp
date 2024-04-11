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

const int MAXN=200000;

int n;
int a[MAXN];

int b[MAXN];

int solve() {
	int sum=0; REP(i,n) sum^=a[i]; if(sum==0) return -1;

	REP(i,n) b[i]=a[i];
	int nhave=0;
	REP(bit,30) {
		bool found=false; FOR(i,nhave,n) if((b[i]&(1<<bit))!=0) { swap(b[i],b[nhave]); found=true; break; } if(!found) continue;
		FOR(i,nhave+1,n) if((b[i]&(1<<bit))!=0) b[i]^=b[nhave];
		++nhave;
	}
	return nhave;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
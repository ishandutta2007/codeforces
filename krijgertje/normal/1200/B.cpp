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

const int MAXN=100;

int n,shave,lim;
int a[MAXN];

bool solve() {
	int have=shave,at=0;
	while(at+1<n) {
		int need=max(0,a[at+1]-lim);
		if(a[at]>need) {
			have+=a[at]-need;
			++at;
		} else if(a[at]+have>=need) {
			have-=need-a[at];
			++at;
		} else {
			return false;
		}
	}
	return true;
}

void run() {
	scanf("%d%d%d",&n,&shave,&lim);
	REP(i,n) scanf("%d",&a[i]);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}
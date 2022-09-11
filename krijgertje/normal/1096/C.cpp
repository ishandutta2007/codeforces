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

int ang;

int solve() {
	for(int n=3;;++n) {
		int num=n*ang,den=180; if(num%den!=0) continue;
		int x=num/den; if(x>=n-1) continue;
		//printf("n=%d ang=%d => x=%d\n",n,ang,x);
		return n;
	}
}

void run() {
	scanf("%d",&ang);
	printf("%d\n",solve());
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	//for(ang=1;ang<=179;++ang) { printf("%d:",ang); printf("%d\n",solve()); }
	return 0;
}
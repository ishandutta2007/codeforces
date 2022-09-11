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

int n,k;


bool solve() {
	/*vector<bool> win(80); REPSZ(i,win) { win[i]=false; if(i-1>=0&&!win[i-1]) win[i]=true; if(i-2>=0&&!win[i-2]) win[i]=true; if(i-k>=0&&!win[i-k]) win[i]=true; }
	printf("win: "); REPSZ(i,win) printf("%c",win[i]?'W':'-'); puts("");*/

	if(k%3!=0) return n%3!=0;
	
	int nblock=k/3;
	int period=3*nblock+1;
	int idx=n%period;
	return idx%3!=0||idx==period-1;
}

void run() {
	scanf("%d%d",&n,&k);
	printf("%s\n",solve()?"Alice":"Bob");
	
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}
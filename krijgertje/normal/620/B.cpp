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

int cnt[10]={6,2,5,5,4,5,6,3,7,6};
int cum[10];

int calc(int x) { // #segments of numbers [1..x]
	if(x<10) return cum[x]-cnt[0];
	int d=x%10; x/=10;
	int pre=0; for(int y=x;y>0;y/=10) pre+=cnt[y%10];
	return (d+1)*pre+cum[d]+10*calc(x-1)+cum[9]*x-cnt[0];
}

void run() {
	int a,b; scanf("%d%d",&a,&b); int ret=calc(b)-calc(a-1); printf("%d\n",ret);
}

int main() {
	cum[0]=cnt[0]; FOR(i,1,10) cum[i]=cnt[i]+cum[i-1];
	run();
	return 0;
}
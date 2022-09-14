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

int n,have;

int cnt[10];


void run() {
	scanf("%d%d",&n,&have);
	REP(i,10) cnt[i]=0;

	int ret=0;
	REP(i,n) {
		int a; scanf("%d",&a);
		++cnt[a%10]; ret+=a/10;
	}
	for(int i=9;i>=1;--i) { int cur=min(cnt[i],have/(10-i)); cnt[i]-=cur; have-=cur*(10-i); cnt[0]+=cur; ret+=cur; }
	ret+=have/10; if(ret>n*10) ret=n*10;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
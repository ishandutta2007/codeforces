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

const int MAXN=100;

int n;
int a[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	sort(a+1,a+n);
	int opp=a[n-1],cnt=1,ret=0;
	while(opp>=a[0]) {
		while(cnt<n-1&&a[n-cnt-1]==opp) ++cnt;
		//printf("at=%d opp=%d cnt=%d (ret=%d)\n",a[0],opp,cnt,ret);
		if(cnt>=opp-a[0]+1) { ret+=opp-a[0]+1; break; }
		a[0]+=cnt; ret+=cnt; --opp;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
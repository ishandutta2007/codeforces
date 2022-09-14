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

int n,can;
int a[100];

int ans[1000][2],nans;

void run() {
	scanf("%d%d",&n,&can);
	REP(i,n) scanf("%d",&a[i]);

	nans=0;
	while(nans<can) {
		int l=0,h=0;
		REP(i,n) if(a[i]<a[l]) l=i;
		REP(i,n) if(a[i]>a[h]) h=i;
		if(a[h]-a[l]<=1) break;
		a[l]++; a[h]--; ans[nans][0]=h; ans[nans][1]=l; nans++;
	}
	int ret;
	{
		int l=0,h=0;
		REP(i,n) if(a[i]<a[l]) l=i;
		REP(i,n) if(a[i]>a[h]) h=i;
		ret=a[h]-a[l];
	}
	printf("%d %d\n",ret,nans);
	REP(i,nans) printf("%d %d\n",ans[i][0]+1,ans[i][1]+1);
}

int main() {
	run();
	return 0;
}
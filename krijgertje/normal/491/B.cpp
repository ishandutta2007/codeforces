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

int h,w;
int nh,nr;
int hx[100000],hy[100000];
int rx[100000],ry[100000];

void run() {
	scanf("%d%d",&h,&w);
	scanf("%d",&nh); REP(i,nh) scanf("%d%d",&hx[i],&hy[i]);
	scanf("%d",&nr); REP(i,nr) scanf("%d%d",&rx[i],&ry[i]);
	int minsum=INT_MAX,maxsum=INT_MIN,mindiff=INT_MAX,maxdiff=INT_MIN;
	REP(i,nh) {
		int sum=hx[i]+hy[i],diff=hx[i]-hy[i];
		if(sum<minsum) minsum=sum; if(sum>maxsum) maxsum=sum; if(diff<mindiff) mindiff=diff; if(diff>maxdiff) maxdiff=diff;
	}
	int retdist=INT_MAX,retr=-1;
	REP(i,nr) {
		int sum=rx[i]+ry[i],diff=rx[i]-ry[i];
		int dist=max(max(abs(sum-minsum),abs(sum-maxsum)),max(abs(diff-mindiff),abs(diff-maxdiff)));
		if(dist<retdist) retdist=dist,retr=i;
	}
	printf("%d\n%d\n",retdist,retr+1);
}

int main() {
	run();
	return 0;
}
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

int n,maxdiff,minlen;
int x[100000];

int minprev[100000]; // minprev[i]=min(j | j..i such that max(x[k],j<=k<=i)-min(x[k],j<=k<=i)<=maxdiff)
int f[100001]; // f[i]=1+min(f[j],minprev[i]<=j<=i-minlen)

int mx[100000],mxhead,mxtail;
int mn[100000],mnhead,mntail;

int q[100000],qhead,qtail;

void run() {
	scanf("%d%d%d",&n,&maxdiff,&minlen);
	REP(i,n) scanf("%d",&x[i]);
	
	mxhead=mxtail=mnhead=mntail=0;
	minprev[0]=0; mx[mxhead++]=0; mn[mnhead++]=0;
	FOR(i,1,n) {
		minprev[i]=minprev[i-1];
		while(mxtail<mxhead&&x[i]>=x[mx[mxhead-1]]) --mxhead; mx[mxhead++]=i;
		while(mntail<mnhead&&x[i]<=x[mn[mnhead-1]]) --mnhead; mn[mnhead++]=i;
		while(x[mx[mxtail]]>x[i]+maxdiff) { if(mx[mxtail]>=minprev[i]) minprev[i]=mx[mxtail]+1; ++mxtail; }
		while(x[mn[mntail]]<x[i]-maxdiff) { if(mn[mntail]>=minprev[i]) minprev[i]=mn[mntail]+1; ++mntail; }
//		printf("\t%d\n",i);
//		printf("\tmx:"); FOR(j,mxtail,mxhead) printf(" %d",mx[j]); puts("");
//		printf("\tmn:"); FOR(j,mntail,mnhead) printf(" %d",mn[j]); puts("");
	}

	qhead=qtail=0; f[0]=0;
	FORE(i,1,n) {
		if(i-minlen>=0&&f[i-minlen]!=INT_MAX) {
			while(qtail<qhead&&f[q[qhead-1]]>=f[i-minlen]) --qhead; q[qhead++]=i-minlen;
		}
		while(qtail<qhead&&q[qtail]<minprev[i-1]) ++qtail;
//		printf("\t%d\n",i-1);
//		printf("\tq:"); FOR(j,qtail,qhead) printf(" %d",q[j]); puts("");
		f[i]=qtail<qhead?f[q[qtail]]+1:INT_MAX;
	}
//	REP(i,n) printf("%d: minprev=%d, f=%d\n",i,minprev[i],f[i+1]);
	int ret=f[n]; printf("%d\n",ret==INT_MAX?-1:ret);
}

int main() {
	run();
	return 0;
}
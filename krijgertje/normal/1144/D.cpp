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
int anskind[MAXN],ansx[MAXN],ansy[MAXN],nans;

int b[MAXN];

void process(int i,int j) {
	//printf("process(%d,%d) [%d->%d]\n",i,j,b[i],b[j]);
	assert(b[i]!=b[j]);
	anskind[nans]=b[i]<b[j]?1:2,ansx[nans]=i,ansy[nans]=j,++nans;
	b[i]=b[j];
}

void solve() {
	REP(i,n) b[i]=a[i];
	sort(b,b+n);
	int mxval=-1,mxcnt=0;
	for(int l=0,r=l;l<n;l=r) { while(r<n&&b[l]==b[r]) ++r; int cnt=r-l,val=b[l]; if(cnt>mxcnt) mxcnt=cnt,mxval=val; }
	//printf("mxval=%d mxcnt=%d\n",mxval,mxcnt);

	nans=0; REP(i,n) b[i]=a[i];
	REP(i,n) if(b[i]==mxval) {
		for(int j=i-1;j>=0;--j) if(b[j]!=mxval) process(j,j+1); else break;
		if(i+1<n&&b[i+1]!=mxval) process(i+1,i);
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	solve();
	printf("%d\n",nans);
	REP(i,nans) printf("%d %d %d\n",anskind[i],ansx[i]+1,ansy[i]+1);
}

int main() {
	run();
	return 0;
}
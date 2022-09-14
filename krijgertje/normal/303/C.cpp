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

int n,k;
int a[5000];

int ndiff;
int cntdiff[1000001];
int firstdiff[1000001];
int nextdiff[12497500];
int diff1[12497500];
int diff2[12497500];
int mark[1000001];
int parent[1000001];
int rnk[1000001];
int find(int x) { if(parent[x]==x) return x; return parent[x]=find(parent[x]); }

void run(int casenr) {
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d",&a[i]);
	sort(a,a+n);
	
	memset(firstdiff,-1,sizeof(firstdiff)); ndiff=0;
	REP(i,n) FOR(j,i+1,n) {
		int x=a[j]-a[i];
		diff1[ndiff]=i; diff2[ndiff]=j; nextdiff[ndiff]=firstdiff[x]; firstdiff[x]=ndiff++; ++cntdiff[x];
	}
	
	for(int ret=1;;++ret) {
		int sum=0;
		for(int i=ret;i<=1000000;i+=ret) { sum+=cntdiff[i]; if(sum>k*(k+1)/2) break; }
		if(sum>k*(k+1)/2) continue;
		
		int nitems=0,nsets=0;
		for(int i=ret;i<=1000000;i+=ret) for(int x=firstdiff[i];x!=-1;x=nextdiff[x]) {
			int a=diff1[x],b=diff2[x];
			if(mark[a]!=ret) { ++nitems,++nsets; mark[a]=ret; parent[a]=a; rnk[a]=0; }
			if(mark[b]!=ret) { ++nitems,++nsets; mark[b]=ret; parent[b]=b; rnk[b]=0; }
			a=find(a); b=find(b); if(a==b) continue;
			if(rnk[a]<rnk[b]) swap(a,b);
			parent[b]=a; --nsets; if(rnk[a]==rnk[b]) ++rnk[a];
		}
		if(nitems-nsets>k) continue;
		
		printf("%d\n",ret); return;		
	}
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
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

int n,maxswap;
int a[200];
int p[200];
bool pcmp(const int &x,const int &y) { if(a[x]!=a[y]) return a[x]>a[y]; return x<y; }

int smallest[10],nsmallest;
int fst,prv[200],nxt[200],lst;

void rem(int i) {
	if(prv[i]==-1) fst=nxt[i]; else nxt[prv[i]]=nxt[i];
	if(nxt[i]==-1) lst=prv[i]; else prv[nxt[i]]=prv[i];
}

void add(int i) {
	REP(j,nsmallest) if(a[i]<smallest[j]) {
		if(nsmallest==maxswap) --nsmallest;
		for(int k=nsmallest-1;k>=j;--k) smallest[k+1]=smallest[k]; smallest[j]=a[i]; ++nsmallest;
		return;
	}
	if(nsmallest<maxswap) smallest[nsmallest++]=a[i];
}

void run() {
	scanf("%d%d",&n,&maxswap);
	REP(i,n) scanf("%d",&a[i]);

	REP(i,n) p[i]=i; sort(p,p+n,pcmp);

	int ret=a[0];
	REP(first,n) {
		fst=p[0]; lst=p[n-1];
		REP(i,n) prv[p[i]]=i==0?-1:p[i-1];
		REP(i,n) nxt[p[i]]=i==n-1?-1:p[i+1];
		nsmallest=0;
		int sum=0;
		FOR(last,first,n) {
			sum+=a[last];
			rem(last); add(last);
			int cur=sum;
			for(int i=0,j=fst;i<maxswap&&i<nsmallest&&j!=-1&&smallest[i]<a[j];++i,j=nxt[j]) cur+=a[j]-smallest[i];
			if(cur>ret) ret=cur;
			//printf("%d..%d -> %d\n",first,last,cur);
			//printf("\t"); REP(k,nsmallest) printf("%d ",smallest[k]); puts("");
			//printf("\t"); for(int k=fst;k!=-1;k=nxt[k]) printf("%d ",a[k]); puts("");
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
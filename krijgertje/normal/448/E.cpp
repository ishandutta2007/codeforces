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

const int maxneed=100000;

int have;
void print(ll x) { if(have!=0) printf(" "); printf("%I64d",x); ++have; }


ll divs[1000001]; int ndivs;

int start[1000001];
int len[1000001];
int vals[10000001];


void go(int at,int k) {
	if(k==0) { print(divs[at]); return; }
	if(divs[at]==1) { print(1); return; }
	REP(j,len[at]) {
		go(vals[start[at]+j],k-1);
		if(have>=maxneed) return;
	}
}



ll X,k;

void run() {
	cin>>X>>k;
	have=0;
	if(X==1) { print(1); cout<<endl; return; }
	if(k>=maxneed) { REP(i,maxneed) print(1); cout<<endl; return; }

	ndivs=0; for(int i=1;(ll)i*i<=X;++i) if(X%i==0) divs[ndivs++]=i;
	for(int i=divs[ndivs-1]*divs[ndivs-1]==X?ndivs-2:ndivs-1;i>=0;--i) divs[ndivs++]=X/divs[i];
	//REP(i,ndivs) printf("%lld\n",divs[i]);

	REP(i,ndivs) {
		start[i]=i==0?0:start[i-1]+len[i-1]; len[i]=0;
		REPE(j,i) if(divs[i]%divs[j]==0) { vals[start[i]+len[i]]=j; ++len[i]; }
	}
	//fprintf(stderr,"%lld\n",start[ndivs-1]+len[ndivs-1]);

	go(ndivs-1,(int)k);	cout<<endl;
}

int main() {
	run();
	return 0;
}
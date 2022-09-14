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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

void print(int a,int na,int b,int nb) {
	if(nb>na) { int cur=b/nb; REP(i,cur) printf("x"); b-=cur; --nb; }
	while(na>0) {
		{ int cur=a-na+1; REP(i,cur) printf("o"); a-=cur; --na; }
		if(nb>0) { int cur=b/nb; REP(i,cur) printf("x"); b-=cur; --nb; }
	}
}

void run() {
	int a,b; scanf("%d%d",&a,&b);
	ll ret=LLONG_MIN; int retna=-1,retnb=-1;
	FORE(na,a==0?0:1,min(a,b+1)) FORE(nb,max(na-1,b==0?0:1),min(b,na+1)) {
		ll cur=0,maxa=-1,maxb=-1,minb=-1;
		if(na>0) {
			maxa=a-na+1;
			cur+=(na-1)*(1)+(1)*(maxa*maxa);
		}
		if(nb>0) {
			minb=b/nb,maxb=minb+1;
			cur-=(b%nb)*(maxb*maxb)+(nb-b%nb)*(minb*minb);
		}
//		printf("\t%d %d -> %lld (%lld,%lld,%lld)\n",na,nb,cur,maxa,maxb,minb);
		if(cur>ret) { ret=cur; retna=na; retnb=nb; }
	}
	cout<<ret<<endl;
	print(a,retna,b,retnb);
}

int main() {
	run();
	return 0;
}
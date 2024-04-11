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

void move(int *x,int i,int j,int &nret,int ret[1000000][2]) {
	ret[nret][0]=i,ret[nret][1]=j,++nret,x[i]^=x[j];
}

void swap(int *x,int i,int j,int &nret,int ret[1000000][2]) {
	move(x,i,j,nret,ret); move(x,j,i,nret,ret); move(x,i,j,nret,ret);
}

void gaussjord(int n,int *x,int &nret,int ret[1000000][2]) {
	REP(i,n) {
		{
			int best=i; FOR(j,i+1,n) if(x[j]>x[best]) best=j;
			if(best!=i) swap(x,i,best,nret,ret);
		}
		FOR(j,i+1,n) if((x[i]^x[j])<x[j]) move(x,j,i,nret,ret);
	}
	for(int i=n-1;i>=0;--i) if(x[i]!=0) {
		REP(j,i) if((x[i]^x[j])<x[j]) move(x,j,i,nret,ret);
	}
}

int n;
int s[10000];
int t[10000];

int ret1[1000000][2],nret1;
int ret2[1000000][2],nret2;
int ret[1000000][2],nret;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&s[i]); REP(i,n) scanf("%d",&t[i]);
	nret1=nret2=0;
	gaussjord(n,s,nret1,ret1);
	gaussjord(n,t,nret2,ret2);
	REP(i,n) {
		FOR(j,i,n) {
			if(s[j]==0) break;
			bool have=(s[i]^s[j])<s[i];
			bool want=(t[i]^s[j])<t[i];
			if(have!=want) move(s,i,j,nret1,ret1);
		}
	}
	//REP(i,n) printf("%x %x\n",s[i],t[i]);
	REP(i,n) if(s[i]!=t[i]) { printf("-1\n"); return; }
	printf("%d\n",nret1+nret2); REP(i,nret1) printf("%d %d\n",ret1[i][0]+1,ret1[i][1]+1); for(int i=nret2-1;i>=0;--i) printf("%d %d\n",ret2[i][0]+1,ret2[i][1]+1);
}

int main() {
	run();
	return 0;
}
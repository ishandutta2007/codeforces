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

int n,x,y;
int a[100000];

int z[2000000],nz;

void run() {
	scanf("%d%d%d",&n,&x,&y);
	{ int g=gcd(x,y); if(g!=1) x/=g,y/=g; }
	REP(i,n) scanf("%d",&a[i]); REP(i,n) a[i]%=(x+y);
	REP(i,n) if(a[i]==0) a[i]=x+y;
	{
		nz=0; ll lx=0,ly=0;
		REP(i,x+y-2) {
			assert(lx+y!=ly+x);
			if(lx+y<ly+x) {
				z[nz++]=0; lx+=y;
			} else {
				z[nz++]=1; ly+=x;
			}
		}
		assert(lx+y==ly+x);
		//printf("%lld %lld\n",lx,ly); REP(i,nz) printf("%d",z[i]); puts("");
	}

	REP(i,n) {
		if(a[i]==x+y||a[i]==x+y-1) { printf("Both\n"); continue; }
		int ret=z[a[i]-1]; //printf("\t%d -> %d\n",a[i],ret);
		printf("%s\n",ret==0?"Vanya":"Vova");
	}
}

int main() {
	run();
	return 0;
}
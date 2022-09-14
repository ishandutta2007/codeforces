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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=4000;

int n;
int vd[MAXN],vh[MAXN],c[MAXN];

int q[MAXN],qhead,qtail;

int ret[MAXN],nret;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d%d",&vd[i],&vh[i],&c[i]);

	qhead=qtail=0;
	REP(i,n) if(c[i]>=0) {
		ret[nret++]=i;
		int leftd=vd[i];
		FOR(j,i+1,n) if(c[j]>=0) {
			c[j]-=leftd; leftd--;
			if(c[j]<0) q[qhead++]=j;
			if(leftd<=0) break;
		}
		while(qtail<qhead) {
			int j=q[qtail++];
			FOR(k,j+1,n) if(c[k]>=0) {
				c[k]-=vh[j];
				if(c[k]<0) q[qhead++]=k;
			}
		}
	}
	printf("%d\n",nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}
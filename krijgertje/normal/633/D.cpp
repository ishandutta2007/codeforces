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

const int MAXN=1000;

int n;
int x[MAXN];
bool used[MAXN];
int cur[MAXN],ncur;
int get(int y) {
	int l=-1,h=n; // (l,h]
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(y>x[m]||y==x[m]&&used[m]) l=m; else h=m;
	}
	return h<n&&y==x[h]?h:-1;
}

void run() {
	// a	b	a+b	a+2b	2a+3b	3a+5b
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]); sort(x,x+n);
	int ret=0; memset(used,false,sizeof(used));
	REP(i,n) if(i==0||x[i]!=x[i-1]) REP(j,n) if((j==0||x[j]!=x[j-1]||j==i+1)&&i!=j) {
		int a=x[i],b=x[j]; ncur=0; cur[ncur++]=i,used[i]=true; cur[ncur++]=j,used[j]=true;
		while(true) {
			int c=a+b,idx=get(c);
			if(idx==-1) break;
			cur[ncur++]=idx,used[idx]=true; a=b; b=c;
		}
		REP(k,ncur) used[cur[k]]=false;
		//printf("%d %d -> %d\n",x[i],x[j],ncur);
		if(ncur>ret) ret=ncur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
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

const int LIM=2000000;
const int MAXN=100000;

int pmin[LIM+1];

bool ok[LIM+1];

int n;
int a[MAXN];
int b[MAXN];

void mark(int x) {
	while(x!=1) {
		int p=pmin[x]; while(pmin[x]==p) x/=p;
		//printf("marking %d\n",p);
		for(int i=p;i<=LIM;i+=p) ok[i]=false;
	}
}

void run() {
	memset(pmin,-1,sizeof(pmin)); FORE(i,2,LIM) if(pmin[i]==-1) for(int j=i;j<=LIM;j+=i) if(pmin[j]==-1) pmin[j]=i;
	//int cnt=0; FORE(i,100001,LIM) if(pmin[i]==i) ++cnt; printf("%d\n",cnt);

	REPE(i,LIM) ok[i]=i>=2;
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	bool havegreater=false; int at=0;
	REP(i,n) {
		if(!havegreater) {
			b[i]=a[i]; while(!ok[b[i]]) ++b[i];
			havegreater=b[i]>a[i];
		} else {
			b[i]=at; while(!ok[b[i]]) ++b[i]; at=b[i];
		}
		mark(b[i]);
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",b[i]); } puts("");
}

int main() {
	run();
	return 0;
}
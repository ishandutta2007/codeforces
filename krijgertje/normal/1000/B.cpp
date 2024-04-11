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

const int MAXN=100000;

int n,len;
int a[MAXN];

int t[MAXN+2];
int onfrom[MAXN+2];


void run() {
	scanf("%d%d",&n,&len); REP(i,n) scanf("%d",&a[i]);

	t[0]=0; REP(i,n) t[i+1]=a[i]; t[n+1]=len;
	onfrom[n+1]=0; for(int i=n;i>=0;--i) onfrom[i]=onfrom[i+1]+(i%2==0?t[i+1]-t[i]:0);
	//printf("t:"); REP(i,n+2) printf(" %d",t[i]); puts("");
	//printf("onfrom:"); REP(i,n+2) printf(" %d",onfrom[i]); puts("");

	int ret=onfrom[0];
	for(int i=1;i+1<n+2;i+=2) if(t[i]+1<t[i+1]) {
		int cur=onfrom[0]-onfrom[i]+t[n+1]-t[i]-onfrom[i]-1;
		//printf("%d: %d\n",t[i]+1,cur);
		ret=max(ret,cur);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
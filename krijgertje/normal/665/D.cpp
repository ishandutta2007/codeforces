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
const int MAXVAL=1000000;
const int MAXSUM=2*MAXVAL;

int n;
int x[MAXN];
bool isprime[MAXSUM+1];

int ret[MAXN],nret;

void run() {
	memset(isprime,true,sizeof(isprime)); isprime[0]=isprime[1]=false;
	FORE(i,2,MAXSUM) if(isprime[i]) for(int j=i+i;j<=MAXSUM;j+=i) isprime[j]=false;

	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);

	ret[0]=x[0],nret=1;
	int n1=0; REP(i,n) if(x[i]==1) ++n1;
	REP(i,n) if(x[i]!=1&&x[i]%2==1) REP(j,n) if(x[j]%2==0) if(isprime[x[i]+x[j]]&&nret<2) nret=2,ret[0]=x[i],ret[1]=x[j];
	if(n1>0) REP(i,n) if(x[i]%2==0) if(isprime[x[i]+1]&&nret<n1+1) { nret=n1+1; REP(k,n1) ret[k]=1; ret[n1]=x[i]; }
	if(nret<n1) { nret=n1; REP(k,n1) ret[k]=1; }

	printf("%d\n",nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}
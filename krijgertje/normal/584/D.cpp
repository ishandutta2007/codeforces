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

const int MAXN=999999999;
const int MAXGAP=1000;

int n;
int z[MAXGAP+1];

bool isprime(int x) {
	if(x==0||x==1) return false;
	for(int i=2;i*i<=x;++i) if(x%i==0) return false;
	return true;
}

void run() {
	memset(z,-1,sizeof(z));
	z[0]=0; for(int i=2;i<=MAXGAP;++i) for(int j=0;j+j<=i;++j) if((j==0||isprime(j))&&isprime(i-j)) { z[i]=j; break; }
	//for(int i=0;i<=MAXGAP;i+=2) if(z[i]==-1) printf("! %d\n",i);

	scanf("%d",&n);
	int x=n;
	while(!isprime(x)) x-=2;

	if(x==n) printf("1\n%d\n",x);
	else if(z[n-x]==0) printf("2\n%d %d\n",x,n-x);
	else printf("3\n%d %d %d\n",x,n-x-z[n-x],z[n-x]);
}

int main() {
	run();
	return 0;
}
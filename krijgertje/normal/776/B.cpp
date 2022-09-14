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

int n;
bool isp[MAXN+2];

void run() {
	scanf("%d",&n);
	REPE(i,n+1) isp[i]=true; isp[0]=isp[1]=false; FORE(i,2,n+1) if(isp[i]) for(int j=i+i;j<=n+1;j+=i) isp[j]=false;
	int ret=n<=2?1:2;
	printf("%d\n",ret);
	FORE(i,2,n+1) { if(i!=2) printf(" "); printf("%d",isp[i]?1:2); } puts("");
}

int main() {
	run();
	return 0;
}
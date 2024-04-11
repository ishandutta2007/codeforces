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
bool isp[MAXN+1];

int ret[MAXN],nret;

void run() {
	scanf("%d",&n);
	FORE(i,1,n) isp[i]=true; isp[0]=isp[1]=false; FORE(i,2,n) if(isp[i]) for(int j=i*i;j<=n;j+=i) isp[j]=false;

	nret=0;
	REPE(i,n) if(isp[i]) { for(int x=i;x<=n;x*=i) ret[nret++]=x; }

	printf("%d\n",nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");

}

int main() {
	run();
	return 0;
}
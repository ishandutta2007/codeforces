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
double p[MAXN][MAXN];
bool done[MAXN];
double num[MAXN],den[MAXN]; // num[i]/(1-den[i])


void run() {
	scanf("%d",&n);
	REP(i,n) REP(j,n) { int cp; scanf("%d",&cp); p[i][j]=0.01*cp; }

	REP(i,n) done[i]=false,num[i]=1,den[i]=1-p[i][n-1]; done[n-1]=true,num[n-1]=0,den[n-1]=0;
	while(true) {
		int at=-1; REP(i,n) if(!done[i]&&den[i]<1&&(at==-1||num[i]/(1-den[i])<num[at]/(1-den[at]))) at=i; if(at==-1) break;
		done[at]=true; REP(i,n) if(!done[i]) num[i]+=p[i][at]*den[i]*num[at]/(1-den[at]),den[i]*=1-p[i][at];
	}
	printf("%.9lf\n",num[0]/(1-den[0]));
}

int main() {
	run();
	return 0;
}
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

const int MAXN=100;

int n;
double p[MAXN];
double pk[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) { int pp; scanf("%d",&pp); p[i]=0.01*pp; }

	double pdone=1; REP(i,n) pdone*=p[i],pk[i]=1-p[i];
	double ret=n;
	for(int cnt=n;cnt<=1000000;++cnt) {
		//if(cnt==1000000) { printf("after %d guesses %lf:",cnt,pdone); REP(i,n) printf(" %lf",1-pk[i]); puts(""); }
		ret+=1-pdone;
		int idx=0; FOR(i,1,n) if((1-pk[i]*(1-p[i]))/(1-pk[i])>(1-pk[idx]*(1-p[idx]))/(1-pk[idx])) idx=i;
		pdone*=(1-pk[idx]*(1-p[idx]))/(1-pk[idx]);
		pk[idx]*=1-p[idx];
	}
	printf("%.9lf\n",ret);

}

int main() {
	run();
	return 0;
}
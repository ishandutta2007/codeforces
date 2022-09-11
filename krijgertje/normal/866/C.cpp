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

const int MAXN=50;
const int MAXONE=100;
const int MAXT=MAXN*MAXONE;

int n,T;
int a[MAXN],b[MAXN],p[MAXN];

double E[MAXN+1][MAXT+1];

bool ok(double E00) {
	REPE(t,T) E[n][T]=0;
	for(int i=n-1;i>=0;--i) REPE(t,T) {
		E[i][t]=0;
		E[i][t]+=0.01*p[i]*(a[i]+(t+a[i]<=T?E[i+1][t+a[i]]:E00));
		E[i][t]+=0.01*(100-p[i])*(b[i]+(t+b[i]<=T?E[i+1][t+b[i]]:E00));
		if(i!=0&&E00<E[i][t]) E[i][t]=E00;
	}
	//printf("%lf -> %lf\n",E00,E[0][0]);
	return E00>=E[0][0];
}

void run() {
	scanf("%d%d",&n,&T);
	REP(i,n) scanf("%d%d%d",&a[i],&b[i],&p[i]);
	//n=MAXN; 90*n; REP(i,n) a[i]=80+rand()%10,b[i]=99-rand()%10,p[i]=80+rand()%21;

	int asum=0; REP(i,n) asum+=a[i];
	double l=asum,h=2*asum;
	while(!ok(h)) l=h,h+=h;
	REP(rep,100) {
		double m=l+(h-l)/2;
		if(!ok(m)) l=m; else h=m;
	}
	printf("%.15lf\n",l+(h-l)/2);
}

int main() {
	run();
	return 0;
}
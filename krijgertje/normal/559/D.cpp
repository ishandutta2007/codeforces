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
const int MAXSTEP=100;

int n;
int x[2*MAXN],y[2*MAXN];

double p2[MAXN+1];
double p2a[MAXSTEP+1];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&x[i],&y[i]);
	REP(i,n) x[i+n]=x[i],y[i+n]=y[i];

	p2[0]=1; FORE(i,1,MAXN) p2[i]=p2[i-1]/2;
	FORE(i,1,MAXSTEP) p2a[i]=p2[i+1]-p2[n];

	int maxstep=min(n-2,MAXSTEP);
	double ret=0;
	FORE(j,1,maxstep) REP(i,n) {
		double area=.5*x[i]*y[i+j]-.5*y[i]*x[i+j];
		int cnt=gcd(abs(x[i]-x[i+j]),abs(y[i]-y[i+j]));
		//printf("%d..%d (%lf, %lf, %d)\n",i,i+j,p2a[j],area,cnt);
		ret+=p2a[j]*(area-.5*cnt);
	}

	//fix p
	if(n<=100) ret*=(1/p2[n])/(1/p2[n]-1-n-n*(n-1)/2);
	ret=ret+1;
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}
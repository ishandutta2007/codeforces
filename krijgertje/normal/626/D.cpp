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

const int MAXN=2000;
const int MAXVAL=5000;

int n,x[MAXN];
double p1[MAXVAL+1];
double p2[2*MAXVAL+1];
double s2[2*MAXVAL+2];

void run() {
	// P(A+B+C>a+b+c | a>A,b>B,C>c)
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);
	memset(p1,0,sizeof(p1));
	double ppair=1.0/n/(n-1);
	REP(i,n) REP(j,n) if(x[i]>x[j]) p1[x[i]-x[j]]+=2*ppair;
	//REPE(i,MAXVAL) if(p1[i]>0) printf("p1[%d]=%.9lf\n",i,p1[i]);
	memset(p2,0,sizeof(p2));
	REPE(i,MAXVAL) REPE(j,MAXVAL) p2[i+j]+=p1[i]*p1[j];
	//REPE(i,2*MAXVAL) if(p2[i]>0) printf("p2[%d]=%.9lf\n",i,p2[i]);
	s2[0]=0; REPE(i,2*MAXVAL) s2[i+1]=s2[i]+p2[i];
	double ret=0;
	REPE(i,MAXVAL) ret+=p1[i]*s2[i];
	printf("%.9lf\n",ret);
}
int main() {
	run();
	return 0;
}
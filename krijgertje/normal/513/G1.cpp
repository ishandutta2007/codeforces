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

int n,times;
double p[2][100][100];
int x[100];

void run() {
	scanf("%d%d",&n,&times);
	REP(i,n) scanf("%d",&x[i]);
	if(times>2000) times=2000;
	int at=0;
	REP(i,n) FOR(j,i+1,n) p[at][i][j]=0;
	double den=.5*n*(n+1);
	REP(t,times) {
		int to=1-at;
		REP(i,n) FOR(j,i+1,n) {
			p[to][i][j]=0;
			// =sum(p[at][ni][nj]*p(ni+nj)
			REP(a,n) FOR(b,a,n) {
				int ni=i<a||i>b?i:a+b-i;
				int nj=j<a||j>b?j:a+b-j;
				if(ni<=nj) p[to][i][j]+=p[at][ni][nj]/den;
				else p[to][i][j]+=(1-p[at][nj][ni])/den;
			}
		}
		at=to;
	}
	//REP(i,n) FOR(j,i+1,n) printf("%d %d: %lf\n",i,j,p[at][i][j]);
	double ret=0;
	REP(i,n) FOR(j,i+1,n) {
		if(x[i]>x[j]) ret+=1-p[at][i][j]; else ret+=p[at][i][j];
	}
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}
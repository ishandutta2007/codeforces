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

const int MAXN=1000000;
const int MAXV=1000000;

int n;
int a[MAXN];

vector<int> pos[MAXV+1];

double calc(int x) {
	return 1.0*x/n*x/n;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]); REP(i,n) pos[a[i]].PB(i);
	double ret=0;
	FORE(i,1,MAXV) if(SZ(pos[i])>0) {
		double p=1.0;
		p-=calc(pos[i][0]);
		FORSZ(j,1,pos[i]) p-=calc(pos[i][j]-pos[i][j-1]-1);
		p-=calc(n-pos[i].back()-1);
		ret+=p;
	}
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}
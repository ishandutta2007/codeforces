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

int n;
int x[1000],y[1000];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&x[i],&y[i]);
	int lx=INT_MAX,ly=INT_MAX,hx=INT_MIN,hy=INT_MIN;
	REP(i,n) if(x[i]<lx) lx=x[i];
	REP(i,n) if(x[i]>hx) hx=x[i];
	REP(i,n) if(y[i]<ly) ly=y[i];
	REP(i,n) if(y[i]>hy) hy=y[i];
	int side=max(hx-lx,hy-ly);
	cout<<(ll)side*side<<endl;
}

int main() {
	run();
	return 0;
}
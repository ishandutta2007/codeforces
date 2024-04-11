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

int n,len;
int cmp(int *a,int sa,int *b,int sb) {
	REP(i,n) { int aa=a[(sa+i)%n],bb=b[(sb+i)%n]; if(aa!=bb) return aa<bb?-1:+1; } return 0;
}

int x[2][MAXN];
int y[2][MAXN];
int a[2];

void run() {
	scanf("%d%d",&n,&len); REP(i,2) REP(j,n) scanf("%d",&x[i][j]);
	REP(i,2) sort(x[i],x[i]+n);
	REP(i,2) REP(j,n) y[i][j]=(j+1>=n?x[i][0]+len:x[i][j+1])-x[i][j];
	REP(i,2) { a[i]=0; FOR(j,1,n) if(cmp(y[i],j,y[i],a[i])<0) a[i]=j; }
	printf("%s\n",cmp(y[0],a[0],y[1],a[1])==0?"YES":"NO");	
}

int main() {
	run();
	return 0;
}
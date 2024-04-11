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

int n;
int par[MAXN];

void printtree() {
	REP(i,n) if(par[i]!=-1) printf("%d %d\n",par[i]+1,i+1);
}

void solvewrong() {
	if(n<6) { printf("-1\n"); return; }
	par[0]=-1; par[1]=par[2]=par[3]=0; par[4]=par[5]=1; FOR(i,6,n) par[i]=0;
	printtree();
}

void solveok() {
	par[0]=-1; FOR(i,1,n) par[i]=0;
	printtree();
}

void run() {
	scanf("%d",&n);
	solvewrong();
	solveok();
}

int main() {
	run();
	return 0;
}
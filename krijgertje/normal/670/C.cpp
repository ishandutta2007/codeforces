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

const int MAXM=200000;

int n,m;
map<int,int> cnt;
int y[MAXM],z[MAXM];



void run() {
	scanf("%d",&n); cnt.clear(); REP(i,n) { int x; scanf("%d",&x); ++cnt[x]; }
	scanf("%d",&m); REP(i,m) scanf("%d",&y[i]); REP(i,m) scanf("%d",&z[i]);
	int ridx=-1,ry=-1,rz=1; REP(i,m) { int cy=cnt[y[i]],cz=cnt[z[i]]; if(cy>ry||cy==ry&&cz>rz) ridx=i,ry=cy,rz=cz; }
	printf("%d\n",ridx+1);
}

int main() {
	run();
	return 0;
}
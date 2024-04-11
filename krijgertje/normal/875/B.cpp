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

const int MAXN=300000;

int n;
int p[MAXN];

bool incirc[MAXN];
int ret[MAXN+1],nret;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&p[i]),--p[i];

	REP(i,n) incirc[i]=false;
	int lastout=n-1; nret=0; ret[nret++]=1;
	REP(i,n) {
		incirc[p[i]]=true;
		while(lastout>=0&&incirc[lastout]) --lastout;
		if(lastout>=0) {
			int numleftincirc=(i+1)-(n-1-lastout);
			ret[nret++]=numleftincirc+1;
		} else {
			ret[nret++]=1;
		}
	}
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}
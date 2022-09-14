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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n;
int type[5000];
int at[3];

int nret,ret[5000][3];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&type[i]);
	memset(at,0,sizeof(at)); nret=0;
	while(true) {
		bool ok=true;
		REP(i,3) {
			while(at[i]<n&&type[at[i]]!=i+1) ++at[i];
			if(at[i]>=n) ok=false;
		}
		if(!ok) break;
		REP(i,3) ret[nret][i]=++at[i]; ++nret;
	}
	printf("%d\n",nret);
	REP(i,nret) { REP(j,3) { if(j!=0) printf(" "); printf("%d",ret[i][j]); } puts(""); }
}

int main() {
	run();
	return 0;
}
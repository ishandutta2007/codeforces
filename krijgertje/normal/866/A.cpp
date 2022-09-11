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
const int MAXD=10;
const int ND=3;
const int D[ND]={2,4};

int wantways,target;
int nd,d[MAXD];

int ways[MAXN+1];

void run() {
	scanf("%d",&wantways);
	target=999999;
	nd=0; d[nd++]=2; d[nd++]=4; d[nd++]=target-(wantways-1)*4;
	printf("%d %d\n",target,nd); REP(i,nd) { if(i!=0) printf(" "); printf("%d",d[i]); } puts("");

	//memset(ways,0,sizeof(ways)); ways[0]=1;
	//REP(i,nd) FORE(x,d[i],target) ways[x]+=ways[x-d[i]];
	//fprintf(stderr,"wantways=%d ways=%d\n",wantways,ways[target]);
}

int main() {
	run();
	return 0;
}
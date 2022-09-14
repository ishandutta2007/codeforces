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
#include <random>
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

const int MAXN=1000;
const int MAXK=1000;

int n,K;
char s[MAXN+1];

int act[MAXN+1][2*MAXK+1]; // dp[i][MAXK+k]=-1 if it is impossible to have balance k after i games, (the value of the last game)+1 otherwise (1 for i=0)
char ret[MAXN+1];

void run() {
	scanf("%d%d%s",&n,&K,s); 
	memset(act,-1,sizeof(act)); act[0][MAXK]=1;
	REP(i,n) {
		int mxb=min(i,K-1);
		FORE(k,-mxb,+mxb) if(act[i][MAXK+k]!=-1) {
			FORE(a,-1,+1) {
				if(s[i]=='L'&&a!=-1) continue;
				if(s[i]=='D'&&a!=0 ) continue;
				if(s[i]=='W'&&a!=+1) continue;
				act[i+1][MAXK+k+a]=a+1;
			}
		}
	}
	for(int k=-K;k<=+K;k+=2*K) if(act[n][MAXK+k]!=-1) {
		//printf("sk=%d\n",k);
		for(int i=n-1;i>=0;--i) {
			//printf("\t%d %d -> %d\n",i,k,act[i+1][MAXK+k]);
			ret[i]="LDW"[act[i+1][MAXK+k]]; k-=act[i+1][MAXK+k]-1;
		}
		ret[n]='\0'; printf("%s",ret); return;
	}
	printf("NO\n");


	

}

int main() {
	run();
	return 0;
}
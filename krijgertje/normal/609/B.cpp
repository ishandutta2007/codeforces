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

const int MAXN=200000;
const int MAXG=10;

int n,ng;
int x[MAXN];
int cnt[MAXG];

void run() {
	scanf("%d%d",&n,&ng); REP(i,n) scanf("%d",&x[i]),--x[i]; 
	memset(cnt,0,sizeof(cnt)); REP(i,n) cnt[x[i]]++;
	//REP(i,ng) printf("%d\n",cnt[i]);
	int ret=0; REP(i,ng) FOR(j,i+1,ng) ret+=cnt[i]*cnt[j]; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
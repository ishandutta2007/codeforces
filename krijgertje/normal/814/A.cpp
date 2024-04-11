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

const int MAXN=100;

int na,nb;
int a[MAXN];
int b[MAXN];

bool solve() {
	if(nb>=2) return true;
	int prev=-1;
	REP(i,na) {
		int cur=a[i]==0?b[0]:a[i];
		if(i!=0&&(cur<prev)) return true;
		prev=cur;
	}
	return false;
}

void run() {
	scanf("%d%d",&na,&nb); REP(i,na) scanf("%d",&a[i]); REP(i,nb) scanf("%d",&b[i]);
	printf("%s\n",solve()?"Yes":"No");
}

int main() {
	run();
	return 0;
}
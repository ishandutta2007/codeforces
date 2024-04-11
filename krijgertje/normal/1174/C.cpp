#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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

const int MAXN=100000;

int n;
int a[MAXN+1];

int pmn[MAXN+1];

void solve() {
	memset(pmn,-1,sizeof(pmn));
	FORE(i,2,MAXN) if(pmn[i]==-1) for(int j=i;j<=MAXN;j+=i) if(pmn[j]==-1) pmn[j]=i;
	int nxt=1;
	FORE(i,2,MAXN) if(pmn[i]==i) a[i]=nxt++; else a[i]=a[pmn[i]];
}

void run() {
	scanf("%d",&n);
	solve();
	FORE(i,2,n) { if(i!=2) printf(" "); printf("%d",a[i]); } puts("");
}

int main() {
	run();
	return 0;
}
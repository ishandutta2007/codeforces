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

const int MAXN=400000;

int n,mxbytes;
int a[MAXN];

int b[MAXN]; int nb;
int bsum[MAXN+1];

int solve() {
	sort(a,a+n);
	nb=0; for(int l=0,r=l;l<n;l=r) { while(r<n&&a[r]==a[l]) ++r; b[nb++]=r-l; }
	bsum[0]=0; REP(i,nb) bsum[i+1]=bsum[i]+b[i];
	int mxbits=mxbytes*8;
	int mxk=mxbits/n;
	int mxdistinct=min(nb,1<<min(30,mxk));
	int ret=INT_MAX; REPE(i,n-mxdistinct) ret=min(ret,bsum[i]+n-bsum[i+mxdistinct]); return ret;
}

void run() {
	scanf("%d%d",&n,&mxbytes);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
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

const int MAXN=100;
const int MAXVAL=100;

int n;
int a[MAXN];

int ways[MAXN+1][MAXN*MAXVAL+1];

int solve() {
	sort(a,a+n);
	memset(ways,0,sizeof(ways));
	ways[0][0]=1;
	int mx=0;
	vector<int> vals;
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&a[l]==a[r]) ++r;
		int val=a[l],cnt=r-l; vals.PB(val);
		for(int i=l;i>=0;--i) REPE(j,mx) FORE(k,1,cnt) ways[i+k][j+k*val]+=ways[i][j];
		mx+=cnt*val; REPE(i,r) REPE(j,mx) if(ways[i][j]>2) ways[i][j]=2;
	}
	//printf("vals:"); REPSZ(i,vals) printf(" %d",vals[i]); puts("");
	//printf("ways:\n"); REPE(i,n) { printf("%d:",i); REPE(j,mx) printf(" %d",ways[i][j]); puts(""); }
	int ret=0;
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&a[l]==a[r]) ++r;
		int val=a[l],cnt=r-l;
		REPE(k,cnt) {
			if(ways[k][k*val]==1) ret=max(ret,k);
			if(k==cnt&&SZ(vals)==2) { int oval=vals[0]+vals[1]-val,ocnt=(mx-val*cnt)/oval; if(ways[ocnt][ocnt*oval]==1) ret=max(ret,cnt+ocnt); }
		}
	}
	return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
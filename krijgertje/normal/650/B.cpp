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

const int MAXN=500000;

int n,tswipe,trot,thave;
char s[MAXN+1];

int solve(int tleft) {
	int j=n;
	while(j!=1) { int need=tswipe+(s[j-1]=='w'?trot:0)+1; if(tleft<need) break; tleft-=need; --j; }
	int ret=1+n-j;
	FOR(i,1,n) {
		int need=2*tswipe+(s[i]=='w'?trot:0)+1;
		while(j!=n&&(tleft<need||j==i)) {
			tleft+=tswipe+(s[j]=='w'?trot:0)+1; ++j;
		}
		if(tleft<need) break;
		tleft-=need;
		int cur=i+1+n-j; if(cur>ret) ret=cur;
	}
	return ret;
}

void run() {
	scanf("%d%d%d%d%s",&n,&tswipe,&trot,&thave,s);

	int tleft=thave-(s[0]=='w'?trot:0)-1; if(tleft<0) { printf("0\n"); return; }
	int a=solve(tleft); reverse(s+1,s+n); int b=solve(tleft); printf("%d\n",max(a,b));
}

int main() {
	run();
	return 0;
}
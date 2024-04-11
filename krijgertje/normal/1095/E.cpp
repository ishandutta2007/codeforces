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

const int MAXN=1000000;

int n;
char s[MAXN+1];

int prefsum[MAXN+1]; // prefsum[i]=sum over positions < i
int prefmn[MAXN+1];
int suffsum[MAXN+1]; // suffsum[i]=sum over positions >= i
int suffmn[MAXN+1];

int solve() {
	prefsum[0]=0; REP(i,n) prefsum[i+1]=prefsum[i]+(s[i]=='('?+1:-1);
	suffsum[n]=0; for(int i=n-1;i>=0;--i) suffsum[i]=suffsum[i+1]+(s[i]==')'?+1:-1);
	prefmn[0]=0; FORE(i,1,n) prefmn[i]=min(prefmn[i-1],prefsum[i]);
	suffmn[n]=0; for(int i=n-1;i>=0;--i) suffmn[i]=min(suffmn[i+1],suffsum[i]);
	int ret=0;
	REP(i,n) {
		if(prefmn[i]<0||suffmn[i+1]<0) continue;
		int nsum=prefsum[i]+(s[i]=='('?-1:+1);
		if(nsum!=suffsum[i+1]) continue;
		++ret;
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	scanf("%s",s);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
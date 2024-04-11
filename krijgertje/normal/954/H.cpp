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

const int MAXN=5000;
const int MOD=1000000007;

int n;
int a[MAXN];

int one[2][MAXN]; // one[i][j] is number of ways to walk down j steps from depth i with the first step fixed
int two[2][2*MAXN-1]; // two[i][j] is number of ways to walk down j steps in total in two paths from depth i with the first step on both paths fixed

int cnt[MAXN];
int ans[2*MAXN-1];

void inc(int &a,ll b) { a=(a+b)%MOD; }
void run() {
	scanf("%d",&n); REP(i,n-1) scanf("%d",&a[i]); a[n-1]=0;

	cnt[0]=1; REP(i,n-1) cnt[i+1]=(ll)cnt[i]*a[i]%MOD;
	memset(ans,0,sizeof(ans));
	
	int at=0;
	memset(one[at],0,sizeof(one[at])); memset(two[at],0,sizeof(two[at]));
	for(int i=n-2;i>=0;--i) {
		int to=1-at; memset(one[to],0,sizeof(one[to])); memset(two[to],0,sizeof(two[to]));
		one[to][1]=1;
		REPE(j,n-1) if(one[at][j]!=0) inc(one[to][j+1],(ll)one[at][j]*a[i+1]);
		two[to][2]=1;
		REPE(j,n-1) if(one[at][j]!=0) inc(two[to][j+2],(ll)2*one[at][j]*a[i+1]);
		REPE(j,2*n-2) if(two[at][j]!=0) inc(two[to][j+2],(ll)two[at][j]*a[i+1]%MOD*a[i+1]);

		//printf("one%d:"); REPE(j,n-1) if(one[to][j]!=0) printf(" %d*%d",one[to][j],j); puts("");
		//printf("two%d:"); REPE(j,2*n-2) if(two[to][j]!=0) printf(" %d*%d",two[to][j],j); puts("");

		REPE(j,n-1) if(one[to][j]!=0) inc(ans[j],(ll)one[to][j]*a[i]%MOD*cnt[i]);
		REPE(j,2*n-2) if(two[to][j]!=0) inc(ans[j],(ll)two[to][j]*((ll)a[i]*(a[i]-1)/2%MOD)%MOD*cnt[i]);

		at=to;
	}
	
	FORE(i,1,2*n-2) { if(i!=1) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}
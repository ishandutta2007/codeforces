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
const int MOD=1000000007;

int n;
int x[MAXN];
int l[MAXN],m[MAXN],r[MAXN];

void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]),--x[i];
	REP(i,n-1) l[i]=min(x[i],x[i+1]); l[n-1]=x[n-1];
	r[0]=x[0]; FOR(i,1,n) r[i]=min(x[i-1],x[i]);
	REP(i,n) m[i]=min(l[i],r[i]);

	int ret=0,sum=0;
	REP(i,n) {
		inc(ret,x[i]);
		inc(ret,(ll)sum*r[i]%MOD);
		sum=(ll)sum*m[i]%MOD; inc(sum,l[i]);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
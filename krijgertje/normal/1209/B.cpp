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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100;

int n;
char s[MAXN+1];
int a[MAXN],b[MAXN];

int solve() {
	int period=a[0]; FOR(i,1,n) period=period/gcd(period,a[i])*a[i];
	int bmx=b[0]; FOR(i,1,n) bmx=max(bmx,b[i]);
	int ret=0;
	REPE(t,2*period+bmx) {
		int cur=0;
		REP(i,n) {
			int x=s[i]-'0';
			if(t>=b[i]) {
				x=1-x;
				int times=(t-b[i])/a[i];
				if(times%2==1) x=1-x;
			}
			cur+=x;
		}
		ret=max(ret,cur);
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	scanf("%s",s); assert(strlen(s)==n);
	REP(i,n) scanf("%d%d",&a[i],&b[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
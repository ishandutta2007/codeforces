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

const int MAXN=1000000;

char s[MAXN+1]; int n;

int a[MAXN];
int b[MAXN+1];

ll solve() {
	REP(i,n) a[i]=i+1<n&&s[i]=='v'&&s[i+1]=='v';
	b[0]=0; REP(i,n) b[i+1]=a[i]+b[i];
	ll ret=0;
	REP(i,n) if(s[i]=='o') {
		int l=b[i],r=b[n]-b[i];
		ret+=(ll)l*r;
	}
	return ret;
}

void run() {
	scanf("%s",s); n=strlen(s);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}
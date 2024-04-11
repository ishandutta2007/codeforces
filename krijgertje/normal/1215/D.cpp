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

const int MAXN=200000;

int n;
char s[MAXN+1];

bool solve() {
	int n1=0,sum1=0,n2=0,sum2=0;
	REP(i,n/2) if(s[i]=='?') ++n1; else sum1+=s[i]-'0';
	FOR(i,n/2,n) if(s[i]=='?') ++n2; else sum2+=s[i]-'0';
	int mn=min(n1,n2);
	n1-=mn,n2-=mn;
	if(n1==0&&n2==0) return sum1!=sum2;
	if(n1==0) { assert(n2%2==0); int need=sum1-sum2; return need!=(n2/2)*9; }
	if(n2==0) { assert(n1%2==0); int need=sum2-sum1; return need!=(n1/2)*9; }
	assert(false); return false;
}

void run() {
	scanf("%d",&n);
	scanf("%s",s); assert(strlen(s)==n);
	printf("%s\n",solve()?"Monocarp":"Bicarp");
}

int main() {
	run();
	return 0;
}
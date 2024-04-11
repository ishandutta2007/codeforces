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

const int MAXN=100000;

int n; char s[MAXN+1];

int solve(char a) {
	int n0=0,n1=0;
	REP(i,n) {
		if(i%2==0&&s[i]!=a) ++n0;
		if(i%2==1&&s[i]==a) ++n1;
	}
	//printf("%c -> %d %d\n",a,n0,n1);
	return max(n0,n1);
}

void run() {
	scanf("%d%s",&n,s); n=strlen(s);
	int ret=min(solve('r'),solve('b'));
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
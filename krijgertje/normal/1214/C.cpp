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
	int bal=0,minbal=0;
	REP(i,n) {
		if(s[i]=='(') ++bal; else --bal;
		minbal=min(minbal,bal);
	}
	return bal==0&&minbal>=-1;
}

void run() {
	scanf("%d",&n);
	scanf("%s",s); assert(strlen(s)==n);
	printf("%s\n",solve()?"Yes":"No");
}

int main() {
	run();
	return 0;
}
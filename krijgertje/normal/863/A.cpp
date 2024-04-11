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

const int MAXLEN=10;

char s[MAXLEN+1]; int n;

bool solve() {
	FORE(len,n,2*n-1) {
		bool ok=true;
		for(int i=0;i<len-i-1;++i) {
			char a=i<len-n?'0':s[i-(len-n)];
			char b=len-i-1<len-n?'0':s[len-i-1-(len-n)];
			//printf("len=%d i=%d -> %c %c\n",len,i,a,b);
			if(a!=b) ok=false;
		}
		if(ok) return true;
	}
	return false;
}

void run() {
	scanf("%s",s); n=strlen(s);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}
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

const int MAXS=1000;
char s[MAXS+1]; int slen; int k;

bool ok() {
	if(slen%k!=0) return false;
	REP(i,k) {
		int a=i*(slen/k),b=a+(slen/k)-1;
		while(a<b) {
			if(s[a]!=s[b]) return false;
			++a,--b;
		}
	}
	return true;
}
void run() {
	scanf("%s%d",s,&k); slen=strlen(s);
	printf("%s\n",ok()?"YES":"NO");
}

int main() {
	run();
	return 0;
}
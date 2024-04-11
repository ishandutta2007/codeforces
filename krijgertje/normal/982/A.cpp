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

//23:07
const int MAXN=1000;

int n;
char s[MAXN+1];

bool solve() {
	REP(i,n-1) if(s[i]=='1'&&s[i+1]=='1') return false;
	REP(i,n) if(s[i]=='0') {
		bool can=true; FORE(di,-1,+1) { int ni=i+di; if(0<=ni&&ni<n&&s[ni]=='1') can=false; } if(can) return false;
	}
	return true;
}

void run() {
	scanf("%d",&n); scanf("%s",s);
	printf("%s\n",solve()?"Yes":"No");
}

int main() {
	run();
	return 0;
}
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=300000;

int n;
char s[MAXN+1];

pair<int,int> solve() {
	FOR(i,1,n) if(s[i]<s[i-1]) return MP(i-1,i);
	return MP(-1,-1);
}

void run() {
	scanf("%d",&n);
	scanf("%s",s);
	pair<int,int> ans=solve();
	if(ans==MP(-1,-1)) { printf("NO\n"); return; }
	printf("YES\n%d %d\n",ans.first+1,ans.second+1);
}

int main() {
	run();
	return 0;
}
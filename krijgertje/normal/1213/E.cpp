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

const int MAXN=100000;

int n;
char s[3];
char t[3];
char ans[3*MAXN+1];

bool test() {
	REP(i,3*n-1) {
		if(ans[i]==s[0]&&ans[i+1]==s[1]) return false;
		if(ans[i]==t[0]&&ans[i+1]==t[1]) return false;
	}
	return true;
}

bool solve() {
	char p[3]; REP(i,3) p[i]='a'+i;
	do {
		REP(i,3*n) ans[i]=p[i%3]; ans[3*n]='\0';
		if(test()) return true;
		REP(i,3*n) ans[i]=p[i/n]; ans[3*n]='\0';
		if(test()) return true;
	} while(next_permutation(p,p+3));
	return false;
}

void run() {
	scanf("%d%s%s",&n,s,t);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%s\n",ans);
}

void stress() {
	REP(i,3) REP(ii,3) REP(j,3) REP(jj,3) {
		s[0]='a'+i,s[1]='a'+ii,s[2]='\0';
		t[0]='a'+i,t[1]='a'+ii,t[2]='\0';
		n=10;
		bool have=solve();
		assert(have);
	}
}

int main() {
	run();
	//stress();
	return 0;
}
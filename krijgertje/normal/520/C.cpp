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

const int MOD=1000000007;
int n;
char s[100001];
int cnt[26];

void run() {
	scanf("%d%s",&n,s);
	REP(i,26) cnt[i]=0;
	REP(i,n) ++cnt[s[i]-'A'];
	int mx=0,mxcnt=0;
	REP(i,26) {
		if(cnt[i]>mx) mx=cnt[i],mxcnt=0;
		if(cnt[i]==mx) ++mxcnt;
	}
	int ret=1;
	REP(i,n) {
		ret=(ll)ret*mxcnt%MOD;
	}
	printf("%d\n",ret);

}

int main() {
	run();
	return 0;
}
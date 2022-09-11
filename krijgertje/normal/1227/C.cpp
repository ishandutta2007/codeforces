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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXN=2000;

int n,want;
char s[MAXN+1];
vector<pair<int,int>> ans;

char t[MAXN+1];

void solve() {
	ans.clear();
	int fst=(n-2*want+2)/2;
	REP(i,n) t[i]=i%2==0?'(':')';
	REP(i,fst) t[i]='(',t[fst+i]=')';
	t[n]='\0';
	//printf("t=%s\n",t);
	REP(i,n) {
		int j=i; while(j<n&&s[j]!=t[i]) ++j; assert(j<n);
		if(i!=j) ans.PB(MP(i,j));
		reverse(s+i,s+j+1);
	}
}

void run() {
	scanf("%d%d",&n,&want);
	scanf("%s",s); assert(strlen(s)==n);
	solve();
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}
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

const int MAXN=1500;

int n;
char s[MAXN+1];

vector<int> pos[26];
int ans[26][MAXN+1];

void run() {
	scanf("%d%s",&n,s); REP(i,26) pos[i].clear(); REP(i,n) pos[s[i]-'a'].PB(i);
	REP(i,26) {
		REPE(j,n) ans[i][j]=-1; ans[i][0]=0;
		REPSZ(j,pos[i]) FORSZ(k,j,pos[i]) {
			int len=pos[i][k]-pos[i][j]+1,have=k-j+1,need=len-have;
			if(ans[i][need]==-1||len>ans[i][need]) ans[i][need]=len;
		}
		FORE(need,1,n) {
			int len=min(n,ans[i][need-1]+1);
			if(ans[i][need]==-1||len>ans[i][need]) ans[i][need]=len;
		}
	}
	int nq; scanf("%d",&nq);
	REP(i,nq) {
		int have; char c; scanf("%d %c",&have,&c);
		int ret=ans[c-'a'][have];
		printf("%d\n",ret);
	}
}

int main() {
	run();
	return 0;
}
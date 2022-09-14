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

int n;
char s[200001];
char t[200001];

int ret;
int have[26][26];

void run() {
	scanf("%d%s%s",&n,s,t);
	ret=0; REP(i,26) REP(j,26) have[i][j]=-1;
	REP(i,n) if(s[i]!=t[i]) {
		++ret;
		int a=s[i]-'a',b=t[i]-'a'; if(have[a][b]==-1) have[a][b]=i;
	}
	REP(i,26) FOR(j,i+1,26) if(have[i][j]!=-1&&have[j][i]!=-1) { printf("%d\n%d %d\n",ret-2,have[i][j]+1,have[j][i]+1); return; }
	REP(i,26) {
		int j=-1; REP(jj,26) if(have[jj][i]!=-1) { j=jj; break; } if(j==-1) continue;
		int k=-1; REP(kk,26) if(have[i][kk]!=-1) { k=kk; break; } if(k==-1) continue;
		printf("%d\n%d %d\n",ret-1,have[j][i]+1,have[i][k]+1); return;
	}
	printf("%d\n-1 -1\n",ret);
}

int main() {
	run();
	return 0;
}
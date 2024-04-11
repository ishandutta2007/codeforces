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

int n; char s[7];

bool canzero[10];
int sum[10];
int mp[10];

void run() {
	REP(i,10) canzero[i]=true,sum[i]=0,mp[i]=-1;
	scanf("%d",&n); REP(i,n) { scanf("%s",s); int len=strlen(s); int x=1; REP(j,len) { int y=s[len-1-j]-'a'; sum[y]+=x; if(j==len-1) canzero[y]=false; x*=10; } }
	//REP(i,10) printf("%c: sum=%d canzero=%s\n",'a'+i,sum[i],canzero[i]?"yes":"no");

	REP(i,10) {
		int idx=-1; REP(j,10) { if(i==0&&!canzero[j]) continue; if(mp[j]!=-1) continue; if(idx==-1||sum[j]>sum[idx]) idx=j; } assert(idx!=-1);
		mp[idx]=i;
	}
	int ret=0; REP(i,10) ret+=sum[i]*mp[i]; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
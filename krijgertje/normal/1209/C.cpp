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

const int MAXN=200000;

int n;
char s[MAXN+1];
char ans[MAXN+1];

int a[MAXN];
int mn[MAXN];

bool solve() {
	REP(i,n) a[i]=s[i]-'0';
	for(int i=n-1;i>=0;--i) { mn[i]=a[i]; if(i+1<n) mn[i]=min(mn[i],mn[i+1]); }
	REP(i,n) ans[i]='?'; ans[n]='\0';
	REP(i,n) if(a[i]==mn[i]) ans[i]='1';
	int idx=-1; REP(i,n) if(ans[i]=='?') { idx=i; break; } if(idx==-1) return true;
	int fst2=a[idx]; REP(i,n) if(ans[i]=='1'&&a[i]>fst2) ans[i]='?';
	int lst=fst2; REP(i,n) if(ans[i]=='?') { if(a[i]<lst) return false; ans[i]='2',lst=a[i]; }
	return true;
}

void run() {
	scanf("%d",&n);
	scanf("%s",s); assert(strlen(s)==n);
	if(!solve()) { printf("-\n"); return; }
	printf("%s\n",ans);
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}
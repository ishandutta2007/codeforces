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

const int MAXN=100000;

int n;
int a[MAXN];
char ans[MAXN+1];

int pos[MAXN+1];

bool canwin(int at,int step) {
	for(int i=at-step;i>=0;i-=step) if(ans[i]=='B') return true;
	for(int i=at+step;i<n;i+=step) if(ans[i]=='B') return true;
	return false;
}

void solve() {
	REP(i,n) ans[i]='?'; ans[n]='\0';
	REP(i,n) pos[a[i]]=i;
	for(int i=n;i>=1;--i) {
		int idx=pos[i];
		ans[idx]=canwin(idx,i)?'A':'B';
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	solve();
	printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}
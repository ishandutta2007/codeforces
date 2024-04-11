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
char t[MAXN+1];
pair<int,int> ans[MAXN]; int nans;

int x[MAXN],nx;
int y[MAXN],ny;

bool solve() {
	nx=ny=0;
	REP(i,n) if(s[i]=='a'&&t[i]=='b') x[nx++]=i; else if(s[i]=='b'&&t[i]=='a') y[ny++]=i;
	if((nx+ny)%2!=0) return false;
	nans=0;
	if(nx%2!=0) { int idx=x[--nx]; y[ny++]=idx; ans[nans++]=MP(idx,idx); }
	REP(i,nx/2) ans[nans++]=MP(x[2*i+0],x[2*i+1]);
	REP(i,ny/2) ans[nans++]=MP(y[2*i+0],y[2*i+1]);
	return true;
}


void run() {
	scanf("%d",&n);
	scanf("%s",s); assert(strlen(s)==n);
	scanf("%s",t); assert(strlen(t)==n);
	if(!solve()) { printf("-1\n"); return; }
	printf("%d\n",nans);
	REP(i,nans) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
}

int main() {
	run();
	return 0;
}
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

const int MAXN=50;

int n,k;
char ans[MAXN][5];
bool eff[MAXN];

int id[MAXN],nid;
void print(int x) { printf("%c%c",'A'+x/26,'a'+x%26); }

void run() {
	scanf("%d%d",&n,&k); REP(i,n-k+1) scanf("%s",ans[i]),eff[i]=strcmp(ans[i],"YES")==0;
	bool found=false; nid=0;
	REP(i,n-k+1) if(eff[i]) {
		nid=0; REP(j,k) id[i+j]=nid++;
		for(int j=i-1;j>=0;--j) { assert(!eff[j]); id[j]=id[j+k-1]; }
		FOR(j,i+1,n-k+1) id[j+k-1]=eff[j]?nid++:id[j];
		found=true; break;
	}
	if(!found) REP(i,n) id[i]=0; nid=1;
	REP(i,n) { if(i!=0) printf(" "); print(id[i]); } puts("");
}

int main() {
	run();
	return 0;
}
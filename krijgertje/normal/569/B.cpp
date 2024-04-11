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

const int MAXN=100000;

int n;
int x[MAXN];
int ret[MAXN];
bool used[MAXN+1];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&x[i]);
	memset(ret,-1,sizeof(ret));
	memset(used,false,sizeof(used));
	REP(i,n) if(1<=x[i]&&x[i]<=n&&!used[x[i]]) ret[i]=x[i],used[x[i]]=true;
	int at=1; REP(i,n) if(ret[i]==-1) { while(used[at]) ++at; ret[i]=at++; }
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}


int main() {
	run();
	return 0;
}
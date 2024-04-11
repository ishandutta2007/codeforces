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
const int MAXM=100000;

int n,m,k;
bool store[MAXN];
int a[MAXM],b[MAXM],c[MAXM];

void run() {
	scanf("%d%d%d",&n,&m,&k);
	REP(i,m) scanf("%d%d%d",&a[i],&b[i],&c[i]),--a[i],--b[i];
	memset(store,false,sizeof(store)); REP(i,k) { int x; scanf("%d",&x); --x; store[x]=true; }
	int ret=-1;
	REP(i,m) if(store[a[i]]&&!store[b[i]]&&(ret==-1||c[i]<ret)) ret=c[i];
	REP(i,m) if(store[b[i]]&&!store[a[i]]&&(ret==-1||c[i]<ret)) ret=c[i];
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
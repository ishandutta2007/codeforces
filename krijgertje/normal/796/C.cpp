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

const int MAXN=300000;
const int MAXM=MAXN-1;

int n;
int str[MAXN];
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];

int cnt[2];
int cur[2];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&str[i]);
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a;
	}
	int mx=str[0]; FOR(i,1,n) if(str[i]>mx) mx=str[i];
	memset(cnt,0,sizeof(cnt)); REP(i,n) if(str[i]>=mx-1) ++cnt[mx-str[i]];
	for(int ret=mx;;++ret) {
		REP(i,n) {
			memset(cur,0,sizeof(cur));
			if(str[i]>=mx-1&&str[i]<=ret) ++cur[mx-str[i]];
			for(int x=ghead[i];x!=-1;x=gnxt[x]) {
				int j=gto[x];
				if(str[j]>=mx-1&&str[j]+1<=ret) ++cur[mx-str[j]];
			}
			bool ok=true;
			if(ret<=mx+1&&cnt[0]!=cur[0]) ok=false;
			if(ret<=mx&&cnt[1]!=cur[1]) ok=false;
			if(ok) { printf("%d\n",ret); return; }
		}
	}
	
}

int main() {
	run();
	return 0;
}
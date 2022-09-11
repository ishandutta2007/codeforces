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

const int MAXN=200000;

int n,len,lim;
int a[MAXN];
bool on[MAXN];

void run() {
	scanf("%d%d%d",&n,&len,&lim); REP(i,n) scanf("%d",&a[i]); sort(a,a+n);

	REP(i,n) on[i]=true;
	int l=0,r=0,cnt=0;
	while(l<n) {
		while(r<n&&a[r]-a[l]<len) {
			if(cnt>=lim-1) on[r]=false;
			cnt+=on[r]?1:0;
			++r;
		}
		cnt-=on[l]?1:0,++l;
	}
	int ans=0; REP(i,n) if(!on[i]) ++ans; printf("%d\n",ans);	
}

int main() {
	run();
	return 0;
}
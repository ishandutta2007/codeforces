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

const int MAXN=500000;
const int MAXVAL=1000000;

int n,k;
int a[MAXN];
int cnt[MAXVAL+1];


void run() {
	scanf("%d%d",&n,&k); REP(i,n) scanf("%d",&a[i]);
	memset(cnt,0,sizeof(cnt));
	int ret=0,retl=-1;
	for(int ndiff=0,l=0,h=0;l<n;) {
		while(h<n&&(cnt[a[h]]>0||ndiff<k)) if(cnt[a[h++]]++==0) ++ndiff;
		if(h-l>ret) ret=h-l,retl=l;
		if(--cnt[a[l++]]==0) --ndiff;
	}
	printf("%d %d\n",retl+1,retl+ret);
}

int main() {
	run();
	return 0;
}
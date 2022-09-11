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

const int MAXN=1000;

int n;

char s[MAXN+1];

int query() {
	printf("? %s\n",s); fflush(stdout);
	int ret; scanf("%d",&ret); return ret;
}

pair<int,int> solve(int l,int r,int x,int noise) {
	int m=l+(r-l)/2,n1=m-l,n2=r-m;
	FOR(i,l,r) s[i]=i<m?'0':'1';
	int y=query()-noise;
	assert((x+y-n2)%2==0);
	int a=(x+y-n2)/2,b=x-a;
	FOR(i,l,r) s[i]='0';
	if(0<a&&a<n1) return solve(l,m,a,noise+b);
	else if(0<b&&b<n2) return solve(m,r,b,noise+a);
	else return MP(a==0?l:m,a==0?m:l);
}

void run() {
	scanf("%d",&n);
	REP(i,n) s[i]='0'; s[n]='\0';
	int n1=query();
	pair<int,int> res=solve(0,n,n1,0);
	printf("! %d %d\n",res.first+1,res.second+1); fflush(stdout);
}

int main() {
	run();
	return 0;
}
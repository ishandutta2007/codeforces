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

int n;
int x[MAXN],y[MAXN];
int p[MAXN];
int xcmp(const int &a,const int &b) { if(x[a]!=x[b]) return x[a]<x[b]; return y[a]<y[b]; }
int ycmp(const int &a,const int &b) { if(y[a]!=y[b]) return y[a]<y[b]; return x[a]<x[b]; }


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&x[i],&y[i]);
	REP(i,n) p[i]=i;
	ll ret=0;
	sort(p,p+n,xcmp);
	for(int at=0,to=0;at<n;at=to) {
		while(to<n&&x[p[to]]==x[p[at]]) ++to;
		int cnt=to-at; ret+=(ll)cnt*(cnt-1)/2;
	}
	sort(p,p+n,ycmp);
	for(int at=0,to=0;at<n;at=to) {
		while(to<n&&y[p[to]]==y[p[at]]) ++to;
		int cnt=to-at; ret+=(ll)cnt*(cnt-1)/2;
	}
	for(int at=0,to=0;at<n;at=to) {
		while(to<n&&y[p[to]]==y[p[at]]&&x[p[to]]==x[p[at]]) ++to;
		int cnt=to-at; ret-=(ll)cnt*(cnt-1)/2;
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}
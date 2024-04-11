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

const int MAXN=100000;

int n; ll lim;
int a[MAXN];

pair<int,int> b[MAXN]; int nb;

int solve() {
	sort(a,a+n);
	nb=0; for(int l=0,r=l;l<n;l=r) { while(r<n&&a[r]==a[l])  ++r; b[nb++]=MP(a[l],r-l); }
	int lidx=0,lcnt=b[lidx].second,ridx=nb-1,rcnt=b[ridx].second; ll rem=lim;
	while(lidx<ridx) {
		if(lcnt<=rcnt) {
			if(b[lidx].first+rem/lcnt>=b[lidx+1].first) {
				rem-=(ll)(b[lidx+1].first-b[lidx].first)*lcnt;
				++lidx,lcnt+=b[lidx].second;
			} else {
				return b[ridx].first-b[lidx].first-rem/lcnt;
			}
		} else {
			if(b[ridx].first-rem/rcnt<=b[ridx-1].first) {
				rem-=(ll)(b[ridx].first-b[ridx-1].first)*rcnt;
				--ridx,rcnt+=b[ridx].second;
			} else {
				return b[ridx].first-b[lidx].first-rem/rcnt;
			}
		}
	}
	return 0;
}

void run() {
	scanf("%d%lld",&n,&lim);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
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
struct Z { int lim,t; };
bool operator<(const Z &a,const Z &b) { return a.t<b.t; }

int n,twant;
Z z[MAXN];

void run() {
	scanf("%d%d",&n,&twant); REP(i,n) scanf("%d",&z[i].lim); REP(i,n) scanf("%d",&z[i].t);

	sort(z,z+n);
	if(z[0].t>twant||z[n-1].t<twant) { printf("0\n"); return; }

	int l=0,r=n-1;
	ll num=0,den=0; FORE(i,l,r) num+=(ll)z[i].lim*z[i].t,den+=z[i].lim;
	while(true) {
		if(num<twant*den) {
			// x=(twant*den-num)/(twant-z[l].t);
			if(twant*den-num<(ll)z[l].lim*(twant-z[l].t)) {
				double x=1.0*(twant*den-num)/(twant-z[l].t);
				printf("%.15lf\n",den-x);
				break;
			}
			num-=(ll)z[l].lim*z[l].t,den-=z[l].lim,++l;
		} else if(num>twant*den) {
			// x=(num-twant*den)/(z[r].t-twant)
			if(num-twant*den<(ll)z[r].lim*(z[r].t-twant)) {
				double x=1.0*(num-twant*den)/(z[r].t-twant);
				printf("%.15lf\n",den-x);
				break;
			}
			num-=(ll)z[r].lim*z[r].t,den-=z[r].lim,--r;
		} else {
			printf("%lld\n",den);
			break;
		}
	}
}

int main() {
	run();
	return 0;
}
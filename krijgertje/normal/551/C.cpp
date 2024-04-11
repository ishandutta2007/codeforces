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

const int MAXBOX=100000;

int nbox,nstud;
int a[MAXBOX];


bool can(ll t) {
	ll nfree=0,left=nstud; 
	for(int i=nbox-1;i>=0;--i) if(a[i]>0) {
		ll have=a[i];
		ll cur=min(have,nfree); have-=cur; nfree-=cur;
		if(have==0) continue;
		ll each=t-(i+1); if(each<=0) return false;
		ll cnt=(have+each-1)/each;
		if(cnt>left) return false;
		left-=cnt;
		nfree+=each*cnt-have;
	}
	return true;
}


void run() {
	scanf("%d%d",&nbox,&nstud);
	REP(i,nbox) scanf("%d",&a[i]);

	ll l=0,h=1;
	while(!can(h)) l=h,h+=h;
	while(l+1<h) { ll m=l+(h-l)/2; if(can(m)) h=m; else l=m; }
	cout<<h<<endl;
}

int main() {
	run();
	return 0;
}
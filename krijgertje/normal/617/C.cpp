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

const int MAXN=2000;

int n;
int ax,ay,bx,by;
int cx[MAXN],cy[MAXN];
ll ca[MAXN],cb[MAXN];

void run() {
	scanf("%d%d%d%d%d",&n,&ax,&ay,&bx,&by);
	REP(i,n) scanf("%d%d",&cx[i],&cy[i]);
	REP(i,n) ca[i]=(ll)(cx[i]-ax)*(cx[i]-ax)+(ll)(cy[i]-ay)*(cy[i]-ay);
	REP(i,n) cb[i]=(ll)(cx[i]-bx)*(cx[i]-bx)+(ll)(cy[i]-by)*(cy[i]-by);

	ll ret=LLONG_MAX;
	REPE(i,n) {
		ll cur=i==n?0:ca[i],mx=0;
		REP(j,n) if(ca[j]>cur&&cb[j]>mx) mx=cb[j];
		cur+=mx;
		if(cur<ret) ret=cur;
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}
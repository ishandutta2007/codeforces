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
const int MAXLEN=100000;
typedef struct R { int s,h; } R;
bool operator<(const R &a,const R &b) { return (ll)a.s*b.h>(ll)b.s*a.h; }

int n;
R r[MAXN];
char buff[MAXLEN+1];

void run() {
	scanf("%d",&n);
	ll ret=0;
	REP(i,n) {
		scanf("%s",buff); int len=strlen(buff);
		r[i].s=r[i].h=0; REP(j,len) if(buff[j]=='s') ++r[i].s; else if(buff[j]=='h') ++r[i].h,ret+=r[i].s;
	}
	sort(r,r+n);
	int sum=0; REP(i,n) ret+=(ll)sum*r[i].h,sum+=r[i].s;
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}
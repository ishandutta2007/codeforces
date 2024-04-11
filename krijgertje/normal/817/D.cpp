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

const int MAXN=1000000;
typedef struct R { int val,pos; ll sum; } R;

int n;
int a[MAXN];

R stck[MAXN]; int nstck;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	ll ret=0;
	REP(rep,2) {
		nstck=0;
		//REP(i,n) printf("%d ",a[i]); puts("");
		REP(i,n) {
			while(nstck>0&&stck[nstck-1].val<=a[i]) --nstck;
			int len=nstck==0?i+1:i-stck[nstck-1].pos;
			stck[nstck].val=a[i],stck[nstck].pos=i,stck[nstck].sum=(nstck==0?0LL:stck[nstck-1].sum)+(ll)len*a[i],++nstck;
			ret+=stck[nstck-1].sum;
			//printf("\t%d:",i); REP(i,nstck) printf(" [%d,%d,%lld]",stck[i].val,stck[i].pos,stck[i].sum); puts("");
		}
		REP(i,n) a[i]=-a[i];
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}
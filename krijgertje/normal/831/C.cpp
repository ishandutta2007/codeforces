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
const int MAXQ=2000;

int n,nq;
int a[MAXN];
int asum[MAXN+1];
int o[MAXN];
int b[MAXQ];
set<int> res;

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]);
	asum[0]=0; REP(i,n) asum[i+1]=asum[i]+a[i];
	REP(i,n) o[i]=asum[i+1]; sort(o,o+n);
	sort(a,a+n);
	res.clear();
	REP(i,nq) scanf("%d",&b[i]);

	FORE(i,1,n) {
		int s=b[0]-asum[i];
		//printf("i=%d s=%d\n",i,s);
		bool ok=true;
		REP(j,nq) {
			int want=b[j]-s;
			//printf("want=%d\n",want);
			int idx=lower_bound(o,o+n,want)-o;
			if(idx==n||o[idx]!=want) { ok=false; break; }
		}
		if(ok) res.insert(s);
	}
	printf("%d\n",SZ(res));
}

int main() {
	run();
	return 0;
}
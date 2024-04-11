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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int n;
int a[5000];
int bad[5000],nbad;

int calc(int x) {
	int ret=0;
	REP(i,nbad) while(x%bad[i]==0) { x/=bad[i]; --ret; }
	for(int i=2;i*i<=x;++i) while(x%i==0) { x/=i; ++ret; } if(x!=1) ++ret;
	return ret;
}

void run() {
	scanf("%d%d",&n,&nbad);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,nbad) scanf("%d",&bad[i]);

	int ret=0;
	for(int i=n-1;i>=0;--i) {
		int g=a[0]; FORE(j,1,i) g=gcd(g,a[j]);
		int f=calc(g);
		if(f<=0) REPE(j,i) a[j]/=g;
		ret+=calc(a[i]);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
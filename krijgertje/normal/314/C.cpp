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

const int MOD=1000000007;

int n;
int a[100000];

ll fw[1<<20];
ll get(int x) {
	ll ret=0;
	while(x!=0) {
		ret+=fw[x];
		x-=x&-x;
	}
	return ret%MOD;
}
void inc(int x,ll by) {
	while(x<(1<<20)) {
		fw[x]+=by; if(fw[x]>=MOD) fw[x]-=MOD;
		x+=x&-x;
	}
}

ll last[1000001];


void run(int casenr) {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	
	memset(fw,0,sizeof(fw));
	memset(last,0,sizeof(last));
	ll ret=0;
	REP(i,n) {
		ll sum=get(a[i]);
//		printf("get(%d)=%d\n",a[i],(int)sum);
		ll cur=(1+sum)*a[i]%MOD;
		ll now=cur-last[a[i]]; if(now<0) now+=MOD;
		ret+=now;
		inc(a[i],now);
		last[a[i]]=cur;
	}
	ret%=MOD;
	cout<<ret<<endl;
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
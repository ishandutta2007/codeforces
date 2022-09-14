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

int n,bound;
int a[MAXN+1];
int b[MAXN+100],nb; bool neg;

void run() {
	scanf("%d%d",&n,&bound); REPE(i,n) scanf("%d",&a[i]);

	for(int i=0,c=0;;++i) {
		if(i<=n) c+=a[i];
		b[i]=c%2==0?0:1; c=(c-b[i])/2;
		if(i>n&&(c==0||c==-1)) { nb=i+1; neg=c==-1; break; }
	}
	//REP(i,nb) printf("%d",b[i]); if(neg) printf("..."); puts("");
	int ret=0;
	int frst=0; while(frst<nb&&b[frst]==0) ++frst;
	ll need=neg?1:0; for(int i=nb-1;i>=0;--i) {
		need=2*need-b[i]; if(abs(need)>2*bound) break;
		if(i<=frst&&i<=n&&(i!=n||a[i]+need!=0)&&a[i]+need>=-bound&&a[i]+need<=+bound) ++ret;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
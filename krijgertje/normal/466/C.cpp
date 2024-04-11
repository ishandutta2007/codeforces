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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=500000;

int n;
int a[MAXN];
ll asum[MAXN+1],want1,want2;

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	asum[0]=0; REP(i,n) asum[i+1]=asum[i]+a[i];
	if(asum[n]%3!=0) { printf("%d\n",0); return; }
	want1=asum[n]/3,want2=want1+want1;
	ll ret=0;
	int n1=0;
	FORE(i,1,n-1) {
		if(asum[i]==want2) ret+=n1;
		if(asum[i]==want1) ++n1;
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}
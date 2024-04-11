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

const int MAXN=360;

int n;
int a[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	int l=0,r=0,sum=0,ret=360;
	while(l<n) {
		//printf("%d..%d = %d\n",l,r,sum);
		int cur=abs(360-sum-sum); if(cur<ret) ret=cur;
		if(sum<180) sum+=a[r%n],++r; else sum-=a[l],++l;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
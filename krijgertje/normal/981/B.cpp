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

int na;
pair<int,int> a[MAXN];
int nb;
pair<int,int> b[MAXN];

void run() {
	scanf("%d",&na); REP(i,na) scanf("%d%d",&a[i].first,&a[i].second);
	scanf("%d",&nb); REP(i,nb) scanf("%d%d",&b[i].first,&b[i].second);

	ll ret=0;
	sort(a,a+na); sort(b,b+nb);
	int ai=0,bi=0;
	while(ai<na||bi<nb) {
		int id=min(ai<na?a[ai].first:INT_MAX,bi<nb?b[bi].first:INT_MAX);
		int cur=0;
		if(ai<na&&a[ai].first==id) cur=max(cur,a[ai].second);
		if(bi<nb&&b[bi].first==id) cur=max(cur,b[bi].second);
		ret+=cur;
		if(ai<na&&a[ai].first==id) ++ai;
		if(bi<nb&&b[bi].first==id) ++bi;
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}
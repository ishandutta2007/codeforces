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

int n;
int w[MAXN];
char s[2*MAXN+1];

int ans[2*MAXN];

pair<int,int> o[MAXN];
int stck[MAXN],nstck;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&w[i]); scanf("%s",s);

	REP(i,n) o[i]=MP(w[i],i); sort(o,o+n); nstck=0; int at=0;
	REP(i,2*n) {
		if(s[i]=='0') {
			assert(at<n);
			int idx=o[at++].second;
			stck[nstck++]=idx;
			ans[i]=idx;
		} else {
			assert(nstck>0);
			int idx=stck[--nstck];
			ans[i]=idx;
		}
	}
	REP(i,2*n) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");



}

int main() {
	run();
	return 0;
}
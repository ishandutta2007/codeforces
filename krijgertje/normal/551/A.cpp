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
typedef struct S { int rat,idx; } S;
bool operator<(const S &a,const S &b) { return a.rat>b.rat; }

int n;
S s[MAXN];
int ret[MAXN];


void run() {
	scanf("%d",&n);
	REP(i,n) s[i].idx=i,scanf("%d",&s[i].rat);
	sort(s,s+n);

	int at=0;
	while(at<n) {
		int to=at; while(to<n&&s[at].rat==s[to].rat) ++to;
		FOR(i,at,to) ret[s[i].idx]=at+1;
		at=to;
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}
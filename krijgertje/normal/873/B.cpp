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

int n;
char s[MAXN+1];

int sum[MAXN+1];

pair<int,int> o[MAXN+1];

void run() {
	scanf("%d%s",&n,s);

	sum[0]=0; REP(i,n) sum[i+1]=sum[i]+(s[i]=='0'?-1:+1);
	REPE(i,n) o[i]=MP(sum[i],i); sort(o,o+n+1);
	int ret=0;
	for(int l=0,r=l;l<=n;l=r) {
		while(r<=n&&o[l].first==o[r].first) ++r;
		int cur=o[r-1].second-o[l].second;
		if(cur>ret) ret=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
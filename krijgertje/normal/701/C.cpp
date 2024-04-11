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
const int MAXTYPE=52;

int n;
char s[MAXN+1];
int x[MAXN];
int cnt[MAXTYPE];

int convert(char c) { if(islower(c)) return c-'a'; return 26+c-'A'; }
void run() {
	scanf("%d%s",&n,s);

	REP(i,n) x[i]=convert(s[i]);
	REP(i,MAXTYPE) cnt[i]=0;
	ll all=0,cur=0; REP(i,n) all|=1LL<<x[i];
	int a=0,b=0; int ret=INT_MAX;
	while(a<n) {
		while(b<n&&cur!=all) {
			if(cnt[x[b]]++==0) cur|=1LL<<x[b];
			++b;
		}
		if(cur==all&&b-a<ret) ret=b-a;
		if(--cnt[x[a]]==0) cur&=~(1LL<<x[a]);
		++a;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
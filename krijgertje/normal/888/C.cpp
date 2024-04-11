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

char s[MAXN+1]; int n;

bool any[26]; int mx[26]; int lst[26];

void run() {
	scanf("%s",s); n=strlen(s);
	REP(i,26) any[i]=false;
	REP(i,n) {
		int x=s[i]-'a';
		if(!any[x]) any[x]=true,mx[x]=i,lst[x]=i;
		else mx[x]=max(mx[x],i-lst[x]-1),lst[x]=i;
	}
	REP(x,26) if(any[x]) mx[x]=max(mx[x],n-lst[x]-1);
	int ret=INT_MAX;
	REP(x,26) if(any[x]) ret=min(ret,mx[x]+1);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
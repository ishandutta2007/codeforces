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

const int MAXLEN=200;

char s[MAXLEN+1]; int n;

void run() {
	scanf("%d%s",&n,s); n=strlen(s);
	int ret=0;
	for(int at=0,to=at;at<n;at=to) {
		if(isupper(s[to])) { ++to; continue; }
		while(to<n&&islower(s[to])) ++to;
		int mask=0,cnt=0;
		FOR(i,at,to) { int x=s[i]-'a'; if(((mask>>x)&1)==0) mask|=1<<x,++cnt; }
		ret=max(ret,cnt);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
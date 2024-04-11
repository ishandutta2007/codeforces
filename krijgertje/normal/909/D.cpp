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

const int MAXN=1000000;

char s[MAXN+1]; int n;


pair<char,int> a[MAXN]; int na;
pair<char,int> b[MAXN]; int nb;


void run() {
	scanf("%s",s); n=strlen(s);

	na=0; for(int l=0,r=l;l<n;l=r) { while(r<n&&s[l]==s[r]) ++r; a[na++]=MP(s[l],r-l); }
	int ret=0;
	while(na>=2) {
		nb=0; REP(i,na) { int ncnt=a[i].second-(i==0||i==na-1?1:2); if(ncnt>0) b[nb++]=MP(a[i].first,ncnt); }
		na=0; REP(i,nb) if(na==0||b[i].first!=a[na-1].first) a[na++]=b[i]; else a[na-1].second+=b[i].second;
		++ret;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
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
char mn[MAXN];
char stck[MAXN+1]; int nstck;
char ret[MAXN+1]; int nret;

void run() {
	scanf("%s",s); n=strlen(s);
	mn[n-1]=s[n-1]; for(int i=n-2;i>=0;--i) mn[i]=min(s[i],mn[i+1]);
	nret=nstck=0;
	REP(i,n) {
		while(nstck>0&&stck[nstck-1]<=mn[i]) ret[nret++]=stck[--nstck];
		stck[nstck++]=s[i];
	}
	while(nstck>0) ret[nret++]=stck[--nstck]; ret[nret]='\0';
	printf("%s\n",ret);
}

int main() {
	run();
	return 0;
}
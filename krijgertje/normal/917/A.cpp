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

const int MAXN=5000;

char s[MAXN+1]; int n;

int a[MAXN],b[MAXN];

void run() {
	scanf("%s",s); n=strlen(s);
	REP(i,n) {
		int bal=0;
		a[i]=i;
		while(a[i]<n&&(bal>0||s[a[i]]!=')')) { bal+=s[a[i]]==')'?-1:+1; ++a[i]; }
	}
	REP(i,n) {
		int bal=0;
		b[i]=i+1;
		while(b[i]-1>=0&&(bal>0||s[b[i]-1]!='(')) { bal+=s[b[i]-1]=='('?-1:+1; --b[i]; }
	}
	//printf("a:"); REP(i,n) printf(" %d",a[i]); puts("");
	//printf("b:"); REP(i,n) printf(" %d",b[i]); puts("");
	int ret=0; REP(i,n) FORE(j,i,n) if((j-i+1)%2==0&&a[i]>j&&b[j]<=i) ++ret; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
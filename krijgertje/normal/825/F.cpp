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

const int MAXLEN=8000;

char s[MAXLEN+1]; int slen;

int dp[MAXLEN+1]; // dp[i] = minimum length of compressed version of s[i..n)
int d[MAXLEN+1]; // d[i] = length of decimal representation of i

int p[MAXLEN+1]; // p[i] = period of string of length i
void calc(char *t,int tlen) {
	p[0]=p[1]=0;
	FORE(i,2,tlen) {
		char c=t[i-1];
		p[i]=p[i-1];
		while(p[i]!=0&&t[p[i]]!=c) p[i]=p[p[i]];
		if(t[p[i]]==c) ++p[i];
	}
	//printf("%s:",t); REPE(i,tlen) printf(" %d",p[i]); puts("");
}


void run() {
	scanf("%s",s); slen=strlen(s);
	d[0]=0; FORE(i,1,slen) d[i]=1+d[i/10];

	dp[slen]=0;
	for(int i=slen-1;i>=0;--i) {
		int plen=slen-i;
		calc(s+i,plen);
		dp[i]=INT_MAX;
		FORE(j,1,plen) {
			int cur;
			if(p[j]!=0&&j%(j-p[j])==0) {
				cur=d[j/(j-p[j])]+(j-p[j])+dp[i+j];
			} else {
				cur=d[1]+j+dp[i+j];
			}
			if(cur<dp[i]) dp[i]=cur;
		}
	}
	printf("%d\n",dp[0]);
}

int main() {
	run();
	return 0;
}
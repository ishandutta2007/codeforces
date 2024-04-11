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

int n;
int sum[300];

char last[601]; int lastlen,lastsum;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&sum[i]);
	lastlen=1; last[0]='0'; last[lastlen]='\0'; lastsum=0;
	REP(i,n) {
		int len=lastlen;
		while(sum[i]>9*len) ++len;
		bool ok=false;
		if(len==lastlen) {
			int remsum=lastsum;
			for(int j=len-1;j>=0;--j) {
				int cur=last[j]-'0'; remsum-=cur;
				int rem=sum[i]-remsum;
				int lx=max(cur+1,rem-9*(len-j-1));
				int hx=min(9,rem);
				if(lx<=hx) {
					ok=true; lastsum=sum[i];
					last[j]='0'+lx; rem-=lx;
					for(++j;j<len;++j) { int x=max(0,rem-9*(len-j-1)); rem-=x; last[j]='0'+x; }
					break;
				}
			}
			if(!ok) ++len;
		}
		if(!ok) {
			lastlen=len; lastsum=sum[i]; last[len]='\0';
			int rem=sum[i];
			int sx=max(1,rem-9*(len-1)); rem-=sx; last[0]='0'+sx;
			FOR(j,1,len) { int x=max(0,rem-9*(len-j-1)); rem-=x; last[j]='0'+x; }
		}
		printf("%s\n",last);
	}
}

int main() {
	run();
	return 0;
}
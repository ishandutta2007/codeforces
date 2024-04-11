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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n;
char s[100000][9];

void setmin(int i) {
	int len=strlen(s[i]);
	REP(j,len) if(s[i][j]=='?') {
		s[i][j]=j==0?'1':'0';
	}
}

bool calc() {
	setmin(0);
	FOR(i,1,n) {
		int len=strlen(s[i]),plen=strlen(s[i-1]);
		if(len<plen) return false; if(len>plen) { setmin(i); continue; }

		int bestdiff=-1;
		for(int j=len-1;j>=0;--j) {
			int a=s[i-1][j]-'0';
			if(s[i][j]!='?') {
				int b=s[i][j]-'0';
				if(b<a) bestdiff=-1; else if(b>a) bestdiff=j;
			} else {
				if(bestdiff==-1&&a!=9) bestdiff=j;
			}
		}
		if(bestdiff==-1) return false;
		REP(j,len) if(s[i][j]=='?') {
			s[i][j]=j<bestdiff?s[i-1][j]:j>bestdiff?'0':s[i-1][j]+1;
		}
	}
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%s",s[i]);
	if(!calc()) {
		printf("NO\n");
	} else {
		printf("YES\n");
		REP(i,n) printf("%s\n",s[i]);
	}

}

int main() {
	run();
	return 0;
}
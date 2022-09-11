#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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

const int MAXLEN=100;

char s[MAXLEN+1]; int slen;
char t[MAXLEN+1]; int tlen;
char p[MAXLEN+1]; int plen;

int rem[26];

bool solve() {
	REP(i,26) rem[i]=0; REP(i,plen) ++rem[p[i]-'a'];
	int at=0;
	REP(i,slen) {
		while(at<tlen&&t[at]!=s[i]) {
			int x=t[at++]-'a';
			if(rem[x]==0) return false; else --rem[x];
		}
		if(at>=tlen) return false;
		++at;
	}
	while(at<tlen) {
		int x=t[at++]-'a';
		if(rem[x]==0) return false; else --rem[x];
	}
	return true;
}

void run() {
	scanf("%s",s); slen=strlen(s);
	scanf("%s",t); tlen=strlen(t);
	scanf("%s",p); plen=strlen(p);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}
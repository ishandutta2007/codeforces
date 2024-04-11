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

const int MAXQ=100;
const int MAXLEN=MAXQ*4+7; 

char s[MAXLEN+3]; int slen;

int pos[MAXQ],neg[MAXQ],npos,nneg;

void run() {
	gets(s); slen=strlen(s);
	npos=0,nneg=0; int n=0;
	for(int i=0;i<slen;i+=4) {
		if(s[i]=='?') { if(i==0||s[i-2]=='+') pos[npos++]=1; else neg[nneg++]=1; continue; }
		while(isdigit(s[i])) n=n*10+(s[i++]-'0');
	}
	int res=npos-nneg;
	REP(i,npos) if(res<n) { int cur=min(n-res,n-pos[i]); pos[i]+=cur; res+=cur; }
	REP(i,nneg) if(res>n) { int cur=min(res-n,n-neg[i]); neg[i]+=cur; res-=cur; }
	if(res!=n) { printf("Impossible\n"); return; }
	printf("Possible\n");
	for(int i=0;i<slen;++i) {
		if(s[i]!='?') { printf("%c",s[i]); continue; }
		if(i==0||s[i-2]=='+') printf("%d",pos[--npos]); else printf("%d",neg[--nneg]);
	}
}

int main() {
	run();
	return 0;
}
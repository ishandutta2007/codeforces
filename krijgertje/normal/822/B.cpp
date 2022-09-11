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

const int MAXLEN=1000;

int slen,tlen;
char s[MAXLEN+1],t[MAXLEN+1];

void run() {
	scanf("%d%d",&slen,&tlen); scanf("%s%s",s,t);
	int ret=slen+1,retidx=-1;
	REPE(i,tlen-slen) {
		int match=0; REP(j,slen) if(s[j]==t[i+j]) ++match;
		int cur=slen-match; if(cur<ret) ret=cur,retidx=i;
	}
	vector<int> res;
	REP(j,slen) if(s[j]!=t[retidx+j]) res.PB(j+1);
	printf("%d\n",ret);
	REPSZ(i,res) { if(i!=0) printf(" "); printf("%d",res[i]); } puts("");
}

int main() {
	run();
	return 0;
}
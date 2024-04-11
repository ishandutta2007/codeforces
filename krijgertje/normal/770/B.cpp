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

const int MAXDIG=19;

ll x;
char s[MAXDIG+1]; int slen;

void run() {
	scanf("%lld",&x);
	slen=0; for(ll y=x;y!=0;y/=10) s[slen++]='0'+y%10; reverse(s,s+slen);
	bool suff9=true; FOR(i,1,slen) if(s[i]!='9') suff9=false;
	int cnt8=0,suff98=true; FOR(i,1,slen) if(s[i]=='8') ++cnt8; else if(s[i]!='9') suff98=false;
	if(!suff9&&(!suff98||cnt8>1)&&slen!=1) {
		int pos=0; while(pos+1<slen&&s[pos+1]=='9') ++pos;
		--s[pos]; FOR(i,pos+1,slen) s[i]='9';
		if(s[0]=='0') { REP(i,slen-1) s[i]=s[i+1]; s[--slen]='\0'; }
	}
	ll ret=0; REP(i,slen) ret=10*ret+s[i]-'0'; printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}
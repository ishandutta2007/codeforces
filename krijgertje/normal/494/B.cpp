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

const int MOD=1000000007;
char s[100001]; int slen;
char t[100001]; int tlen;

int nxt[100001]; // nxt[i]=j --> for first i characters of t the max j such that it ends with first j characters of t
bool matches[100000];
int ways[100000]; // ways[i] = # ways of splitting the first i characters, so that the last is used
int sumways[100000]; // sumways[i] = sum(ways[j],j<i)
int sumways2[100000]; // sumways2[i] = sum(sumways[j],j<=i)

void run() {
	scanf("%s%s",s,t); slen=strlen(s); tlen=strlen(t);

	nxt[0]=nxt[1]=0;
	FORE(i,2,tlen) {
		int at=nxt[i-1];
		while(at!=0&&t[at]!=t[i-1]) at=nxt[at];
		if(t[at]==t[i-1]) ++at;
		nxt[i]=at;
	}
	{
		int at=0;
		REP(i,slen) {
			while(at!=0&&s[i]!=t[at]) at=nxt[at];
			if(s[i]==t[at]) ++at;
			matches[i]=at==tlen;
			if(at==tlen) at=nxt[at];
		}
		//REP(i,slen) printf("%c",matches[i]?'V':'.'); puts("");
	}

	REP(i,slen) {
		sumways[i]=i==0?0:(sumways[i-1]+ways[i-1])%MOD;
		sumways2[i]=i==0?sumways[i]:(sumways[i]+sumways2[i-1])%MOD;
		if(matches[i]) {
			ways[i]=i-tlen+2;
			ways[i]+=sumways2[i-tlen+1];
			ways[i]%=MOD;
		} else {
			ways[i]=i==0?0:ways[i-1];
		}
		//printf("%d: %d\n",i,ways[i]);
	}

	int ret=0; REP(i,slen) ret=(ret+ways[i])%MOD; printf("%d\n",ret);


}

int main() {
	run();
	return 0;
}
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

const int MAXLEN=1000;

int slen,plen,nq;
char s[MAXLEN+1],p[MAXLEN+1];

bool match[MAXLEN];
int sum[MAXLEN+1];

void run() {
	scanf("%d%d%d",&slen,&plen,&nq); scanf("%s%s",s,p);

	memset(match,false,sizeof(match));
	REPE(i,slen-plen) {
		bool ok=true;
		REP(j,plen) if(s[i+j]!=p[j]) ok=false;
		match[i]=ok;
	}
	sum[0]=0; REP(i,slen) sum[i+1]=sum[i]+(match[i]?1:0);
	REP(i,nq) {
		int l,r; scanf("%d%d",&l,&r); --l;
		int ans;
		if(r-l>=plen) {
			ans=sum[r-plen+1]-sum[l];
		} else {
			ans=0;
		}
		printf("%d\n",ans);
	}
}

int main() {
	run();
	return 0;
}
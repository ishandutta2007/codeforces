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

char s[1000001]; int slen;
int a,b;

int lrem[1000000];
int hrem[1000000];

void run() {
	scanf("%s",s); slen=strlen(s);
	scanf("%d%d",&a,&b);
	lrem[0]=(s[0]-'0')%a; FOR(i,1,slen) lrem[i]=(lrem[i-1]*10+s[i]-'0')%a;
	hrem[slen-1]=(s[slen-1]-'0')%b; for(int i=slen-2,mult=10;i>=0;--i,mult=mult*10%b) hrem[i]=((s[i]-'0')*mult+hrem[i+1])%b;
	//REP(i,slen) printf("%d %d\n",lrem[i],hrem[i]);
	REP(i,slen-1) if(lrem[i]==0&&hrem[i+1]==0&&s[i+1]!='0') {
		printf("YES\n");
		REPE(j,i) printf("%c",s[j]); puts("");
		FOR(j,i+1,slen) printf("%c",s[j]); puts("");
		return;
	}
	printf("NO\n");
}

int main() {
	run();
	return 0;
}
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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

char s[1001];
int sheetlen;

int need[26];
char ans[1001];

bool can(int x) {
//	printf("testing %d\n",x);
	int at=0;
	REP(i,26) {
		if(need[i]==0) continue;
		int cur=(need[i]+x-1)/x;
		if(at+cur>sheetlen) return false;
		REP(j,cur) ans[at++]='a'+i;
	}
	while(at<sheetlen) ans[at++]='z'; ans[sheetlen]='\0'; return true;
}

void run(int casenr) {
	scanf("%s%d",s,&sheetlen);
	memset(need,0,sizeof(need)); for(int i=0;s[i]!='\0';++i) need[s[i]-'a']++;

	int l=0,h=1000; // (l,h]
	if(!can(h)) { printf("-1\n"); return; }
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(can(m)) h=m; else l=m;
	}
	assert(can(h));
	printf("%d\n",h);
	printf("%s\n",ans);
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
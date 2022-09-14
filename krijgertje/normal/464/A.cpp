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

int n,k; char s[1001];

bool finish(int at) {
	if(at>=n) return true;
	REP(i,k) {
		if(at-1>=0&&s[at-1]=='a'+i) continue;
		if(at-2>=0&&s[at-2]=='a'+i) continue;
		s[at]='a'+i; return finish(at+1);
	}
	return false;
}

void run() {
	scanf("%d%d%s",&n,&k,s);
	if(k==1||k==2&&n>=3) { printf("NO\n"); return; }
	for(int i=n-1;i>=0;--i) {
		while(true) {
			s[i]++; if(s[i]>'a'+k-1) break;
			if(i-1>=0&&s[i]==s[i-1]) continue;
			if(i-2>=0&&s[i]==s[i-2]) continue;
			assert(finish(i+1));
			printf("%s\n",s); return;
		}
	}
	printf("NO\n");
}

int main() {
	run();
	return 0;
}
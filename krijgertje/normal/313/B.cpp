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

int n;
char s[100002];
int cnt[100000];

void run(int casenr) {
	scanf("%s",s); n=strlen(s);
	cnt[0]=0; FOR(i,1,n) cnt[i]=cnt[i-1]+(s[i]==s[i-1]?1:0);
	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		printf("%d\n",cnt[b]-cnt[a]);
	}
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
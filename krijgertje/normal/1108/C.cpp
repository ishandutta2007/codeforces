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

const int MAXN=200000;

int n;
char s[MAXN+1];
char ans[MAXN+1];

int solve() {
	int ret=INT_MAX;
	char p[4]="BGR";
	ans[0]='?'; ans[1]='\0';
	do {
		int cur=0; REP(i,n) if(s[i]!=p[i%3]) ++cur;
		if(cur<ret) { ret=cur; REP(i,n) ans[i]=p[i%3]; ans[n]='\0'; }
	} while(next_permutation(p,p+3));
	return ret;
}

void run() {
	scanf("%d",&n);
	scanf("%s",s);
	printf("%d\n",solve());
	printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}
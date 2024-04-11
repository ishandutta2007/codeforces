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

const int MAXLEN=200000;

int slen,n;
char s[MAXLEN+1];
int p[26],r[26];

void run() {
	scanf("%d%d%s",&slen,&n,s);
	REP(i,26) r[i]=i;
	REP(i,n) {
		char a,b; scanf(" %c %c",&a,&b); int x=a-'a',y=b-'a';
		swap(r[x],r[y]);
	}
	REP(i,26) p[r[i]]=i;
	REP(i,slen) printf("%c",'a'+p[s[i]-'a']); puts("");
}

int main() {
	run();
	return 0;
}
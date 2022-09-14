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

char s[200001]; int slen;
char t[200001]; int tlen;

int want[26][2];
int have[26][2];

void run() {
	scanf("%s",s); slen=strlen(s);
	scanf("%s",t); tlen=strlen(t);
	memset(want,0,sizeof(want)); REP(i,slen) if('A'<=s[i]&&s[i]<='Z') ++want[s[i]-'A'][0]; else if('a'<=s[i]&&s[i]<='z') ++want[s[i]-'a'][1];
	memset(have,0,sizeof(have)); REP(i,tlen) if('A'<=t[i]&&t[i]<='Z') ++have[t[i]-'A'][0]; else if('a'<=t[i]&&t[i]<='z') ++have[t[i]-'a'][1];
	int yay=0,whoops=0;
	REP(i,26) {
		REP(j,2) { int cur=min(want[i][j],have[i][j]); yay+=cur; want[i][j]-=cur; have[i][j]-=cur; }
		REP(j,2) { int cur=min(want[i][j],have[i][1-j]); whoops+=cur; want[i][j]-=cur; have[i][1-j]-=cur; }
	}
	printf("%d %d\n",yay,whoops);
}

int main() {
	run();
	return 0;
}
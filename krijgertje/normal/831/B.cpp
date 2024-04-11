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

const int MAXLEN=1000;

char a[26+1];
char b[26+1];
char s[MAXLEN+1]; int slen;
char ret[MAXLEN+1];

char mp[26];

void run() {
	scanf("%s%s%s",a,b,s); slen=strlen(s);
	memset(mp,'?',sizeof(mp)); REP(i,26) mp[a[i]-'a']=b[i];

	REP(i,slen) {
		char c=s[i],nc;
		if(!isalpha(c)) nc=c; else if(islower(c)) nc=mp[c-'a']; else if(isupper(c)) nc=mp[c-'A']+'A'-'a'; else assert(false);
		ret[i]=nc;
	}
	ret[slen]='\0';
	printf("%s\n",ret);
}

int main() {
	run();
	return 0;
}
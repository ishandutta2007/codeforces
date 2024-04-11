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

const int MAXLEN=7;

char s[MAXLEN+1]; int len;

void run() {
	scanf("%s",s); len=strlen(s);
	int ret=0;
	for(int at=0,to=at;at<len;at=to) {
		while(to<len&&(to==at||to-at==1&&s[at]=='1')) ++to;
		if(s[at]=='A') ++ret; else { int cur=0; while(at<to) cur=10*cur+(s[at++]-'0'); ret+=cur; }
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
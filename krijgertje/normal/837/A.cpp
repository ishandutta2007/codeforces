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

const int MAXLEN=200;

int n;
char s[MAXLEN+1];

void run() {
	gets(s); sscanf(s,"%d",&n);
	gets(s);
	//printf("n=%d s='%s'\n",n,s);
	int ret=0;
	for(int at=0,to=at;at<n;at=to) {
		++to; if(s[at]==' ') continue;
		while(to<n&&s[to]!=' ') ++to;
		int cur=0; FOR(i,at,to) if(isupper(s[i])) ++cur; if(cur>ret) ret=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
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

const int MAXLEN=100000;

char s[MAXLEN+1]; int slen;

int cnt[26];
int pos[26],npos;

bool solve() {
	memset(cnt,0,sizeof(cnt)); REP(i,slen) ++cnt[s[i]-'a'];
	npos=0; REP(i,26) if(cnt[i]>0) pos[npos++]=cnt[i]; sort(pos,pos+npos);
	if(npos==2) {
		return pos[0]>=2;
	}
	if(npos==3) {
		return slen>=4;
	}
	if(npos==4) {
		return true;
	}
	return false;
}

void run() {
	scanf("%s",s); slen=strlen(s);
	printf("%s\n",solve()?"Yes":"No");
}

int main() {
	run();
	return 0;
}
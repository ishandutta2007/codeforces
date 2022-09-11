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

const int MAXN=300000;
const int MAXLEN=300000;

int n;
char s[MAXLEN+1];

map<pair<int,int>,int> cnt;

pair<int,int> calc() {
	int bal=0,minbal=0;
	for(int i=0;s[i]!='\0';++i) {
		if(s[i]=='(') ++bal; else if(s[i]==')') --bal;
		minbal=min(minbal,bal);
	}
	return MP(-minbal,bal-minbal);
}

void run() {
	scanf("%d",&n);
	REP(i,n) {
		scanf("%s",s);
		pair<int,int> cur=calc();
		//printf("%s = (%d,%d)\n",s,cur.first,cur.second);
		++cnt[cur];
	}

	ll ret=0;
	for(auto it=cnt.begin();it!=cnt.end();++it) {
		int pre=it->first.first,suf=it->first.second,cur=it->second;
		if(pre!=0) continue;
		ret+=(ll)cur*cnt[MP(suf,0)];
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}
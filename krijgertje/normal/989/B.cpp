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

const int MAXLEN=2000;

int slen,per;
char s[MAXLEN+1];

char ans[MAXLEN+1];

bool solve() {
	bool globfound=false;
	REPE(i,slen) if(ans[i]=s[i]);
	REP(i,per) {
		bool have0=false,have1=false; int cntdot=0;
		for(int j=i;j<slen;j+=per) {
			char c=s[j];
			if(c=='.') ++cntdot; else if(c=='0') have0=true; else if(c=='1') have1=true;
		}
		bool found=false;
		if(have0&&have1) { found=true; for(int j=i;j<slen;j+=per) if(s[j]=='.') ans[j]='0'; }
		if(!found&&have0&&cntdot>=1) { found=true; for(int j=i;j<slen;j+=per) if(s[j]=='.') ans[j]='1'; }
		if(!found&&have1&&cntdot>=1) { found=true; for(int j=i;j<slen;j+=per) if(s[j]=='.') ans[j]='0'; }
		if(!found&&cntdot>=2) { found=true; bool fst=true; for(int j=i;j<slen;j+=per) if(s[j]=='.') if(fst) ans[j]='0',fst=false; else ans[j]='1'; }
		if(!found) { assert(cntdot==0||!have0&&!have1&&cntdot==1); for(int j=i;j<slen;j+=per) if(s[j]=='.') ans[j]='0'; }
		if(found) globfound=true;
	}
	return globfound;
}

void run() {
	scanf("%d%d",&slen,&per); scanf("%s",s);
	if(!solve()) { printf("No\n"); return; }
	printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}
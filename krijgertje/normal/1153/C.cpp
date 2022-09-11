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

const int MAXLEN=300000;

int slen;
char s[MAXLEN+1];
char ans[MAXLEN+1];

bool solve() {
	int nopen=0,nclose=0; REP(i,slen) if(s[i]=='(') ++nopen; else if(s[i]==')') ++nclose;
	if(slen%2!=0||nopen>slen/2||nclose>slen/2) return false;
	int rem=slen/2-nopen; REP(i,slen) if(s[i]!='?') ans[i]=s[i]; else if(rem>0) ans[i]='(',--rem; else ans[i]=')';
	int bal=0;
	REP(i,slen) {
		bal+=(ans[i]=='('?+1:-1);
		if(bal<0||i!=slen-1&&bal==0) return false;
	}
	return true;
}

void run() {
	scanf("%d",&slen);
	scanf("%s",s);
	if(!solve()) { printf(":("); return; }
	printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}
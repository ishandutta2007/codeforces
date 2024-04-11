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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN=300000;

int a,b;
char s[MAXLEN+1]; int slen;

bool solve() {
	int singles=0;
	int force=-1;
	for(int l=0,r=l;l<slen;l=r) {
		while(r<slen&&s[r]==s[l]) ++r;
		if(s[l]!='.') continue;
		int len=r-l;
		if(len<b) continue;
		if(len<a) return false;
		if(len<2*b) { ++singles; continue; }
		if(force!=-1) return false; else force=len;
	}
	if(force==-1) return singles%2==1;
	REPE(l,force-a) {
		int r=force-a-l;
		int cursingles=singles; bool ok=true;
		if(l>=b) { if(l<a||l>=2*b) ok=false; else ++cursingles; }
		if(r>=b) { if(r<a||r>=2*b) ok=false; else ++cursingles; }
		if(ok&&cursingles%2==0) return true;
	}
	return false;
}

void run() {
	scanf("%d%d",&a,&b);
	scanf("%s",s); slen=strlen(s);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}
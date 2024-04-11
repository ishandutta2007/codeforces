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

const int MAXLEN=200000;

int slen;
char s[MAXLEN+1];
int mp[10];
char ans[MAXLEN+1];

void solve() {
	int state=0;
	REP(i,slen) {
		char a=s[i],b='0'+mp[a-'0'];
		if(state==0) {
			ans[i]=max(a,b); if(b>a) state=1;
		} else if(state==1) {
			ans[i]=max(a,b); if(a>b) state=2;
		} else {
			ans[i]=s[i];
		}
	}
	ans[slen]='\0';
}

void run() {
	scanf("%d",&slen);
	scanf("%s",s);
	FORE(i,1,9) scanf("%d",&mp[i]);
	solve();
	printf("%s\n",ans);

}

int main() {
	run();
	return 0;
}
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

const int MAXLEN=100;

int len;
char parts[2*MAXLEN-2][MAXLEN+1];
char ans[2*MAXLEN-2+1];

bool havepref[MAXLEN],havesuff[MAXLEN];
char s[MAXLEN+1];


bool solve(int a,int b) {
	REP(i,len-1) s[i]=parts[a][i]; s[len-1]=parts[b][len-2]; s[len]='\0';
	FORE(i,1,len-1) havepref[i]=havesuff[i]=false;
	REP(i,2*len-2) {
		int plen=strlen(parts[i]);
		bool canpref=true; REP(j,plen) if(parts[i][j]!=s[j]) canpref=false;
		bool cansuff=true; REP(j,plen) if(parts[i][j]!=s[len-plen+j]) cansuff=false;
		if(!havepref[plen]&&canpref) { ans[i]='P'; havepref[plen]=true; continue; }
		if(!havesuff[plen]&&cansuff) { ans[i]='S'; havesuff[plen]=true; continue; }
		return false;
	}
	ans[2*len-2]='\0'; return true;
}

void solve() {
	vector<int> idx; REP(i,2*len-2) if(strlen(parts[i])==len-1) idx.PB(i); assert(SZ(idx)==2);
	if(solve(idx[0],idx[1])) return;
	if(solve(idx[1],idx[0])) return;
	assert(false);
}

void run() {
	scanf("%d",&len);
	REP(i,2*len-2) scanf("%s",parts[i]);
	solve();
	printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}
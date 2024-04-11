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

const int MAXN=500000;
const int MAXLEN=500000;

int n;
char s[MAXLEN+1];
int len[MAXN];
int off[MAXN+1];
int nsame[MAXN-1];
bool oklonger[MAXN-1];
int res[MAXN];

void run() {
	scanf("%d",&n);
	off[0]=0; REP(i,n) { char hash; scanf(" %c%s",&hash,s+off[i]); len[i]=strlen(s+off[i]); off[i+1]=off[i]+len[i]; }
	//printf("%s\n",s);
	REP(i,n-1) { nsame[i]=0; while(nsame[i]+1<=len[i]&&nsame[i]+1<=len[i+1]&&s[off[i]+nsame[i]]==s[off[i+1]+nsame[i]]) ++nsame[i]; oklonger[i]=nsame[i]<len[i]&&nsame[i]<len[i+1]&&s[off[i]+nsame[i]]<s[off[i+1]+nsame[i]]; }
	//REP(i,n-1) printf("%d: %d %c\n",i,nsame[i],oklonger[i]?'V':'-');
	res[n-1]=len[n-1];
	for(int i=n-2;i>=0;--i) {
		if(res[i+1]<=nsame[i]) res[i]=min(res[i+1],len[i]); else res[i]=oklonger[i]?len[i]:nsame[i];
	}
	REP(i,n) { printf("#"); REP(j,res[i]) printf("%c",s[off[i]+j]); puts(""); }

}

int main() {
	run();
	return 0;
}
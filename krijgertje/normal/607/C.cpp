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

const int MAXN=1000000;

char a[MAXN+1],b[MAXN+1]; int n;
char s[2*MAXN+2]; int ns;
int nxt[2*MAXN+2]; // nxt[i]==length of longest proper prefix of s[0..i-1] that is also suffix
char inv(char c) { return c=='N'?'S':c=='S'?'N':c=='W'?'E':c=='E'?'W':'?'; }


void run() {
	scanf("%d%s%s",&n,a,b);
	ns=0; for(int i=n-2;i>=0;--i) s[ns++]=a[i]; s[ns++]='#'; REP(i,n-1) s[ns++]=inv(b[i]); s[ns]='\0'; //printf("%s\n",s);

	nxt[0]=nxt[1]=0; FORE(i,2,ns) { nxt[i]=nxt[i-1]; while(nxt[i]!=0&&s[i-1]!=s[nxt[i]]) nxt[i]=nxt[nxt[i]]; if(s[i-1]==s[nxt[i]]) ++nxt[i]; }
	//REPE(i,ns) printf("%d ",nxt[i]); puts("");
	printf("%s\n",nxt[ns]==0?"YES":"NO");
}

int main() {
	run();
	return 0;
}
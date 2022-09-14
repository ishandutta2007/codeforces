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

int n;
char sa[MAXN+1];
char sb[MAXN+1];
char ret[MAXN+1];

int a[26],b[26];
int getmn(int *c) { for(int i=0;i<26;++i) if(c[i]>0) return i; return -1; }
int getmx(int *c) { for(int i=25;i>=0;--i) if(c[i]>0) return i; return -1; }

void run() {
	scanf("%s%s",sa,sb); n=strlen(sa);
	memset(a,0,sizeof(a)); REP(i,n) a[sa[i]-'a']++; { int left=(n+1)/2; REP(i,26) { int cur=min(left,a[i]); a[i]=cur; left-=cur; } }
	memset(b,0,sizeof(b)); REP(i,n) b[sb[i]-'a']++; { int left=n/2; for(int i=25;i>=0;--i) { int cur=min(left,b[i]); b[i]=cur; left-=cur; } }
	REP(i,n) ret[i]='?'; ret[n]='\0';
	int l=0,h=n-1;
	REP(i,n) {
		if(i%2==0) {
			int mn=getmn(a),mx=getmx(b),ot=getmx(a);
			if(mn<mx) ret[l++]='a'+mn,--a[mn]; else ret[h--]='a'+ot,--a[ot];
		} else {
			int mn=getmn(a),mx=getmx(b),ot=getmn(b);
			if(mn<mx) ret[l++]='a'+mx,--b[mx]; else ret[h--]='a'+ot,--b[ot];
		}
	}
	printf("%s\n",ret);
}

int main() {
	run();
	return 0;
}
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

const int MAXLEN=200000;

char s[MAXLEN+1]; int len;
char t[MAXLEN+1];

int cnt[10];
int odd[10],nodd;

void run() {
	scanf("%s",s); len=strlen(s);

	REP(i,10) cnt[i]=0;
	REP(i,len) ++cnt[s[i]-'0'];
	for(int i=len-1;i>=0;--i) {
		--cnt[s[i]-'0'];
		for(int j=s[i]-'0'-1;j>=0;--j) {
			if(i==0&&j==0) continue;
			++cnt[j];
			nodd=0; REP(k,10) if(cnt[k]%2==1) odd[nodd++]=k;
			int rem=len-i-1;
			assert(nodd%2==rem%2);
			if(nodd<=rem) {
				REP(k,i) t[k]=s[k]; t[i]='0'+j; REP(k,rem-nodd) t[i+1+k]='9'; REP(k,nodd) t[i+1+rem-nodd+k]='0'+odd[nodd-k-1]; t[len]='\0';
				printf("%s\n",t); return;
			}
			--cnt[j];
		}
	}
	REP(k,len-2) t[k]='9'; t[len-2]='\0';
	printf("%s\n",t);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}
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

const int MAXWORD=100000;
const int MAXSUMLEN=1000000;

int nword;
int off[MAXWORD+1],len[MAXWORD];
char s[MAXSUMLEN+1];
char ans[MAXSUMLEN+1]; int anslen;

char pat[2*MAXSUMLEN+1+1]; int patlen;
int kmp[2*MAXSUMLEN+1+1]; // kmp[i] = longest proper prefix of pat[0..i) that is also a prefix

int calcpat() {
	//printf("pat=%s\n",pat);
	kmp[0]=kmp[1]=0; FORE(i,2,patlen) { int cur=kmp[i-1]; while(cur>0&&pat[cur]!=pat[i-1]) cur=kmp[cur]; if(pat[cur]==pat[i-1]) ++cur; kmp[i]=cur; }
	//printf("kmp:"); REPE(i,patlen) printf(" %d",kmp[i]); puts("");
	return kmp[patlen];
}

void solve() {
	anslen=0;
	REP(i,nword) {
		int preflen=min(anslen,len[i]);
		patlen=0; REP(j,len[i]) pat[patlen++]=s[off[i]+j]; pat[patlen++]='$'; REP(j,preflen) pat[patlen++]=ans[anslen-preflen+j]; pat[patlen]='\0';
		int border=calcpat();
		FOR(j,border,len[i]) ans[anslen++]=s[off[i]+j];
	}
	ans[anslen]='\0';
}

void run() {
	scanf("%d",&nword);
	off[0]=0; REP(i,nword) { scanf("%s",s+off[i]); len[i]=strlen(s+off[i]); off[i+1]=off[i]+len[i]; }
	solve();
	printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}
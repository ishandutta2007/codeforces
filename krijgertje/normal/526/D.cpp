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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN=1000000;

char s[MAXLEN+1]; int slen,k;

int nxt[MAXLEN+1]; //nxt[i]=length of longest proper suffix of 0..i+1 that is also a prefix


bool ok(int len,int plen) {
	if(k==1) return true;
	if(2*plen<len) return false;
	int x=len-plen;
	int cnt=len/x,rem=len%x;
	return cnt/k>=cnt%k+(rem>0?1:0);
}

void run() {
	scanf("%d%d%s",&slen,&k,s);

	nxt[0]=nxt[1]=0;
	FORE(i,2,slen) {
		nxt[i]=nxt[i-1];
		while(nxt[i]!=0&&s[nxt[i]]!=s[i-1]) nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]]==s[i-1]) ++nxt[i];
	}
	//printf("nxt:"); REPE(i,slen) printf(" %d",nxt[i]); puts("");

	FORE(i,1,slen) printf("%c",ok(i,nxt[i])?'1':'0'); puts("");
}

int main() {
	run();
	return 0;
}
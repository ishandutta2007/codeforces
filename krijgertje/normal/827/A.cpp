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

const int MAXN=100000;
const int MAXLEN=1000000;
const int MAXPOS=1000000;
const int MAXRET=MAXPOS+MAXLEN;
typedef struct Z { int pat,idx,len; } Z;

int n;
char s[MAXLEN+1];
int off[MAXN+1],len[MAXN];

Z z[MAXRET+1];
char ret[MAXRET+1]; int nret;


void run() {
	scanf("%d",&n);
	REPE(i,MAXRET) z[i].pat=-1,z[i].idx=-1,z[i].len=0;
	off[0]=0; nret=0;
	REP(i,n) {
		scanf("%s",s+off[i]); len[i]=strlen(s+off[i]); off[i+1]=off[i]+len[i];
		int k; scanf("%d",&k); REP(j,k) { int pos; scanf("%d",&pos); --pos; if(len[i]>z[pos].len) z[pos].pat=i,z[pos].idx=0,z[pos].len=len[i]; if(pos+len[i]>nret) nret=pos+len[i]; }
	}
	REP(i,nret) {
		if(z[i].pat!=-1) {
			ret[i]=s[off[z[i].pat]+z[i].idx];
			if(z[i].len-1>z[i+1].len) z[i+1].pat=z[i].pat,z[i+1].idx=z[i].idx+1,z[i+1].len=z[i].len-1;
		} else {
			ret[i]='a';
		}
	}
	ret[nret]='\0';
	printf("%s\n",ret);

}

int main() {
	run();
	return 0;
}
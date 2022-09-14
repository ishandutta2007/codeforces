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
typedef long double ld;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MOD=1000000007;
const int MAXLEN=100000+100000;
const int MAXS=1+100000;
const int MAXVAL=MAXS+10;

char s[MAXLEN+1];
int become[MAXLEN];

int n;
char qdig[MAXS];
int qstart[MAXS],qlen[MAXS];

int val[MAXVAL];
int mlt[MAXVAL];

int curto[10];

void run() {
	scanf("%s",s); qdig[0]='?'; qstart[0]=0; qlen[0]=strlen(s);
	scanf("%d",&n);
	FORE(i,1,n) { qstart[i]=qstart[i-1]+qlen[i-1]; scanf(" %c->",&qdig[i]); gets(s+qstart[i]); qlen[i]=strlen(s+qstart[i]); }
	
	REP(i,10) { curto[i]=1+n+i; val[1+n+i]=i; mlt[1+n+i]=10; }
	for(int i=n;i>=0;--i) {
		FOR(j,qstart[i],qstart[i]+qlen[i]) become[j]=curto[s[j]-'0'];
		if(isdigit(qdig[i])) curto[qdig[i]-'0']=i;
	}
	//REPE(i,n) { FOR(j,qstart[i],qstart[i]+qlen[i]) printf("%c=%d ",s[j],become[j]); puts(""); }

	for(int i=n;i>=0;--i) {
		val[i]=0; mlt[i]=1;
		for(int j=qstart[i]+qlen[i]-1;j>=qstart[i];--j) {
			val[i]=(val[i]+(ll)val[become[j]]*mlt[i])%MOD;
			mlt[i]=(ll)mlt[i]*mlt[become[j]]%MOD;
		}
		//printf("%d: %d %d\n",i,val[i],mlt[i]);
	}
	printf("%d\n",val[0]);
}

int main() {
	run();
	return 0;
}
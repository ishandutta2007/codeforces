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

const int MAXLEN=100000;
const int MAXQ=100000;

char s[MAXLEN+1]; int slen;
char t[MAXLEN+1]; int tlen;

int sx[MAXLEN+1];
int tx[MAXLEN+1];
int sa[MAXLEN];
int ta[MAXLEN];

char ans[MAXQ+1];

bool solve(int a,int b,int c,int d) {
	//FORE(j,a,b) printf("%c",s[j]); printf(" -> "); FORE(j,c,d) printf("%c",t[j]); puts("");
	int x1=sx[b+1]-sx[a],x2=tx[d+1]-tx[c];
	int a1=min(sa[b],b-a+1),a2=min(ta[d],d-c+1);
	//printf("x1=%d x2=%d a1=%d a2=%d\n",x1,x2,a1,a2);
	if(x1==x2) {
		if(a1%3!=a2%3||a1<a2) return false;
		return true;
	} else {
		if(x1>x2||x1%2!=x2%2) return false;
		if(x1==0) {
			if(a1<=a2) return false;
			return true;
		} else {
			if(a1<a2) return false;
			return true;
		}
	}
}

void run() {
	scanf("%s%s",s,t); slen=strlen(s); tlen=strlen(t);
	sx[0]=0; REP(i,slen) sx[i+1]=sx[i]+(s[i]=='B'||s[i]=='C'?1:0);
	tx[0]=0; REP(i,tlen) tx[i+1]=tx[i]+(t[i]=='B'||t[i]=='C'?1:0);
	REP(i,slen) sa[i]=s[i]!='A'?0:1+(i==0?0:sa[i-1]);
	REP(i,tlen) ta[i]=t[i]!='A'?0:1+(i==0?0:ta[i-1]);

	int nq; scanf("%d",&nq);
	REP(i,nq) {
		int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d); --a,--b,--c,--d;
		ans[i]=solve(a,b,c,d)?'1':'0';
	}
	ans[nq]='\0'; printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}
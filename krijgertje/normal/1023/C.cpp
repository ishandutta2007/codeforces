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

const int MAXLEN=200000;

int slen,want;
char s[MAXLEN+1];

int match[MAXLEN];
int stck[MAXLEN],nstck;

int prv[MAXLEN],nxt[MAXLEN],head,tail;
int q[MAXLEN],qhead,qtail;

char ret[MAXLEN+1]; int nret;

void remove(int at) {
	if(prv[at]!=-1) { nxt[prv[at]]=nxt[at]; if(s[prv[at]]=='('&&match[prv[at]]==nxt[prv[at]]) q[qhead++]=prv[at]; } else head=nxt[at];
	if(nxt[at]!=-1) { prv[nxt[at]]=prv[at]; } else tail=prv[at];
}


void run() {
	scanf("%d%d",&slen,&want); scanf("%s",s);

	nstck=0;
	REP(i,slen) { if(s[i]=='(') stck[nstck++]=i; else { assert(nstck>0); int j=stck[--nstck]; match[i]=j,match[j]=i; } }
	assert(nstck==0);

	head=0,qtail=slen-1; REP(i,slen) prv[i]=i==0?-1:i-1,nxt[i]=i==slen-1?-1:i+1;
	qhead=qtail=0; REP(i,slen) if(s[i]=='('&&match[i]==nxt[i]) q[qhead++]=i;
	REP(rep,(slen-want)/2) {
		assert(qtail<qhead);
		int a=q[qtail++],b=match[a];
		remove(a); remove(b);
	}

	nret=0;
	for(int at=head;at!=-1;at=nxt[at]) ret[nret++]=s[at];
	ret[nret]='\0';
	printf("%s\n",ret);
}

int main() {
	run();
	return 0;
}
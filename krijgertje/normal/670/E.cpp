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

const int MAXLEN=500000;
const int MAXNODE=1+MAXLEN/2;
const int MAXQ=500000;


char s[MAXLEN+1],q[MAXQ+1]; int slen,qlen,spos;
int chead[MAXNODE],ctail[MAXNODE],cnxt[MAXNODE],cprv[MAXNODE],par[MAXNODE]; int n;
int addnode(int p) { chead[n]=ctail[n]=cnxt[n]=cprv[n]=par[n]=-1; if(p==-1) return n++; par[n]=p,cprv[n]=ctail[p],ctail[p]=n; if(cprv[n]!=-1) cnxt[cprv[n]]=n; else chead[p]=n; return n++; }
void print(int at) { for(int x=chead[at];x!=-1;x=cnxt[x]) { printf("("); print(x); printf(")"); } }

void run() {
	scanf("%d%d%d%s%s",&slen,&qlen,&spos,s,q); --spos;

	n=0;
	int root=addnode(-1);
	int at=-1; bool atleft=true;
	
	int cur=root;
	REP(i,slen) {
		if(s[i]=='(') { cur=addnode(cur); if(i==spos) at=cur,atleft=true; }
		if(s[i]==')') { if(i==spos) at=cur,atleft=false; assert(cur!=root),cur=par[cur]; }
	}
	assert(cur==root&&at!=-1);
	//print(root); puts(""); printf("at=%d,side=%c\n",at,atleft?'L':'R');
	
	REP(i,qlen) {
		if(q[i]=='L') {
			if(atleft) {
				if(cprv[at]!=-1) at=cprv[at],atleft=false; else if(par[at]!=root) at=par[at],atleft=true; else assert(false);
			} else {
				if(ctail[at]!=-1) at=ctail[at],atleft=false; else atleft=true;
			}
		}
		if(q[i]=='R') {
			if(atleft) {
				if(chead[at]!=-1) at=chead[at],atleft=true; else atleft=false;
			} else {
				if(cnxt[at]!=-1) at=cnxt[at],atleft=true; else if(par[at]!=root) at=par[at],atleft=false; else assert(false);
			}
		}
		if(q[i]=='D') {
			if(cprv[at]!=-1) cnxt[cprv[at]]=cnxt[at]; else chead[par[at]]=cnxt[at];
			if(cnxt[at]!=-1) cprv[cnxt[at]]=cprv[at]; else ctail[par[at]]=cprv[at];
			if(cnxt[at]!=-1) at=cnxt[at],atleft=true; else if(par[at]!=root) at=par[at],atleft=false; else if(cprv[at]!=-1) at=cprv[at],atleft=false; else assert(false);
		}
		//printf("at=%d,side=%c\n",at,atleft?'L':'R');
	}
	print(root); puts("");

}

int main() {
	run();
	return 0;
}
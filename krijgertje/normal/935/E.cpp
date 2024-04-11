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

const int MAXLEN=10000;
const int MAXMN=100;

char s[MAXLEN+1]; int slen;
int haveplus,havemin;

int match[MAXLEN];
int stck[MAXLEN],nstck;

int op,haveop;
int mxdp[MAXLEN][MAXMN+1];
int mndp[MAXLEN][MAXMN+1];

void go(int at) {
	if(isdigit(s[at])) {
		int val=s[at]-'0';
		REPE(i,haveop) mxdp[at][i]=i==0?val:INT_MIN,mndp[at][i]=i==0?val:INT_MAX;
	} else {
		int l=at+1,r=match[l]==-1?l+2:match[l]+2;
		go(l); go(r);
		REPE(i,haveop) mxdp[at][i]=INT_MIN,mndp[at][i]=INT_MAX;
		REPE(i,haveop) REPE(j,haveop-i) {
			{ //use plus
				int k=i+j+(op==+1?1:0);
				if(k<=haveop) {
					if(mxdp[l][i]!=INT_MIN&&mxdp[r][j]!=INT_MIN) mxdp[at][k]=max(mxdp[at][k],mxdp[l][i]+mxdp[r][j]);
					if(mndp[l][i]!=INT_MAX&&mndp[r][j]!=INT_MAX) mndp[at][k]=min(mndp[at][k],mndp[l][i]+mndp[r][j]);
				}
			}
			{ //use min
				int k=i+j+(op==-1?1:0);
				if(k<=haveop) {
					if(mxdp[l][i]!=INT_MIN&&mndp[r][j]!=INT_MAX) mxdp[at][k]=max(mxdp[at][k],mxdp[l][i]-mndp[r][j]);
					if(mndp[l][i]!=INT_MAX&&mxdp[r][j]!=INT_MIN) mndp[at][k]=min(mndp[at][k],mndp[l][i]-mxdp[r][j]);
				}
			}
		}
		//printf("%d:",at); REPE(i,haveop) if(mxdp[at][i]!=INT_MIN) printf(" %d",mxdp[at][i]); else printf(" X"); printf(" |"); REPE(i,haveop) if(mndp[at][i]!=INT_MAX) printf(" %d",mndp[at][i]); else printf(" X"); puts("");
	}
}



void run() {
	scanf("%s",s); slen=strlen(s); scanf("%d%d",&haveplus,&havemin);

	REP(i,slen) match[i]=-1; nstck=0;
	REP(i,slen) if(s[i]=='(') stck[nstck++]=i; else if(s[i]==')') { int j=stck[--nstck]; match[i]=j,match[j]=i; } assert(nstck==0);
	
	if(haveplus<=havemin) op=+1,haveop=haveplus; else op=-1,haveop=havemin;
	go(0);
	printf("%d\n",mxdp[0][haveop]);
}

int main() {
	run();
	return 0;
}
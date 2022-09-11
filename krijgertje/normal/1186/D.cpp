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

const int MAXN=100000;
const int ONE=100000;


int n;
int sgn[MAXN],ipart[MAXN],fpart[MAXN];
int ans[MAXN];

void solve() {
	//REP(i,n) printf("%d %d %d\n",sgn[i],ipart[i],fpart[i]);

	int bal=0;
	REP(i,n) {
		if(fpart[i]==0) { ans[i]=sgn[i]*ipart[i]; continue; }
		if(bal>=0) {
			if(sgn[i]>=0) {
				ans[i]=sgn[i]*ipart[i];
				bal-=fpart[i];
			} else {
				ans[i]=sgn[i]*ipart[i]-1;
				bal-=ONE-fpart[i];
			}
		} else {
			if(sgn[i]>=0) {
				ans[i]=sgn[i]*ipart[i]+1;
				bal+=ONE-fpart[i];
			} else {
				ans[i]=sgn[i]*ipart[i];
				bal+=fpart[i];
			}
		}
		//printf("ans[%d]=%d bal=%d\n",i,ans[i],bal);
	}
	assert(bal==0);
}

void run() {
	scanf("%d",&n);
	REP(i,n) {
		char buff[20]; scanf("%s",buff);
		sgn[i]=+1,ipart[i]=0,fpart[i]=0; bool havedec=false;
		for(int j=0;buff[j]!='\0';++j) if(buff[j]=='-') sgn[i]=-sgn[i]; else if(buff[j]=='.') havedec=true; else if(!havedec) ipart[i]=10*ipart[i]+buff[j]-'0'; else fpart[i]=10*fpart[i]+buff[j]-'0';
	}
	solve();
	REP(i,n) printf("%d\n",ans[i]);
}

int main() {
	run();
	return 0;
}
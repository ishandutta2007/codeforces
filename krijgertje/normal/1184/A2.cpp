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

const int MAXN=200000;

int n;
char y[MAXN+1];

bool test(int d) {
	//printf("testing %d\n",d);
	assert(n%d==0);
	REP(off,d) {
		int par=0;
		for(int i=off;i<n;i+=d) if(y[i]=='1') par=1-par;
		//printf("off=%d -> par=%d\n",off,par);
		if(par==1) return false;
	}
	return true;
}

int solve() {
	map<int,int> cnt;
	REP(i,n) ++cnt[gcd(i,n)];
	int ret=0;
	for(auto it=cnt.begin();it!=cnt.end();++it) {
		if(test(it->first)) ret+=it->second;
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	scanf("%s",y); assert(strlen(y)==n);
	printf("%d\n",solve());
}

int solvestupid(int y) {
	int ret=0;
	REP(k,n) {
		REP(x,1<<n) {
			int xrot=x; REP(i,k) { xrot=xrot<<1; if(xrot>=(1<<n)) xrot+=1-(1<<n); }
			if((x^xrot)==y) {
				++ret;
				//if(n==4&&y==3) printf("%d: %x\n",k,x);
				break;
			}
		}
	}
	return ret;
}

void stress() {
	FORE(len,1,10) {
		REP(mask,1<<len) {
			n=len; REP(i,len) y[i]=((mask>>i)&1)==0?'0':'1'; y[len]='\0';
			int have=solve();
			int want=solvestupid(mask);
			if(have==want) { printf("."); continue; }
			printf("err have=%d want=%d\n",have,want);
			printf("%d\n%s\n",n,y);
			return;
		}
		puts("");
	}
}

int main() {
	run();
	//stress();
	return 0;
}
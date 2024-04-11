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

const int MAXN=300000;

int n;
char s[MAXN+1];

vector<bool> mem[9];

ll solve() {
	FORE(len,1,8) {
		mem[len]=vector<bool>(1<<len);
		REP(mask,1<<len) {
			string cur(len,'?'); REP(i,len) cur[i]=(mask&(1<<i))==0?'0':'1';
			bool ok=false; REP(i,len) for(int k=1;i+2*k<len;++k) if(cur[i]==cur[i+k]&&cur[i]==cur[i+2*k]) ok=true;
			mem[len][mask]=ok;
		}
	}
	ll ret=0;
	REP(i,n) {
		int remlen=n-i;
		ret+=max(0,remlen-8);
		int mask=0;
		FORE(len,1,8) if(i+len<=n) {
			mask|=(s[i+len-1]-'0')<<(len-1);
			//printf("i=%d len=%d mask=%x\n",i,len,mask);
			if(mem[len][mask]) ++ret;
		}
	}
	return ret;
}

void run() {
	scanf("%s",s); n=strlen(s);
	printf("%lld\n",solve());
}

void research() {
	FORE(len,1,20) {
		REP(mask,1<<len) {
			string cur(len,'?'); REP(i,len) cur[i]=(mask&(1<<i))==0?'0':'1';
			bool ok=false; REP(i,len) for(int k=1;i+2*k<len;++k) if(cur[i]==cur[i+k]&&cur[i]==cur[i+2*k]) ok=true;
			if(!ok) { printf("len=%d: %s\n",len,cur.c_str()); break; }
		}
	}
}

int main() {
	//research();
	run();
	return 0;
}
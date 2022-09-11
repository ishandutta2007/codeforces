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

const int MAXLEN=500000;

int len,cnt;
char a[MAXLEN+1];
char b[MAXLEN+1];


int opt[MAXLEN+1];

ll solve() {
	if(cnt==1) return len;
	int idx=0; while(idx<len&&a[idx]==b[idx]) ++idx;
	if(idx>=len) return len;
	ll ret=idx+2*(len-idx);
	REPE(i,len) opt[i]=0;
	FOR(i,idx+1,len) if(a[i]=='a') ++opt[len-i];
	FOR(i,idx+1,len) if(b[i]=='b') ++opt[len-i];
	int rem=cnt-2; ll ways=0;
	for(int i=len;i>=1&&rem>0;--i) {
		//printf("i=%d ways=%lld opt=%d\n",i,ways,opt[i]);
		int cur=(int)min(ways+opt[i],(ll)rem);
		ret+=(ll)cur*i;
		rem-=cur;
		ways+=cur;
	}
	//printf("rem=%d\n",rem);
	return ret;
}


void run() {
	scanf("%d%d",&len,&cnt);
	scanf("%s",a);
	scanf("%s",b);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}
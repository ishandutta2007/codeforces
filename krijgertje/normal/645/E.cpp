

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

const int MAXLEN=1000000;
const int MOD=1000000007;

int n,k;
char s[MAXLEN+1]; int slen;
int cnt[26];
int t[26];

int getsum() { int sum=1; REP(j,k) if((sum+=cnt[j])>=MOD) sum-=MOD; return sum; }

void run() {
	scanf("%d%d%s",&n,&k,s); slen=strlen(s);
	REP(i,k) cnt[i]=0,t[i]=-1;
	REP(i,slen) cnt[s[i]-'a']=getsum(),t[s[i]-'a']=i;
	REP(i,n) {
		int idx=0; FOR(j,1,k) if(t[j]<t[idx]) idx=j;
		cnt[idx]=getsum(); t[idx]=slen+i;
	}
	printf("%d\n",getsum());
}

int main() {
	run();
	return 0;
}
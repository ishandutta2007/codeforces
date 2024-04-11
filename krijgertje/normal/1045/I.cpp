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

const int MAXN=100000;
const int MAXSUMLEN=1000000;

int n;
char s[MAXSUMLEN+1];
int off[MAXN+1],len[MAXN];

int mask[MAXN];

void run() {
	scanf("%d",&n);
	off[0]=0; REP(i,n) { scanf("%s",s+off[i]); len[i]=strlen(s+off[i]); off[i+1]=off[i]+len[i]; }

	REP(i,n) { mask[i]=0; REP(j,len[i]) mask[i]^=1<<(s[off[i]+j]-'a'); }
	sort(mask,mask+n);

	ll ret=0;
	REP(i,n) FOR(j,-1,26) {
		int want=mask[i]; if(j!=-1) want^=1<<j;
		int l=max(i+1,lower_bound(mask,mask+n,want)-mask),r=upper_bound(mask,mask+n,want)-mask,cnt=max(0,r-l);
		ret+=cnt;
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}
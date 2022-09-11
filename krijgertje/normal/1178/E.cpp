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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=1000000;

char s[MAXN+1]; int n;
char ans[MAXN+1]; int nans;

char half[MAXN+1]; int nhalf;
char mid;

void solve() {
	nhalf=0; mid='?';
	int l=0,r=n-1;
	while(l<=r) {
		int rem=r-l+1;
		if(rem<=3) { mid=s[l]; break; }
		if(s[l]==s[r]) { half[nhalf++]=s[l]; l+=1,r-=1; continue; }
		if(s[l]==s[r-1]) { half[nhalf++]=s[l]; l+=1,r-=2; continue; }
		if(s[l+1]==s[r]) { half[nhalf++]=s[r]; l+=2,r-=1; continue; }
		assert(s[l+1]==s[r-1]); half[nhalf++]=s[l+1]; l+=2,r-=2;
	}
	nans=0; REP(i,nhalf) ans[nans++]=half[i]; if(mid!='?') ans[nans++]=mid; for(int i=nhalf-1;i>=0;--i) ans[nans++]=half[i]; ans[nans]='\0';

}

void run() {
	scanf("%s",s); n=strlen(s);
	solve();
	printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}
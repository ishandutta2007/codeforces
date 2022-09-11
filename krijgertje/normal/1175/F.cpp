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
int a[MAXN];

int freq[MAXN];

ll solve() {
	ll ret=0;
	REP(i,n) if(a[i]==0) ++ret;
	REP(i,n) freq[i]=0;
	REP(rep,2) {
		REP(i,n) if(a[i]==0) {
			int l=i,r=i,mx=a[i],cnt=0; if(++freq[a[i]]==1) ++cnt;
			while(r+1<n) {
				++r; if(++freq[a[r]]==1) ++cnt; mx=max(mx,a[r]);
				while(freq[a[r]]>1&&l<i) { if(--freq[a[l]]==0) --cnt; ++l; }
				if(freq[a[r]]>1) { --freq[a[r]]; --r; break; }
				while(l-1>=0&&a[l-1]<=mx&&freq[a[l-1]]==0) { --l; if(++freq[a[l]]==1) ++cnt; }
				if(cnt==mx+1) ++ret;
			}
			FORE(j,l,r) assert(--freq[a[j]]==0);
		}
		reverse(a,a+n);
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]),--a[i];
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}
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

int n;
int a[MAXN];

bool solve() {
	sort(a,a+n);
	int dup=-1;
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&a[r]==a[l]) ++r;
		int cnt=r-l;
		if(cnt>=3) return false;
		if(cnt==1) continue;
		assert(cnt==2);
		if(dup!=-1) return false;
		dup=a[l];
	}
	if(dup==0) return false;
	if(dup!=-1) REP(i,n) if(a[i]==dup-1) return false;
	ll have=0,want=0; REP(i,n) have+=a[i],want+=i;
	return (have-want)%2!=0;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%s\n",solve()?"sjfnb":"cslnb");
}

int main() {
	run();
	return 0;
}
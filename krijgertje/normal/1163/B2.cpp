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
const int MAXA=100000;

int n;
int a[MAXN];

int cnt[MAXA+1];
int freq[MAXN+1];

bool ok(int cntfreq,int sumfreq,int last) {
	if(cntfreq==1) {
		int y=sumfreq;
		if(y==1) return true;
		if(freq[y]==1) return true;
	}
	if(cntfreq==2&&last!=-1) {
		int y1=last,y2=sumfreq^last;
		if(freq[y2]>1) swap(y1,y2);
		//printf("y1=%d y2=%d\n",y1,y2);
		if(freq[y2]==1&&y2==y1+1) return true;
		if(freq[y2]==1&&y2==1) return true;
		if(freq[y2]==1&&freq[y1]==1&&y1==y2+1) return true;
	}
	return false;
}

int solve() {
	memset(cnt,0,sizeof(cnt));
	memset(freq,0,sizeof(freq));
	int cntfreq=0,sumfreq=0,last=-1;
	int ret=0;
	REP(i,n) {
		int x=a[i],y=cnt[x];
		if(y!=0) { --freq[y]; if(freq[y]==0) --cntfreq,sumfreq^=y; }
		++cnt[x],++y;
		if(y!=0) { ++freq[y]; if(freq[y]==1) ++cntfreq,sumfreq^=y; last=y; }
		//printf("%d: cntfreq=%d sumfreq=%d\n",i+1,cntfreq,sumfreq);
		if(ok(cntfreq,sumfreq,last))
		 ret=max(ret,i+1);
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
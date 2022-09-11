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
struct Row { int bit,mask,orig; Row() {} Row(int bit,int mask,int orig):bit(bit),mask(mask),orig(orig) {} };

int n;
int a[MAXN];

void augment(vector<Row> &A,int x) {
	int y=x;
	REPSZ(i,A) if((y&(1<<A[i].bit))!=0) y^=A[i].mask;
	if(y==0) return;
	int bit=0; while((2<<bit)<=y) ++bit;
	REPSZ(i,A) if((A[i].mask&(1<<bit))!=0) A[i].mask^=y;
	A.PB(Row(bit,y,x));
}

pair<int,vector<int>> solve() {
	sort(a,a+n);
	vector<Row> retset;
	vector<Row> curset;
	REP(i,n) {
		augment(curset,a[i]);
		int mxbit=0; while((2<<mxbit)<=a[i]) ++mxbit;
		if(SZ(curset)==mxbit+1) retset=curset;
	}

	vector<int> gray(1,0);
	REPSZ(bit,retset) { int osz=SZ(gray); REP(i,osz) gray.PB(gray[osz-i-1]|(1<<bit)); }

	vector<int> retperm; REPSZ(i,gray) { int cur=0; REPSZ(j,retset) if(gray[i]&(1<<j)) cur^=retset[j].orig; retperm.PB(cur); }
	return MP(SZ(retset),retperm);
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	pair<int,vector<int>> ans=solve();
	printf("%d\n",ans.first);
	REPSZ(i,ans.second) { if(i!=0) printf(" "); printf("%d",ans.second[i]); } puts("");
}

int main() {
	run();
	return 0;
}
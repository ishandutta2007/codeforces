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
const int MAXQ=100000;
const int MOD=1000000007;

int n,nq;
char s[MAXN+1];
int ql[MAXQ],qr[MAXQ],qans[MAXQ];

int p2[MAXN+1];
int sum[MAXN+1];

void solve() {
	p2[0]=1; FORE(i,1,n) p2[i]=(ll)p2[i-1]*2%MOD;
	sum[0]=0; REP(i,n) sum[i+1]=sum[i]+(s[i]=='1'?1:0);
	REP(i,nq) {
		int l=ql[i],r=qr[i];
		int len=r-l+1,ones=sum[r+1]-sum[l];
		qans[i]=(p2[len]+MOD-p2[len-ones])%MOD;
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	scanf("%s",s);
	REP(i,nq) scanf("%d%d",&ql[i],&qr[i]),--ql[i],--qr[i];
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}
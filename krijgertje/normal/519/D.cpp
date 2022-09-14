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

typedef struct X { char c; int idx; bool isstart; ll val; } X;
bool operator<(const X &p,const X &q) {
	if(p.c!=q.c) return p.c<q.c;
	if(p.val!=q.val) return p.val<q.val;
	if(p.idx!=q.idx) return p.idx<q.idx;
	if(p.isstart!=q.isstart) return !p.isstart;
	return false;
}

int val[26];
char s[100001]; int n;


X x[200000];



void run() {
	REP(i,26) scanf("%d",&val[i]);
	scanf("%s",s); n=strlen(s);

	ll sum=0;
	REP(i,n) {
		x[2*i+0].c=s[i]; x[2*i+0].isstart=false; x[2*i+0].val=sum; x[2*i+0].idx=i;
		sum+=val[s[i]-'a'];
		x[2*i+1].c=s[i]; x[2*i+1].isstart=true; x[2*i+1].val=sum; x[2*i+1].idx=i;
	}
	sort(x,x+2*n);
	//REP(i,2*n) printf("%d: %c %lld %d %c\n",i,x[i].c,x[i].val,x[i].idx,x[i].isstart?'S':'E');

	ll ret=0;
	int at=0;
	while(at<2*n) {
		int nstart=0,to=at;
		while(to<2*n&&x[to].c==x[at].c&&x[to].val==x[at].val) {
			if(x[to].isstart) ++nstart; else ret+=nstart;
			++to;
		}
		at=to;
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}
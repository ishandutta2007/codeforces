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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n;
int a[200000];
int b[200000];

bool have[1000001];
int nxt[1000001];
int prv[1000001];

int ret[200000],nret;

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&a[i],&b[i]);
	memset(have,false,sizeof(have));
	memset(nxt,-1,sizeof(nxt));
	memset(prv,-1,sizeof(prv));
	REP(i,n) nxt[a[i]]=b[i],prv[b[i]]=a[i],have[a[i]]=have[b[i]]=true;
	
	int p=-1,q=-1;
	FORE(i,1,1000000) if(have[i]&&prv[i]==-1) p=i; else if(have[i]&&prv[i]==0) q=i;

	nret=0;
	while(p!=-1&&p!=0||q!=-1&&q!=0) {
		if(p!=-1&&p!=0) { ret[nret++]=p; p=nxt[p]; }
		if(q!=-1&&q!=0) { ret[nret++]=q; q=nxt[q]; }
	}
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}
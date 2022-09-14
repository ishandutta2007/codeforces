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

const int MAXN=4000;
const int MAXM=4000;

int n,m;
int head[MAXN],nxt[2*MAXM],to[2*MAXM],deg[MAXN];
int s[MAXN],o[2*MAXM];

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) head[i]=-1,deg[i]=0;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b; ++deg[a];
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a; ++deg[b];
	}
	REP(i,n) {
		s[i]=i==0?0:s[i-1]+deg[i-1];
		for(int x=head[i],j=0;x!=-1;x=nxt[x],++j) o[s[i]+j]=to[x];
		sort(o+s[i],o+s[i]+deg[i]);
	}
	int ret=INT_MAX;
	REP(i,n) for(int x=head[i];x!=-1;x=nxt[x]) {
		int j=to[x];
		int ii=0,jj=0;
		while(ii<deg[i]&&jj<deg[j]) {
			if(o[s[i]+ii]<o[s[j]+jj]) ++ii;
			else if(o[s[i]+ii]>o[s[j]+jj]) ++jj;
			else { int k=o[s[i]+ii]; int cur=deg[i]-2+deg[j]-2+deg[k]-2; if(cur<ret) ret=cur; ++ii,++jj; }
		}
	}
	printf("%d\n",ret==INT_MAX?-1:ret);
}

int main() {
	run();
	return 0;
}
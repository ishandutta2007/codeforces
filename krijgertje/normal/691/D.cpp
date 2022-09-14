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

const int MAXN=1000000;
const int MAXM=1000000;

int n,m;
int p[MAXN];
int a[MAXM],b[MAXM];
int par[MAXN];
int off[MAXN],cnt[MAXN];
int c[MAXN],nc;
int ret[MAXN];


int find(int x) { if(par[x]<0) return x; return par[x]=find(par[x]); }
void unite(int x,int y) {
	x=find(x),y=find(y);
	if(x==y) return;
	if(-par[x]<-par[y]) swap(x,y);
	par[x]+=par[y]; par[y]=x;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%d",&p[i]);
	REP(i,m) scanf("%d%d",&a[i],&b[i]),--a[i],--b[i];
	REP(i,n) par[i]=-1;
	REP(i,m) unite(a[i],b[i]);
	REP(i,n) cnt[i]=0; REP(i,n) ++cnt[find(i)];
	nc=0; REP(i,n) if(find(i)==i) off[i]=nc,nc+=cnt[i];
	REP(i,n) c[off[find(i)]++]=p[i];
	REP(i,n) if(find(i)==i) off[i]-=cnt[i],sort(c+off[i],c+off[i]+cnt[i]),reverse(c+off[i],c+off[i]+cnt[i]);
	REP(i,n) ret[i]=-1;
	REP(i,n) ret[i]=c[off[find(i)]++];
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}
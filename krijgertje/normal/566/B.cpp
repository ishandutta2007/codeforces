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

const int MAXN=30000;

int n;
int a[4*MAXN],b[4*MAXN],c[4*MAXN];
bool done[4*MAXN];

int cnt[MAXN];
int whead[MAXN],wnxt[8*MAXN];

int head,prv[4*MAXN],nxt[4*MAXN],tail; bool inlst[4*MAXN];
bool can(int i) {
	if(a[i]==b[i]) return cnt[c[i]]+1<=9;
	if(a[i]==c[i]) return cnt[b[i]]+1<=9;
	if(b[i]==c[i]) return cnt[b[i]]+2<=9;
	return cnt[b[i]]+1<=9&&cnt[c[i]]+1<=9;
}
void ins(int x) {
	assert(!inlst[x]); inlst[x]=true;
	if(head==-1) head=x; if(tail!=-1) nxt[tail]=x; prv[x]=tail; nxt[x]=-1; tail=x;
}
void rem(int x) {
	assert(inlst[x]); inlst[x]=false;
	if(prv[x]==-1) head=nxt[x]; else nxt[prv[x]]=nxt[x]; if(nxt[x]==-1) tail=prv[x]; else prv[nxt[x]]=prv[x]; prv[x]=nxt[x]=-1;
}
void printstate() { printf("lst:"); for(int x=head;x!=-1;x=nxt[x]) printf(" %d",x); printf(" |"); REP(i,n) printf(" %d",cnt[i]); puts(""); }

int ret[4*MAXN],nret;

void run() {
	scanf("%d",&n);
	REP(i,n) cnt[i]=0,whead[i]=-1;
	REP(i,4*n) scanf("%d%d%d",&a[i],&b[i],&c[i]),--a[i],--b[i],--c[i],done[i]=inlst[i]=false;
	REP(i,4*n) cnt[a[i]]++;
	REP(i,4*n) {
		wnxt[2*i+0]=whead[b[i]]; whead[b[i]]=2*i+0;
		wnxt[2*i+1]=whead[c[i]]; whead[c[i]]=2*i+1;
	}
	head=tail=-1; nret=0;
	REP(i,4*n) if(can(i)) ins(i);
	//printstate();
	while(head!=-1) {
		int cur=head; rem(cur); done[cur]=true;
		ret[nret++]=cur;
		--cnt[a[cur]]; for(int x=whead[a[cur]];x!=-1;x=wnxt[x]) if(!done[x>>1]&&!inlst[x>>1]&&can(x>>1)) ins(x>>1);
		++cnt[b[cur]]; for(int x=whead[b[cur]];x!=-1;x=wnxt[x]) if(!done[x>>1]&&inlst[x>>1]&&!can(x>>1)) rem(x>>1);
		++cnt[c[cur]]; for(int x=whead[c[cur]];x!=-1;x=wnxt[x]) if(!done[x>>1]&&inlst[x>>1]&&!can(x>>1)) rem(x>>1);
		//printstate();
	}
	if(nret!=4*n) { printf("NO\n"); return; }
	printf("YES\n"); REP(i,nret) printf("%d%c",ret[i]+1,i==nret-1?'\n':' ');
}


int main() {
	run();
	return 0;
}
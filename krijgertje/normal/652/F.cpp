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

const int MAXN=300000;

int n,len; ll t;
int pos[MAXN]; char d[MAXN];
int p[MAXN],pinv[MAXN]; bool pcmp(const int &u,const int &v) { return pos[u]<pos[v]; }
int rpos[MAXN];
int ret[MAXN];

ll r[2*MAXN]; int rhead,rtail;
ll l[2*MAXN]; int lhead,ltail;
int norm(ll x) { x%=len; if(x<=0) x+=len; return x; }

void solve() {
	rhead=rtail=lhead=ltail=0;
	FOR(i,1,n) if(d[i]=='R') r[rhead++]=pos[i]<pos[0]?pos[i]:pos[i]-len; else if(d[i]=='L') l[lhead++]=pos[i]>pos[0]?pos[i]:pos[i]+len;
	sort(r,r+rhead); reverse(r,r+rhead); sort(l,l+lhead);

	int t1=(int)(t%len),t2=len,x1=-1,x2=-1; char d1;
	ll cpos=pos[0]; char cd=d[0]; ll ct=0;
	while(ct<2*t2) {
		//puts(""); printf("%.1lf: %I64d %c\n",.5*ct,cpos,cd);
		//printf("R:"); FOR(i,rtail,rhead) printf(" %d",r[i]); puts("");
		//printf("L:"); FOR(i,ltail,lhead) printf(" %d",l[i]); puts("");
		ll nt=2*t2; ll npos=cpos; char nd=cd;
		if(cd=='R'&&ltail<lhead) {
			nt=l[ltail]-cpos; assert(rhead<2*n);
			r[rhead++]=cpos-len; npos=l[ltail++]; nd='L'; 
		}
		if(cd=='L'&&rtail<rhead) {
			nt=cpos-r[rtail]; assert(lhead<2*n);
			l[lhead++]=cpos+len; npos=r[rtail++]; nd='R';
		}
		if(ct<=2*t1&&2*t1<nt) { x1=norm(cpos+(cd=='R'?+1:cd=='L'?-1:0)*t1); d1=cd; }
		if(ct<2*t2&&2*t2<=nt) { x2=norm(cpos+(cd=='R'?+1:cd=='L'?-1:0)*t2); }
		ct=nt,cpos=npos,cd=nd;
	}
	if(x1==-1) { printf("x1==-1\n"); exit(0); } if(x2==-1) { printf("x2==-1\n"); exit(0); }
	//printf("x1=%d dc=%c x2=%d\n",x1,d1,x2);
	REP(i,n) p[i]=i; sort(p,p+n,pcmp);
	REP(i,n) pinv[p[i]]=i;
	int nidx=-1; REP(i,n) if(pos[i]==x2) { nidx=i; break; } if(nidx==-1) { printf("nidx==-1 [%d]\n",x2); exit(0); }
	int step=pinv[0]-pinv[nidx]; if(step<0) step+=n;
	int aidx=(pinv[0]+(t/len)*step)%n;
	REP(i,n) rpos[i]=norm(pos[i]+(d[i]=='R'?+1:d[i]=='L'?-1:0)*t); sort(rpos,rpos+n);
	int bidx=-1; REP(i,n) if(rpos[i]==x1) { bidx=i+1>=n||rpos[i+1]!=x1||d1=='L'?i:i+1; break; } if(bidx==-1) { printf("bidx==-1 [%d%c]\n",x1,d1); exit(0); }
	//printf("apos=%d, aidx=%d, bidx=%d\n",apos,aidx,bidx);
	//printf("p:"); REP(i,n) printf(" %d",p[i]); puts("");
	//printf("rpos:"); REP(i,n) printf(" %d",rpos[i]); puts("");
	REP(i,n) ret[p[i]]=rpos[(bidx+i-aidx+n)%n];
}

void run() {
	scanf("%d%d%I64d",&n,&len,&t);
	REP(i,n) scanf("%d %c",&pos[i],&d[i]);
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

ll myrand(ll lim) {
	ll cur=0; while(cur<lim) cur=cur*RAND_MAX+rand(); if(cur<0) cur=-cur; return cur%lim;
}

void stress() {
	REP(qi,100) {
		n=MAXN; len=1000000000; t=myrand(1000000000000000000LL);
		set<int> have;
		REP(i,n) { do { pos[i]=myrand(len)+1; } while(have.count(pos[i])); have.insert(pos[i]); d[i]="LR"[rand()%2]; }
		//printf("%d %d %I64d\n",n,len,t); REP(i,n) printf("%d %c\n",pos[i],d[i]);
		printf("."); solve();
	}
}



int main() {
	//srand(time(NULL)); stress();
	run();
	return 0;
}
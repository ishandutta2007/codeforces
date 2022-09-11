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
#include <chrono>
#include <random>
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

const int MAXN=300;
struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
bool operator<(const P &a,const P &b) {
	bool apos=a.y>0||a.y==0&&a.x>0;
	bool bpos=b.y>0||b.y==0&&b.x>0;
	if(apos!=bpos) return apos;
	return (a^b)>0;
}

int n;
P p[MAXN];

int byrot[MAXN][MAXN-1];
int invbyrot[MAXN][MAXN];
pair<P,int> o[MAXN];

int cntinside[MAXN][MAXN][MAXN];
int cntbefore[MAXN][MAXN][MAXN];

int side(const P &a,const P &b,const P &c) { ll res=(b-a)^(c-a); return res<0?-1:res>0?+1:0; }
int side(int a,int b,int c) { return side(p[a],p[b],p[c]); }

int bit[MAXN+1];
int bget(int idx) { ++idx; int ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }
void bmod(int idx,int by) { ++idx; while(idx<=n) { bit[idx]+=by; idx+=idx&-idx; } }

ll solve() {
	REP(a,n) {
		int cnt=0; REP(b,n) if(b!=a) o[cnt++]=MP(p[b]-p[a],b);
		sort(o,o+cnt);
		REP(i,cnt) byrot[a][i]=o[i].second;
		//printf("byrot%d:",a); REP(i,n-1) printf(" %d",byrot[a][i]); puts("");
	}
	REP(a,n) REP(b,n) REP(c,n) cntinside[a][b][c]=cntbefore[a][b][c]=0;
	REP(a,n) REP(b,n) invbyrot[a][b]=-1; REP(a,n) REP(i,n-1) invbyrot[a][byrot[a][i]]=i;
	REP(a,n) REP(b,n) if(b!=a) {
		int bidx=invbyrot[a][b]; assert(bidx!=-1);
		int aidx=invbyrot[b][a]; assert(aidx!=-1);
		int tot=0; REPE(i,n) bit[i]=0;
		FOR(i,1,n-1) {
			int c=byrot[a][(bidx+i)%(n-1)];
			if(side(a,b,c)!=-1) continue;
			int idx=invbyrot[b][c]; assert(idx!=-1&&idx<n-1); idx-=aidx; if(idx<0) idx+=n-1;
			int cur=bget(idx);
			cntinside[a][b][c]=tot-cur;
			cntbefore[a][b][c]=cur;
			++tot; bmod(idx,1);
		}
	}

	ll ret=0;
	REP(c,n) REP(d,n) if(d!=c) {
		int cnta=0; REP(a,n) if(side(c,d,a)==+1) ++cnta;
		ll cur=0;
		REP(b,n) cur+=(ll)cnta*cntbefore[c][d][b];
		REP(e,n) cur+=(ll)cnta*cntbefore[e][c][d]; 
		REP(b,n) cur-=(ll)2*cntbefore[c][d][b]*cntinside[b][c][d];
		REP(e,n) cur-=(ll)2*cntbefore[e][c][d]*cntinside[d][e][c];
		REP(a,n) cur+=(ll)2*cntinside[c][a][d]*cntinside[a][d][c];
		ret+=cur;
		//printf("%d-%d = %lld\n",c,d,cur);
	}
	if(ret%10!=0) { printf("err ret=%d\n",ret); }
	return ret/10;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	printf("%lld\n",solve());
}

int solvestupid() {
	int ret=0;
	REP(a,n) REP(b,n) REP(c,n) REP(d,n) REP(e,n) {
		if(b==a||c==b||c==a||d==c||d==b||d==a||e==d||e==c||e==b||e==a) continue;
		if(side(c,d,a)!=+1) continue;
		if(side(c,d,e)!=-1) continue;
		if(side(c,d,b)!=-1) continue;
		if(side(b,d,a)!=+1) continue;
		if(side(e,c,a)!=-1) continue;
		if(side(c,b,e)!=-1) continue;
		if(side(d,b,e)!=-1) continue;
		if(side(c,e,b)!=+1) continue;
		if(side(d,e,b)!=+1) continue;
		++ret;
	}
	assert(ret%5==0); ret/=5;
	return ret;
}

void stress() {
	std::mt19937 rnd(213);
	int mnn=10,mxn=30,mxcoord=1000000;
	REP(rep,1000) {
		n=rnd()%(mxn-mnn+1)+mnn;
		while(true) {
			REP(i,n) p[i].x=rnd()%mxcoord,p[i].y=rnd()%mxcoord;
			bool ok=true; REP(i,n) FOR(j,i+1,n) FOR(k,j+1,n) if(side(i,j,k)==0) ok=false; if(ok) break;
		}
		int have=solve();
		int want=solvestupid();
		if(have==want) { printf("."); continue; }
		printf("have=%d want=%d\n",have,want);
	}
}

int main() {
	run();
	//stress();
	return 0;
}
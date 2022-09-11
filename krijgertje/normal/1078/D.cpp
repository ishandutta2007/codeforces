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
const int MAXLG=16;
struct Range { int l,r; Range() {} Range(int l,int r):l(l),r(r) {} };

struct RMQ {
	int n,lgn;
	vector<int> a;
	vector<vector<int>> b;
	vector<int> lg;

	void init(int _n) { n=_n; a=vector<int>(n,0); }
	void build() {
		lg=vector<int>(n+1); lg[1]=0; FORE(i,1,n) { lg[i]=lg[i-1]; while((2<<lg[i])<=i) ++lg[i]; } lgn=lg[n];
		b=vector<vector<int>>(n,vector<int>(lgn+1,-1));
		REP(i,n) b[i][0]=i;
		REP(k,lgn) REP(i,n) { b[i][k+1]=b[i][k]; if(i+(1<<k)<n&&a[b[i+(1<<k)][k]]<a[b[i][k]]) b[i][k+1]=b[i+(1<<k)][k]; }
	}
	int get(int l,int r) {
		int k=lg[r-l+1]; return a[b[l][k]]<a[b[r-(1<<k)+1][k]]?b[l][k]:b[r-(1<<k)+1][k];
	}
};

int n;
int a[MAXN];
int ans[MAXN];

Range range[MAXN][MAXLG+1];

RMQ lrmq,rrmq;

/*Res mergergt(const Res &have,int k2) {  return Res(min(n,have.cnt+r[at][k2].cnt-overlap),r[at][k2].nxt); }
Res mergelft(const Res &have,int k2) {  return Res(min(n,have.cnt+l[at][k2].cnt-overlap),l[at][k2].nxt); }*/

Range normalize(const Range &cur) {
	if(cur.l<0) return Range(cur.l+n,cur.r);
	if(cur.r>=n) return Range(cur.l,cur.r-n);
	return cur;
}

Range merge(const Range &a,const Range &b) {
	if(a.l>b.l) return merge(b,a);
	//printf("merging [%d..%d] with [%d..%d]\n",a.l,a.r,b.l,b.r);
	if(a.l>a.r) { if(b.l<=b.r) return Range(a.l,a.r); else if(b.r<a.l) return Range(a.l,max(a.r,b.r)); else return Range(0,n-1); }
	else if(b.l<=a.r) { if(b.l<=b.r) return Range(a.l,max(a.r,b.r)); else if(b.r<a.l) return Range(a.l,b.r); else return Range(0,n-1); }
	else { assert(b.r<b.l&&b.r>=a.l); return Range(b.l,max(a.r,b.r)); }
}

int getlft(const Range &cur) { int l=cur.l,r=cur.r; if(r<l) r+=n; return lrmq.get(l,r)%n; }
int getrgt(const Range &cur) { int l=cur.l,r=cur.r; if(r<l) r+=n; return rrmq.get(l,r)%n; }
int getlen(const Range &cur) { int l=cur.l,r=cur.r; if(r<l) r+=n; return r-l+1; }
Range extend(const Range &cur,int k) { 
	int l=getlft(cur),r=getrgt(cur); 
	//printf("cur=[%d..%d] -> l=%d, r=%d\n",cur.l,cur.r,l,r);
	return merge(merge(range[l][k],cur),range[r][k]); 
}

int calc(int start,int steps) {
	Range cur(start,start); REPE(k,MAXLG) if(steps&(1<<k)) cur=extend(cur,k);
	return getlen(cur);
}

void solve() {
	REP(i,n) a[i]=min(a[i],n-1);
	
	lrmq.init(2*n);
	REP(i,2*n) lrmq.a[i]=i-a[i%n];
	lrmq.build();
	rrmq.init(2*n);
	REP(i,2*n) rrmq.a[i]=-(i+a[i%n]);
	rrmq.build();
	REP(i,n) range[i][0]=merge(normalize(Range(i-a[i],i)),normalize(Range(i,i+a[i])));
	REP(k,MAXLG) REP(i,n) range[i][k+1]=extend(range[i][k],k);
	//REP(i,n) { printf("range%d:",i); REP(k,5) printf(" (%d,%d)",range[i][k].l,range[i][k].r); puts(""); }

	REP(i,n) {
		int lo=-1,hi=n;
		while(lo+1<hi) {
			int mi=lo+(hi-lo)/2;
			if(calc(i,mi)>=n) hi=mi; else lo=mi;
		}
		ans[i]=hi;
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int bfans[MAXN];

void bfsolve() {
	REP(i,n) {
		int l=i,r=i,cur=0;
		while(true) {
			int cnt=l<=r?r-l+1:n-r+l+1; if(cnt==n) break;
			int lidx=l,ridx=l;
			for(int at=l;;++at) {
				if(at-a[at%n]<lidx-a[lidx%n]) lidx=at;
				if(at+a[at%n]>ridx+a[ridx%n]) ridx=at;
				if(at%n==r) break;
			}
			int ncnt=ridx-lidx+1+a[lidx%n]+a[ridx%n]; 
			//printf("start=%d l=%d r=%d cnt=%d cur=%d -> lidx=%d ridx=%d -> ncnt=%d\n",i,l,r,cnt,cur,lidx,ridx,ncnt);
			if(cur>n) exit(0);
			++cur;
			if(ncnt>=n) break;
			l=lidx-a[lidx%n]; while(l<0) l+=n;
			r=ridx+a[ridx%n]; while(r>=n) r-=n;
		}
		bfans[i]=cur;
	}
}

void stress() {
	REP(rep,100000) {
		n=rand()%20;
		//REP(i,n) a[i]=rand()%(n-1)+1;
		REP(i,n) a[i]=rand()%10+1;
		solve();
		bfsolve();
		bool ok=true; REP(i,n) if(ans[i]!=bfans[i]) ok=false;
		if(ok) { printf("."); continue; }
		printf("err (rep=%d)\n",rep);
		printf("%d\n",n); REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]); } puts("");
		printf("have:"); REP(i,n) printf(" %d",ans[i]); puts("");
		printf("want:"); REP(i,n) printf(" %d",bfans[i]); puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}
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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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

int n;
int px[3000],py[3000];
int d2[3000][3000];

int cw[3000][2999*2];

bool max60deg(int center,int a,int b) {
	int ax=px[a]-px[center],ay=py[a]-py[center];
	int bx=px[b]-px[center],by=py[b]-py[center];
	int cross=ax*bx+ay*by;
	// cross/sqrt(ax*ax+ay*ay)/sqrt(bx*bx+by*by)>=.5
	// 4*cross^2>=(ax*ax+ay*ay)*(bx*bx+by*by)
	ll lhs=4LL*cross*cross;
	ll rhs=(ll)(ax*ax+ay*ay)*(bx*bx+by*by);
//	printf("\t\t\t\t(%d,%d,%d):(cross=%d,cos=%lf,%lld>=%lld)\n",center,a,b,cross,1.0*cross/sqrt(ax*ax+ay*ay)/sqrt(bx*bx+by*by),lhs,rhs);
	return cross>0&&lhs>=rhs;
}

bool first60deg(int center,int a,int b) {
	int ax=px[a]-px[center],ay=py[a]-py[center];
	int bx=px[b]-px[center],by=py[b]-py[center];
	int cross=ax*bx+ay*by;
	int dot=ax*by-ay*bx;
	// cross/sqrt(ax*ax+ay*ay)/sqrt(bx*bx+by*by)>=.5
	// 4*cross^2>=(ax*ax+ay*ay)*(bx*bx+by*by)
	ll lhs=4LL*cross*cross;
	ll rhs=(ll)(ax*ax+ay*ay)*(bx*bx+by*by);
//	printf("\t\t\t\t(%d,%d,%d):(cross=%d,dot=%d,cos=%lf,%lld>=%lld)\n",center,a,b,cross,dot,1.0*cross/sqrt(ax*ax+ay*ay)/sqrt(bx*bx+by*by),lhs,rhs);
	return cross>0&&lhs>=rhs&&dot>=0;
}

bool test(int mind2) {
//	printf("testing %d\n",mind2);
	REP(i,n) {
//		printf("\taround %d\n",i);
		int a=0,b=0; int cnt=0;
		REP(j,n-1) if(d2[i][cw[i][j]]>=mind2) {
//			printf("\t\tfrom %d (at distance %d)\n",cw[i][j],d2[i][cw[i][j]]);
			while(a<j||first60deg(i,cw[i][j],cw[i][a])) {
				if(d2[i][cw[i][a]]>=mind2) {
//					printf("\t\t\t%d leaves (at distance %d)\n",cw[i][a],d2[i][cw[i][a]]);
					--cnt;
				}
				++a;
			}
			while(b<a||!max60deg(i,cw[i][j],cw[i][b])) {
				if(d2[i][cw[i][b]]>=mind2) {
//					printf("\t\t\t%d enters (at distance %d)\n",cw[i][b],d2[i][cw[i][b]]);
					++cnt;
				}
				++b;
			}
//			printf("\t\t%d (at distance %d) -> %d items\n",cw[i][j],d2[i][cw[i][j]],cnt);
			if(cnt>0) return true;
		}
	}
	return false;
}

int center;
bool centercmp(const int &a,const int &b) {
	int ax=px[a]-px[center],ay=py[a]-py[center];
	int bx=px[b]-px[center],by=py[b]-py[center];
	bool afirst=ay>0||ay==0&&ax>0;
	bool bfirst=by>0||by==0&&bx>0;
	if(afirst!=bfirst) return afirst;
	int dot=ax*by-ay*bx;
	return dot>0;
}


int alld2[4498500];

void run(int casenr) {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&px[i],&py[i]);
	REP(i,n) FOR(j,i+1,n) d2[i][j]=d2[j][i]=(px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]);

	REP(i,n) {
		int cnt=0;
		REP(j,n) if(i!=j) cw[i][cnt++]=j;
		center=i; sort(cw[i],cw[i]+cnt,centercmp);
		REP(j,cnt) cw[i][cnt+j]=cw[i][j];
	}
//	REP(i,n) { REP(j,n) printf("%d ",d2[i][j]); puts(""); }

	int cnt=0;
	REP(i,n) FOR(j,i+1,n) alld2[cnt++]=d2[i][j];
	sort(alld2,alld2+cnt);
	cnt=unique(alld2,alld2+cnt)-alld2;
//	REP(i,cnt) printf("%d ",alld2[i]); puts("");

	int l=0,h=cnt; // [l,h)
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(test(alld2[m])) l=m; else h=m;
	}
	printf("%.9lf\n",.5*sqrt(1.0*alld2[l]));
}


int main() {
//	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
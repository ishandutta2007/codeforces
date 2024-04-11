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

const int MAXN=200;
const int MAXLG=16;
typedef double Mat[MAXN][MAXN];
typedef double Vec[MAXN];
struct P { int x,y; };

int n;
P p[MAXN];

Mat pone;
Mat pmany[MAXLG+1];

Vec pok;


void mmlt(const Mat &A,const Mat &B,Mat &C) {
	Mat tmp;
	REP(i,n) REP(j,n) { double cur=0; REP(k,n) cur+=A[i][k]*B[k][j]; tmp[i][j]=cur; }
	REP(i,n) REP(j,n) C[i][j]=tmp[i][j];
}
void vmlt(const Mat &A,const Vec &b,Vec &c) {
	Vec tmp;
	REP(i,n) { double cur=0; REP(j,n) cur+=A[i][j]*b[j]; tmp[i]=cur; }
	REP(i,n) c[i]=tmp[i];
}


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);

	REP(i,n) REP(j,n) pone[i][j]=0;
	REP(i,n) {
		map<pair<int,int>,vector<int> > cur;
		REP(j,n) if(j!=i) {
			int dx=p[j].x-p[i].x,dy=p[j].y-p[i].y;
			if(dy<0||dy==0&&dx<0) dy=-dy,dx=-dx;
			int g=gcd(abs(dx),dy); dx/=g,dy/=g;
			cur[MP(dx,dy)].PB(j);
		}
		for(auto it=cur.begin();it!=cur.end();++it) {
			vector<int> now=it->second;
			double peach=1.0/SZ(cur)/(SZ(now)+1);
			pone[i][i]+=peach; REPSZ(j,now) pone[i][now[j]]+=peach;
		}
	}
	//REP(i,n) { printf("%d:",i); REP(j,n) printf(" %.3lf",pone[i][j]); puts(""); }

	REP(i,n) REP(j,n) pmany[0][i][j]=pone[i][j];
	REP(k,MAXLG) mmlt(pmany[k],pmany[k],pmany[k+1]);

	set<vector<int> > opt;
	REP(i,n) {
		map<pair<int,int>,vector<int> > cur;
		REP(j,n) if(j!=i) {
			int dx=p[j].x-p[i].x,dy=p[j].y-p[i].y;
			if(dy<0||dy==0&&dx<0) dy=-dy,dx=-dx;
			int g=gcd(abs(dx),dy); dx/=g,dy/=g;
			cur[MP(dx,dy)].PB(j);
		}
		for(auto it=cur.begin();it!=cur.end();++it) {
			vector<int> now=it->second; now.PB(i); sort(now.begin(),now.end()); opt.insert(now);
		}
	}

	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		int dst,steps; scanf("%d%d",&dst,&steps); --dst,--steps;
		REP(i,n) pok[i]=i==dst?1.0:0.0;
		REPE(k,MAXLG) if(steps&(1<<k)) vmlt(pmany[k],pok,pok);
		//printf("pok:"); REP(i,n) printf(" %.3lf",pok[i]); puts("");
		double ans=0;
		for(auto it=opt.begin();it!=opt.end();++it) {
			vector<int> now=*it;
			double sum=0; REPSZ(j,now) sum+=pok[now[j]];
			ans=max(ans,sum/SZ(now));
		}
		printf("%.15lf\n",ans);
	}


}

int main() {
	run();
	return 0;
}
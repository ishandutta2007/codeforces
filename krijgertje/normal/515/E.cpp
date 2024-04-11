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

const int MAXTREE=100000;

int n,nq;
int d[MAXTREE];
int h[MAXTREE];
ll p[MAXTREE+1];

ll val[MAXTREE][2];
int tmax[1<<18][2];

int best(int a,int b,int z) {
	return val[a][z]>=val[b][z]?a:b;
}

int get(int x,int l,int r,int L,int R,int z) {
	if(L>R) return -1;
	if(L<=l&&r<=R) return tmax[x][z];
	int m=l+(r-l)/2;
	if(R<=m) return get(2*x+1,l,m,L,R,z);
	if(m+1<=L) return get(2*x+2,m+1,r,L,R,z);
	int a=get(2*x+1,l,m,L,R,z);
	int b=get(2*x+2,m+1,r,L,R,z);
	return best(a,b,z);
}

void init(int x,int l,int r) {
	if(l==r) {
		tmax[x][0]=tmax[x][1]=l;
	} else {
		int m=l+(r-l)/2;
		init(2*x+1,l,m); init(2*x+2,m+1,r);
		tmax[x][0]=best(tmax[2*x+1][0],tmax[2*x+2][0],0);
		tmax[x][1]=best(tmax[2*x+1][1],tmax[2*x+2][1],1);
	}
}

void update(ll &ret,int x,int y) {
	ll cur=(ll)2*h[x]+(ll)2*h[y];
	if(x<=y) cur+=p[y]-p[x]; else cur+=p[n]+p[y]-p[x];
	if(cur>ret) ret=cur;
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&d[i]);
	REP(i,n) scanf("%d",&h[i]);
	p[0]=0; REP(i,n) p[i+1]=p[i]+d[i];
	REP(i,n) val[i][0]=(ll)2*h[i]-p[i];
	REP(i,n) val[i][1]=(ll)2*h[i]+p[i];

	init(0,0,n-1);
	REP(qi,nq) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		// max(2*h[x]+2*h[y]+dist(x,y)) 
		ll ret=0;
		if(a<=b) {
			int x1=get(0,0,n-1,b+1,n-1,0);
			int x2=get(0,0,n-1,0,a-1,0);
			int y1=get(0,0,n-1,b+1,n-1,1);
			int y2=get(0,0,n-1,0,a-1,1);
			if(x1!=-1&&y1!=-1&&x1!=y1) {
				update(ret,x1,y1);
			} else if(x1!=-1&&y1!=-1) {
				int x3=get(0,0,n-1,b+1,y1-1,0);
				if(x3!=-1) update(ret,x3,y1);
				int y3=get(0,0,n-1,x1+1,n-1,1);
				if(y3!=-1) update(ret,x1,y3);
			}
			if(x2!=-1&&y2!=-1&&x2!=y2) {
				update(ret,x2,y2);
			} else if(x2!=-1&&y2!=-1) {
				int x3=get(0,0,n-1,0,y2-1,0);
				if(x3!=-1) update(ret,x3,y2);
				int y3=get(0,0,n-1,x2+1,a-1,1);
				if(y3!=-1) update(ret,x2,y3);
			}
			if(x1!=-1&&y2!=-1) {
				update(ret,x1,y2);
			}
		} else {
			int x=get(0,0,n-1,b+1,a-1,0);
			int y=get(0,0,n-1,b+1,a-1,1);
			if(x!=y) {
				update(ret,x,y);
			} else {
				int x1=get(0,0,n-1,b+1,y-1,0);
				if(x1!=-1) update(ret,x1,y);
				int y2=get(0,0,n-1,x+1,a-1,1);
				if(y2!=-1) update(ret,x,y2);
			}
		}
		cout<<ret<<endl;
	}


}

int main() {
	run();
	return 0;
}
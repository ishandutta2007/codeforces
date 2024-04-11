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

const int MAXN=100000+2;

int n;
int x[MAXN];
int d[MAXN];

int mx[MAXN]; // mx[i] = when column i doesn't crash, the maximum coordinate of the next column that doesn't crash (x[0] if impossible)
int mn[MAXN]; // mx[i] = when column i doesn't crash, the minimum coordinate of the prev column that doesn't crash (x[n-1] if impossible)

int stck[MAXN],nstck;

void run() {
	scanf("%d",&n); n+=2;
	REP(i,n) scanf("%d",&x[i]);
	d[0]=INT_MAX; FOR(i,1,n-1) scanf("%d",&d[i]); d[n-1]=INT_MAX;

	mx[0]=x[n-1]; nstck=0; stck[nstck++]=0;
	FOR(i,1,n-1) {
		while(x[i]>mx[stck[nstck-1]]) --nstck;
		int j=stck[nstck-1];
		if(x[j]+2*d[i]<=x[i]) {
			mx[i]=x[0];
		} else {
			mx[i]=x[j]+2*d[i];
			while(nstck>0&&mx[i]>=mx[stck[nstck-1]]) --nstck;
			stck[nstck++]=i;
		}
	}
	mn[n-1]=x[0]; nstck=0; stck[nstck++]=n-1;
	for(int i=n-2;i>=1;--i) {
		while(x[i]<mn[stck[nstck-1]]) --nstck;
		int j=stck[nstck-1];
		if(x[j]-2*d[i]>=x[i]) {
			mn[i]=x[n-1];
		} else {
			mn[i]=x[j]-2*d[i];
			while(nstck>0&&mn[i]<=mn[stck[nstck-1]]) --nstck;
			stck[nstck++]=i;
		}
	}
	//FOR(i,1,n-1) printf("%d..%d..%d (%d)\n",mn[i],x[i],mx[i],d[i]);

	FOR(i,1,n-1) if(mx[i]>=x[n-1]) { printf("0\n"); return; }

	int ret=x[n-1]-x[0];
	FOR(i,1,n-1) if(mx[i]>x[i]) { int cur=x[n-1]-x[i]; if(cur<ret) ret=cur; }
	FOR(i,1,n-1) if(mn[i]<x[i]) { int cur=x[i]-x[0]; if(cur<ret) ret=cur; }
	//FOR(i,1,n-1) FOR(j,i+1,n-1) if(mx[i]>=mn[j]) { int cur=x[j]-x[i]; if(cur<ret) ret=cur; }
	nstck=0;
	for(int i=n-2;i>=1;--i) {
		if(mx[i]>x[i]) {
			int l=-1,r=nstck;
			while(l+1<r) {
				int m=l+(r-l)/2;
				if(mx[i]>=mn[stck[m]]) l=m; else r=m;
			}
			if(l!=-1) { int cur=x[stck[l]]-x[i]; if(cur<ret) ret=cur; }
		}
		if(mn[i]<x[i]) {
			while(nstck>0&&mn[i]<=mn[stck[nstck-1]]) --nstck;
			stck[nstck++]=i;
		}
	}
	printf("%lf\n",.5*ret);
}

int main() {
	run();
	return 0;
}
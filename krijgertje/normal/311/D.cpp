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

const int MOD=95542721;

int n,nops;
int a[100000];

int offset[1<<18];
int val[1<<18][48];

void cube(int x) {
	++offset[x]; if(offset[x]>=48) offset[x]-=48;
}
void propagate(int x,bool update) {
	offset[2*x+1]+=offset[x]; if(offset[2*x+1]>=48) offset[2*x+1]-=48;
	offset[2*x+2]+=offset[x]; if(offset[2*x+2]>=48) offset[2*x+2]-=48;
	offset[x]=0;
	if(!update) return;
	int i1=offset[2*x+1],i2=offset[2*x+2];
	REP(i,48) {
		val[x][i]=val[2*x+1][i1]+val[2*x+2][i2]; if(val[x][i]>=MOD) val[x][i]-=MOD;
		++i1; if(i1>=48) i1-=48; ++i2; if(i2>=48) i2-=48;
	}
}
	
void cube(int x,int l,int r,int ll,int rr) {
	if(ll<l) ll=l; if(rr>r) rr=r; if(ll>rr) return;
	if(l==ll&&r==rr) {
		cube(x);
	} else {
		propagate(x,false);
		int m=l+(r-l)/2;
		cube(2*x+1,l,m,ll,rr); cube(2*x+2,m+1,r,ll,rr);
		propagate(x,true);
	}
}

int get(int x,int l,int r,int ll,int rr,int delta) {
	if(ll<l) ll=l; if(rr>r) rr=r; if(ll>rr) return 0;
	if(l==ll&&r==rr) {
		return val[x][(delta+offset[x])%48];
	} else {
//		propagate(x,true);
		int m=l+(r-l)/2;
		int ret=get(2*x+1,l,m,ll,rr,delta+offset[x])+get(2*x+2,m+1,r,ll,rr,delta+offset[x]); if(ret>=MOD) ret-=MOD; return ret;
	}
}

ll mpow(ll x,ll n,int m) {
	if(n==0) return 1;
	if(n%2==1) return mpow(x,n-1,m)*x%m;
	return mpow(x*x%m,n/2,m);
}

void init(int x,int l,int r) {
	offset[x]=0;
	if(l==r) {
		val[x][0]=a[l]%MOD; FOR(i,1,48) val[x][i]=(ll)val[x][i-1]*(ll)val[x][i-1]%MOD*(ll)val[x][i-1]%MOD;
//		REP(i,48) assert(val[x][i]==mpow(a[l],mpow(3,i,MOD-1),MOD));
	} else {
		int m=l+(r-l)/2;
		init(2*x+1,l,m); init(2*x+2,m+1,r);
		REP(i,48) { val[x][i]=val[2*x+1][i]+val[2*x+2][i]; if(val[x][i]>=MOD) val[x][i]-=MOD; }
	}
	//REP(i,48) printf("%d..%d: %d -> %d\n",l,r,i,val[x][i]);
}


void run(int casenr) {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	init(0,0,n-1);
	
	scanf("%d",&nops);
	REP(op,nops) {
		int t,l,r; scanf("%d%d%d",&t,&l,&r); --l; --r;
		if(t==1) cout<<get(0,0,n-1,l,r,0)<<endl;
		if(t==2) cube(0,0,n-1,l,r);
	}
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}
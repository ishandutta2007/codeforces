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

const int MAXN=200000;

struct P { int x,y,id; P() {} P(int x,int y):x(x),y(y),id(-1) {} };
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
ll side(const P &a,const P &b,const P &c) { return (b-a)^(c-a); }

int no;
P o[MAXN];

int np;
P p[MAXN+1];
bool killed[MAXN+1];

int nh;
P h[MAXN+2];

int lst[MAXN+1],nlst;

void makehull() { // assumes sorted
	nh=0; assert(!killed[0]); h[nh++]=p[0]; int tmp,last=-1;
	tmp=nh; FOR(i,1,np) if(!killed[i]) { while(nh>tmp&&side(h[nh-2],h[nh-1],p[i])<=0) --nh; h[nh++]=p[i]; last=i; }
	tmp=nh; for(int i=last-1;i>=0;--i) if(!killed[i]) { while(nh>tmp&&side(h[nh-2],h[nh-1],p[i])<=0) --nh; h[nh++]=p[i]; }
	--nh;
}

bool solve() {
	no=np; REP(i,np) o[i]=p[i];
	
	p[np++]=P(0,0);
	sort(p,p+np);
	REP(i,np) p[i].id=i;
	REP(i,np) killed[i]=false;
	makehull();
	REP(i,nh) if(h[i].x%2==1||h[i].y%2==1) return true;

	nlst=nh; REP(i,nh) lst[i]=h[i].id;
	FORE(off,1,2) {
		REP(i,np) killed[i]=false; for(int i=off;i<nlst;i+=2) killed[lst[i]]=true;
		makehull();
		REP(i,nh) if(h[i].x%2==1||h[i].y%2==1) return true;
	}
	return false;
}

void run() {
	scanf("%d",&np);
	REP(i,np) scanf("%d%d",&p[i].x,&p[i].y);
	printf("%s\n",solve()?"Ani":"Borna");
}

int main() {
	run();
	return 0;
}
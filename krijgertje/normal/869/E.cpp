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

const int MAXH=2500;
const int MAXW=2500;
const int MAXS1=8177;
const int MAXS2=8177;
const int MAXQ=100000;

int h,w,nq;

int sval[MAXS1][MAXS2];

void sinit2(int a,int b,int ly,int hy) {
	sval[a][b]=0;
	if(ly!=hy) {
		int my=ly+(hy-ly)/2;
		sinit2(a,2*b+1,ly,my);
		sinit2(a,2*b+2,my+1,hy);
	}
}
void sinit(int a,int lx,int hx) {
	if(lx==hx) {
		sinit2(a,0,0,w-1);
	} else {
		int mx=lx+(hx-lx)/2;
		sinit(2*a+1,lx,mx);
		sinit(2*a+2,mx+1,hx);
	}
}
void supd2(int a,int b,int ly,int hy,int LY,int HY,ll V) {
	if(LY<=ly&&hy<=HY) {
		sval[a][b]^=V;
	} else {
		int my=ly+(hy-ly)/2;
		if(LY<=my) supd2(a,2*b+1,ly,my,LY,HY,V);
		if(my+1<=HY) supd2(a,2*b+2,my+1,hy,LY,HY,V);
	}
}
void supd(int a,int lx,int hx,int LX,int HX,int LY,int HY,ll V) {
	if(LX<=lx&&hx<=HX) {
		supd2(a,0,0,w-1,LY,HY,V);
	} else {
		int mx=lx+(hx-lx)/2;
		if(LX<=mx) supd(2*a+1,lx,mx,LX,HX,LY,HY,V);
		if(mx+1<=HX) supd(2*a+2,mx+1,hx,LX,HX,LY,HY,V);
	}
}
ll sget2(int a,int b,int ly,int hy,int Y) {
	if(ly==hy) {
		return sval[a][b];
	} else {
		ll ret=sval[a][b];
		int my=ly+(hy-ly)/2;
		if(Y<=my) ret^=sget2(a,2*b+1,ly,my,Y);
		else ret^=sget2(a,2*b+2,my+1,hy,Y);
		return ret;
	}
}
ll sget(int a,int lx,int hx,int X,int Y) {
	ll ret=sget2(a,0,0,w-1,Y);
	if(lx!=hx) {
		int mx=lx+(hx-lx)/2;
		if(X<=mx) ret^=sget(2*a+1,lx,mx,X,Y);
		else ret^=sget(2*a+2,mx+1,hx,X,Y);
	}
	return ret;
}


map<vector<int>,int> mp; int nr;
int val[MAXQ];

int qkind[MAXQ],qlx[MAXQ],qly[MAXQ],qhx[MAXQ],qhy[MAXQ],qidx[MAXQ];

void run() {
	scanf("%d%d%d",&h,&w,&nq); nr=0;
	REP(i,nq) {
		scanf("%d%d%d%d%d",&qkind[i],&qlx[i],&qly[i],&qhx[i],&qhy[i]); --qlx[i],--qly[i],--qhx[i],--qhy[i];
		if(qkind[i]!=3) { if(qlx[i]>qhx[i]) swap(qlx[i],qhx[i]); if(qly[i]>qhy[i]) swap(qly[i],qhy[i]); }
		if(qkind[i]!=3) { vector<int> v(4); v[0]=qlx[i],v[1]=qly[i],v[2]=qhx[i],v[3]=qhy[i]; if(!mp.count(v)) mp[v]=nr++; qidx[i]=mp[v]; }
	}
	REP(i,nr) { val[i]=0; REP(j,10) val[i]=val[i]*1000+rand(); if(val[i]<0) val[i]=-val[i]; }

	sinit(0,0,h-1);
	REP(i,nq) {
		//printf("processing %d\n",i);
		if(qkind[i]==1) supd(0,0,h-1,qlx[i],qhx[i],qly[i],qhy[i],val[qidx[i]]);
		if(qkind[i]==2) supd(0,0,h-1,qlx[i],qhx[i],qly[i],qhy[i],val[qidx[i]]);
		if(qkind[i]==3) {
			int a=sget(0,0,h-1,qlx[i],qly[i]),b=sget(0,0,h-1,qhx[i],qhy[i]);
			printf("%s\n",a==b?"Yes":"No");
		}
	}
}

int main() {
	run();
	return 0;
}
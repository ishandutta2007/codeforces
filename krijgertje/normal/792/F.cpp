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

const int MAXQ=100000;
typedef struct F { ll num,den; F(ll num,ll den):num(num),den(den) {} } F;
bool operator<(const F &a,const F &b) { return a.num*b.den<b.num*a.den; }

int nq; ll havemana;
bool ans[MAXQ]; int nans;

set<pair<int,int> > xmp;
set<F> fmp;
void remspell(set<pair<int,int> >::iterator it) {
	//printf("removing (%d,%d)\n",it->first,it->second);
	fmp.erase(F(it->second,it->first));
	xmp.erase(it);
}
void addspell(int x,int y) {
	//printf("adding (%d,%d)\n",x,y);
	xmp.insert(MP(x,y));
	fmp.insert(F(y,x));
}
bool below(pair<int,int> b,pair<int,int> a,pair<int,int> c) {
	int bx=b.first,by=b.second,ax=a.first,ay=a.second,cx=c.first,cy=c.second;
	//printf("below (%d,%d) wrt (%d,%d)-(%d,%d)\n",bx,by,ax,ay,cx,cy);
	return (ll)(by-ay)*(cx-ax)<(ll)(cy-ay)*(bx-ax);
}

void learn(int x,int y) {
	//printf("learning(%d,%d)\n",x,y);
	set<pair<int,int> >::iterator nxt=xmp.lower_bound(MP(x,-1));
	if(nxt!=xmp.end()&&nxt->first==x) {
		if(nxt->second<=y) return;
		remspell(nxt++);
	} else if(nxt!=xmp.begin()&&nxt!=xmp.end()) {
		set<pair<int,int> >::iterator prv=nxt; --prv;
		if(!below(MP(x,y),*prv,*nxt)) return;
	} else if(nxt==xmp.begin()&&nxt!=xmp.end()) {
		if(!below(MP(x,y),MP(0,0),*nxt)) return;
	}
	while(nxt!=xmp.begin()) {
		set<pair<int,int> >::iterator prv=nxt; --prv;
		if(prv==xmp.begin()) {
			if(below(*prv,MP(0,0),MP(x,y))) break;
		} else {
			set<pair<int,int> >::iterator pprv=prv; --pprv;
			if(below(*prv,*pprv,MP(x,y))) break;
		}
		remspell(prv);
	}
	while(nxt!=xmp.end()) {
		set<pair<int,int> > ::iterator nnxt=nxt; ++nnxt;
		if(nnxt==xmp.end()) break;
		if(below(*nxt,MP(x,y),*nnxt)) break;
		remspell(nxt++);
	}
	addspell(x,y);
}
bool battle(int t,int h) {
	//printf("battle(%d,%d)\n",t,h);
	set<F>::iterator nxt=fmp.lower_bound(F(havemana,h));
	//if(nxt==fmp.end()) printf("\t->end\n"); else printf("\t->(%lld,%lld)\n",nxt->den,nxt->num);
	if(nxt==fmp.begin()) {
		int x=nxt->den,y=nxt->num;
		// cnt*x>=h, cnt*y<=havemana, cnt<=t
		return (ll)t*x>=h&&havemana*x>=(ll)h*y;
	} else {
		set<F>::iterator prv=nxt; --prv;
		if(nxt==fmp.end()) {
			int x=prv->den,y=prv->num;
			// cnt*x>=h, cnt*y<=havemana, cnt<=t
			return (ll)t*x>=h&&havemana*x>=(ll)h*y;
		} else {
			int x1=prv->den,y1=prv->num;
			int x2=nxt->den,y2=nxt->num;
			// cnt1*x1+cnt2*x2>=h, cnt1*y1+cnt2*y2<=havemana, cnt1+cnt2<=t
			// cnt1*x1+(t-cnt1)*x2>=h, cnt1*y1+(t-cnt1)*y2<=havemana, cnt2=t-cnt1
			// cnt1<=(t*x2-h)/(x2-x1), cnt1>=(t*y2-havemana)/(y2-y1)
			//assert((ll)t*y2-havemana>=0);
			//assert((ll)t*x2-h>=0);
			return ((ll)t*y2-havemana)*(x2-x1)<=((ll)t*x2-h)*(y2-y1);
		}
	}
}

void run() {
	scanf("%d%lld",&nq,&havemana);
	int off=0; nans=0;
	REP(qi,nq) {
		int qtype; scanf("%d",&qtype);
		if(qtype==1) {
			int x,y; scanf("%d%d",&x,&y); x=(x+off)%1000000+1,y=(y+off)%1000000+1;
			learn(x,y);
		}
		if(qtype==2) {
			int t,h; scanf("%d%d",&t,&h); t=(t+off)%1000000+1,h=(h+off)%1000000+1;
			bool res=battle(t,h);
			//printf("%s\n",res?"YES":"NO");
			ans[nans++]=res;
			if(res) off=qi+1;
		}
	}
	REP(i,nans) printf("%s\n",ans[i]?"YES":"NO");

}

void test(int t,int h) {
	FORE(dt,-1,+1) FORE(dh,-1,+1) {
		int tt=t+dt,hh=h+dh;
		if(tt>=1&&hh>=1) printf("(%d,%d)=%s\n",tt,hh,battle(tt,hh)?"YES":"NO");
	}
	puts("");
}
void test() {
	learn(1,10);
	learn(2,25);
	learn(3,40);
	learn(4,60);
	havemana=600; test(61,75);
	havemana=600; test(60,60); // 60*1
	havemana=600; test(42,54); // 30*1+12*2
	havemana=600; test(24,48); // 24*2
	havemana=600; test(18,46); // 8*2+10*3
	havemana=600; test(15,45); // 15*3
	havemana=600; test(14,44); // 12*3+2*4
	havemana=600; test(10,40); // 10*4
	havemana=600; test( 9,30);
}

int main() {
	//test();
	run();
	return 0;
}
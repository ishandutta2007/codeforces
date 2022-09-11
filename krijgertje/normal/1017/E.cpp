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

const int MAXN=100000;
struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
ll operator*(const P &a,const P &b) { return (ll)a.x*b.x+(ll)a.y*b.y; }
ll side(const P &a,const P &b,const P &c) { return (b-a)^(c-a); }


struct Pol {
	char id;
	int n;
	P p[MAXN];

	P h[MAXN+1]; int nh;
	pair<ll,ll> seq[MAXN];
	void calchull() {
		sort(p,p+n); nh=0;
		REP(i,n) { while(nh>=2&&side(h[nh-2],h[nh-1],p[i])<=0) --nh; h[nh++]=p[i]; }
		int tmp=nh; for(int i=n-2;i>=0;--i) { while(nh>tmp&&side(h[nh-2],h[nh-1],p[i])<=0) --nh; h[nh++]=p[i]; } --nh;
	}
	void gen() {
		REP(i,nh) {
			P a=h[i],b=h[(i+1)%nh],c=h[(i+2)%nh];
			seq[i].first=(b-a)*(b-a),seq[i].second=(c-b)*(a-b);
		}
	}
	void print() {
		printf("%c hull:",id); REP(i,nh) printf(" (%d,%d)",h[i].x,h[i].y); puts("");
		printf("%c seq:",id); REP(i,nh) printf(" (%lld,%lld)",seq[i].first,seq[i].second); puts("");
	}
};

Pol a,b;

pair<ll,ll> s[2*MAXN]; int ns;
pair<ll,ll> p[MAXN]; int np;
int nxt[MAXN+1]; // longest proper suffix of p[0..i) that is also a prefix

bool solve() {
	a.calchull(); a.gen();
	b.calchull(); b.gen();
	//a.print(); b.print();
	
	ns=2*a.nh; REP(i,a.nh) s[i]=s[a.nh+i]=a.seq[i];
	np=b.nh; REP(i,b.nh) p[i]=b.seq[i];
	nxt[0]=nxt[1]=0;
	FORE(i,2,np) { nxt[i]=nxt[i-1]; while(nxt[i]!=0&&p[i-1]!=p[nxt[i]]) nxt[i]=nxt[nxt[i]]; if(p[i-1]==p[nxt[i]]) ++nxt[i]; }
	//printf("nxt:"); REPE(i,np) printf(" %d",nxt[i]); puts("");

	int at=0;
	REP(i,ns) {
		while(at!=0&&s[i]!=p[at]) at=nxt[at];
		if(s[i]==p[at]) ++at;
		if(at==np) return true;
	}
	return false;
}

void run() {
	scanf("%d%d",&a.n,&b.n); a.id='A'; b.id='B';
	REP(i,a.n) scanf("%d%d",&a.p[i].x,&a.p[i].y);	
	REP(i,b.n) scanf("%d%d",&b.p[i].x,&b.p[i].y);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}
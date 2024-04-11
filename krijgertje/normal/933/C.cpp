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

const int MAXN=3;
struct C { int x,y,r; };

struct F { int num,den; F():num(0),den(1) {} F(int _num):num(_num),den(1) {} F(int _num,int _den):num(_num),den(_den) { if(den<0) num=-num,den=-den; int g=gcd(abs(num),den); num/=g,den/=g; } double val() const { return 1.0*num/den; } };
void print(const F &u) { printf("%d",u.num); if(u.den!=1) printf("/%d",u.den); }
F operator*(const F &u,const F &v) { return F(u.num*v.num,u.den*v.den); }
F operator+(const F &u,const F &v) { return F(u.num*v.den+v.num*u.den,u.den*v.den); }
F operator-(const F &u) { return F(-u.num,u.den); }
bool operator==(const F &u,const F &v) { return u.num==v.num&&u.den==v.den; }
bool operator<(const F &u,const F &v) { return u.num*v.den<v.num*u.den; }

struct Q { F a,b; int c; Q(int _a):a(F(_a)),b(F(0)),c(0) {} Q(F _a):a(_a),b(F(0)),c(0) {} Q(F _a,F _b,int _c):a(_a),b(_b),c(_c) { for(int i=2;i*i<=c;++i) while(c%(i*i)==0) { if(b.den%i==0) b.den/=i; else b.num*=i; c/=i*i; } if(c==1) a=a+b,b=F(0),c=0; } double val() const { return a.val()+b.val()*sqrt(1.0*c); } };
void print(const Q &u) { bool any=false; if(u.a.num!=0) print(u.a),any=true; if(u.b.num!=0&&u.c!=0) { if(any&&u.b.num>0) printf("+"); if(u.b.num==-u.b.den) printf("-sqrt(%d)",u.c); else if(u.b.num==u.b.den) printf("sqrt(%d)",u.c); else if(u.b.num!=u.b.den) print(u.b),printf("*sqrt(%d)",u.c); any=true; } if(!any) printf("0"); }
Q operator*(const Q &u,const Q &v) { assert(u.c==0||v.c==0); if(v.c!=0) return v*u; return Q(u.a*v.a,u.b*v.a,u.c); }
Q operator+(const Q &u,const Q &v) { assert(u.c==0||v.c==0); if(v.c!=0) return v+u; return Q(u.a+v.a,u.b,u.c); }
Q operator-(const Q &u) { return Q(-u.a,-u.b,u.c); }
bool operator==(const Q &u,const Q &v) { return u.a==v.a&&u.b==v.b&&u.c==v.c; }
bool operator<(const Q &u,const Q &v) { if(!(u.a==v.a)) return u.a<v.a; if(!(u.b==v.b)) return u.b<v.b; return u.c<v.c; }

struct P { Q x,y; P(Q _x,Q _y):x(_x),y(_y) {} };
void print(const P &u) { printf("("); print(u.x); printf(","); print(u.y); printf(")=(%lf,%lf)",u.x.val(),u.y.val()); }
bool iszero(const Q &u) { return u.a.num==0&&(u.b.num==0||u.c==0); }
P operator*(const Q &u,const P &v) { return P(u*v.x,u*v.y); }
P operator+(const P &u,const P &v) { return P(u.x+v.x,u.y+v.y); }
bool operator<(const P &u,const P &v) { if(!(u.x==v.x)) return u.x<v.x; return u.y<v.y; }

int n;
C c[MAXN];


vector<P> intersect(const C &a,const C &b) {
	vector<P> ret;
	int RR=(b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
	if((a.r+b.r)*(a.r+b.r)<RR||RR<(b.r-a.r)*(b.r-a.r)) return ret;

	P u(Q(a.x+b.x),Q(a.y+b.y)),v(Q(b.x-a.x),Q(b.y-a.y)),w(Q(b.y-a.y),Q(a.x-b.x));
	//printf("u="); print(u); printf(",v="); print(v); printf(",w="); print(w); puts("");
	Q cu(F(1,2));
	Q cv(F(a.r*a.r-b.r*b.r,2*RR));
	Q cw(F(0),F(1,2*RR),2*(a.r*a.r+b.r*b.r)*RR-(a.r*a.r-b.r*b.r)*(a.r*a.r-b.r*b.r)-RR*RR);
	//printf("cu="); print(cu); printf(",cv="); print(cv); printf(",cw="); print(cw); if(iszero(cw)) printf(" ZERO"); puts("");

	ret.PB(cu*u+cv*v+cw*w);
	if(!iszero(cw)) ret.PB(cu*u+cv*v+(-cw)*w);
	return ret;
}

map<P,int> mp;
vector<int> par;
int V,E,C;
int find(int a) { if(par[a]==a) return a; return par[a]=find(par[a]); }
bool unite(int a,int b) { a=find(a),b=find(b); if(a==b) return false; par[b]=a; return true; }


int solve() {
	mp.clear(); par.clear(); V=0,E=0,C=0;

	REP(i,n) {
		set<P> cur;
		REP(j,n) if(i!=j) {
			vector<P> now=intersect(c[i],c[j]);
			REPSZ(k,now) cur.insert(now[k]);
			//printf("(%d,%d):",i,j); REPSZ(k,now) { printf(" "); print(now[k]); } puts("");
		}
		++E,++V,++C;
		int cid=SZ(par); par.PB(cid);
		for(auto it=cur.begin();it!=cur.end();++it) {
			E++;
			if(!mp.count(*it)) mp[*it]=cid,++V; else if(unite(cid,mp[*it])) --C;
		}
	}
	//printf("V=%d E=%d C=%d\n",V,E,C);
	int F=1+E+C-V;
	return F;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].r);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
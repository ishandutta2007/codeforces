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
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXPOL=10000;

struct Frac { ll num,den; Frac():num(0),den(1) {} Frac(ll _num,ll _den):num(_num),den(_den) { if(den<0) den=-den,num=-num; if(den==0) { num=0; return; } ll g=gcd(abs(num),den); num/=g,den/=g; } };
int cmp(const Frac &a,const Frac &b) { ll res=a.num*b.den-b.num*a.den; return res<0?-1:res>0?+1:0; }
bool operator<(const Frac &a,const Frac &b) { return cmp(a,b)<0; }

struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
int side(const P &a,const P &b,const P &c) { ll res=(b-a)^(c-a); return res<0?-1:res>0?+1:0; }
int cmp(const P &a,const P &b) {
	bool apos=a.y>0||a.y==0&&a.x>0,bpos=b.y>0||b.y==0&&b.x>0; if(apos!=bpos) return apos?-1:+1;
	ll s=a^b; if(s!=0) return s>0?-1:+1;
	return 0;
}
bool operator<(const P &a,const P &b) { return cmp(a,b)<0; }
bool operator==(const P &a,const P &b) { return a.x==b.x&&a.y==b.y; }
bool operator!=(const P &a,const P &b) { return a.x!=b.x||a.y!=b.y; }
Frac dist(const P &a,const P &b,const P &dir) { P d=b-a; return Frac(d^a,d^dir); }

struct FP { double x,y; FP() {} FP(double x,double y):x(x),y(y) {} };
FP operator*(const Frac &f,const P &p) { return FP(1.0*f.num/f.den*p.x,1.0*f.num/f.den*p.y); }
FP operator-(const FP &a,const FP &b) { return FP(a.x-b.x,a.y-b.y); }
double operator^(const FP &a,const FP &b) { return a.x*b.y-a.y*b.x; }
double area(const FP &a,const FP &b,const FP &c) { return 0.5*((b-a)^(c-a)); }

P curdir;
struct Seg { P a,b; int pol,idx; Seg() {} Seg(P a,P b,int pol,int idx):a(a),b(b),pol(pol),idx(idx) {} };
bool operator<(const Seg &u,const Seg &v) {
	Frac tu=dist(u.a,u.b,curdir),tv=dist(v.a,v.b,curdir); assert(tu.den!=0&&tv.den!=0);
	int s=cmp(tu,tv); if(s!=0) return s<0;
	assert(u.pol==v.pol);
	if(u.idx==v.idx) return 0;
	if(u.a==v.a&&u.b!=v.b) { P tmpdir=curdir; curdir=(u.b^v.b)>0?u.b:v.b; bool res=u<v; curdir=tmpdir; return res; }
	if(u.b==v.b&&u.a!=v.a) { P tmpdir=curdir; curdir=(u.a^v.a)>0?v.a:u.a; bool res=u<v; curdir=tmpdir; return res; }
	printf("failed to compare (%d,%d)-(%d,%d) [%d:%d] and (%d,%d)-(%d,%d) [%d:%d] with curdir (%d,%d)\n",u.a.x,u.a.y,u.b.x,u.b.y,u.pol,u.idx,v.a.x,v.a.y,v.b.x,v.b.y,v.pol,v.idx,curdir.x,curdir.y);
	assert(false); return 0;
}

struct E { P dir; int seg,by; E() {} E(P dir,int seg,int by):dir(dir),seg(seg),by(by) {} };
bool operator<(const E &a,const E &b) { int s=cmp(a.dir,b.dir); if(s!=0) return s<0; if(a.by!=b.by) return a.by<0; return 0; }

double calcarea(const Seg &u,const Seg &v,const P &ldir,const P &rdir) {
	Frac tlu=dist(u.a,u.b,ldir),tlv=dist(v.a,v.b,ldir),trv=dist(v.a,v.b,rdir),tru=dist(u.a,u.b,rdir);
	FP A=tlu*ldir,B=tlv*ldir,C=trv*rdir,D=tru*rdir;
	//printf("\t(%lf,%lf)(%lf,%lf)(%lf,%lf)(%lf,%lf)\n",A.x,A.y,B.x,B.y,C.x,C.y,D.x,D.y);
	return area(A,B,C)+area(A,C,D);
}

int npol;
vector<P> pol[MAXPOL];

P orig;
vector<Seg> segs;
vector<E> e;
vector<int> initsegs;
set<Seg> active;

double solve() {
	orig=P(0,0);
	segs.clear();
	REP(i,npol) REPSZ(j,pol[i]) {
		P a=pol[i][j],b=pol[i][(j+1)%SZ(pol[i])];
		int s=side(orig,a,b); if(s==0) continue; if(s<0) swap(a,b);
		segs.PB(Seg(a,b,i,j));
	}
	//REPSZ(i,segs) printf("seg%d: (%d,%d)-(%d,%d) [%d:%d]\n",i,segs[i].a.x,segs[i].a.y,segs[i].b.x,segs[i].b.y,segs[i].pol,segs[i].idx);
	
	e.clear(),initsegs.clear();
	P zero(1,0);
	REPSZ(i,segs) {
		P a=segs[i].a,b=segs[i].b;
		if(a<b) {
			e.PB(E(a,i,+1)),e.PB(E(b,i,-1));
		} else if(zero<b) {
			e.PB(E(zero,i,+1)),e.PB(E(b,i,-1)),e.PB(E(a,i,+1));
		} else {
			e.PB(E(a,i,+1));
		}
	}
	sort(e.begin(),e.end());
	//REPSZ(i,e) printf("e%d: (%d,%d) [%d:%+d] <%d,%d>\n",i,e[i].dir.x,e[i].dir.y,e[i].seg,e[i].by,segs[e[i].seg].pol,segs[e[i].seg].idx);

	/*REPSZ(i,e) {
		if(i!=0&&!(e[i-1].dir<e[i].dir)) continue;
		printf("dir=(%d,%d)\n",e[i].dir.x,e[i].dir.y);
		curdir=e[i].dir;
		REPSZ(j,segs) {
			Frac d=dist(segs[j].a,segs[j].b,e[i].dir);
			printf("\t%d: %lld/%lld=%lf\n",j,d.num,d.den,1.0*d.num/d.den);
		}
	}*/
	
	double ret=0;
	active.clear();
	REPSZ(i,e) {
		curdir=e[i].dir;
		if(e[i].by==+1) {
			active.insert(segs[e[i].seg]);
		} else {
			//Seg u=segs[e[i].seg]; printf("i=%d curdir=(%d,%d) curseg=(%d,%d)-(%d,%d)[%d:%d]\n",i,curdir.x,curdir.y,u.a.x,u.a.y,u.b.x,u.b.y,u.pol,u.idx);
			//printf("\tactive:"); for(auto it=active.begin();it!=active.end();++it) printf(" (%d,%d)-(%d,%d)[%d:%d]{%d%d}",it->a.x,it->a.y,it->b.x,it->b.y,it->pol,it->idx,*it<u?1:0,u<*it?1:0); puts("");
			assert(active.erase(segs[e[i].seg])==1);
		}
		if(i+1>=SZ(e)||e[i].dir<e[i+1].dir) {
			//printf("active:"); for(auto it=active.begin();it!=active.end();++it) printf(" (%d,%d)-(%d,%d)[%d:%d]",it->a.x,it->a.y,it->b.x,it->b.y,it->pol,it->idx); puts("");
			if(SZ(active)!=0) {
				assert(SZ(active)>=2); Seg u=*active.begin(),v=*next(active.begin()); assert(u.pol==v.pol);
				P nxtdir=i+1>=SZ(e)?zero:e[i+1].dir;
				double cur=calcarea(u,v,curdir,nxtdir);
				ret+=cur;
				//printf("found (%d,%d)-(%d,%d) and (%d,%d)-(%d,%d) between angle of (%d,%d) and (%d,%d) = %lf\n",u.a.x,u.a.y,u.b.x,u.b.y,v.a.x,v.a.y,v.b.x,v.b.y,curdir.x,curdir.y,nxtdir.x,nxtdir.y,cur);
			}
		}
	}
	return ret;
}

void run() {
	scanf("%d",&npol);
	REP(i,npol) { int cnt; scanf("%d",&cnt); pol[i]=vector<P>(cnt); REP(j,cnt) scanf("%d%d",&pol[i][j].x,&pol[i][j].y); }
	printf("%.15lf\n",solve());
}

int main() {
	run();
	return 0;
}
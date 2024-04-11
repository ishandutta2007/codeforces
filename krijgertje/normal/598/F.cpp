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

const int MAXN=1000;
typedef struct P { int x,y; P(int x,int y):x(x),y(y) {} P() {} } P;
const P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
const ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
const ll operator*(const P &a,const P &b) { return (ll)a.x*b.x+(ll)a.y*b.y; }
typedef struct R { ll num,den; int type; } R;
bool operator<(const R &p,const R &q) {
	if((p.num<0)!=(q.num<0)) return p.num<0;
	ll a=abs(p.num),b=p.den,c=abs(q.num),d=q.den; bool inv=p.num<0;
	while(true) {
		ll aa=a/b,cc=c/d; if(aa!=cc) return !inv?aa<cc:cc<aa;
		a%=b,c%=d;
		if(a==0||c==0) break;
		inv=!inv; swap(a,b); swap(c,d);
	}
	if(a!=0||c!=0) return !inv?a==0:c==0;
	return false;
}


P p[MAXN+1]; int n,nq;
R r[2*MAXN]; int nr;
char buff[100];
int read() { scanf("%s",buff); int at=0,sgn=+1,ret=0,flen=0; if(buff[at]=='-') sgn=-sgn,++at; while(isdigit(buff[at])) ret=ret*10+buff[at++]-'0'; if(buff[at]=='.') ++at; while(isdigit(buff[at])) ret=ret*10+buff[at++]-'0',++flen; REP(i,2-flen) ret=ret*10; return sgn*ret; }
void intersect(const P &a,const P &b,const P &c,const P &d) {
	// a+u(b-a)=c+v*(d-c)

	// a.x+u*b.x-u*a.x=c.x+v*d.x-v*c.x
	// a.y+u*b.y-u*a.y=c.y+v*d.y-v*c.y

	// u=(c.x+v*d.x-v*c.x-a.x)/(b.x-a.x)
	// v=((a.x-c.x)*(b.y-a.y)-(a.y-c.y)*(b.x-a.x)) / ((d.x-c.x)*(b.y-a.y)-(d.y-c.y)*(b.x-a.x))
	// v=(a-c)^(b-a) / (d-c)^(b-a)
	// u=(((a.x-c.x)*(d.y-c.y))-(a.y-c.y)*(d.x-c.x))/((d.x-c.x)*(b.y-a.y)-(d.y-c.y)*(b.x-a.x))
	// u=(a-c)^(d-c) / (d-c)^(b-a)

	// v*(d-c)=a-c -> (a.x-c.x)*(d.y-c.y)-(a.y-c.y)*(d.x-c.x)==0

	ll den=(d-c)^(b-a);
	//printf("\t(%d,%d)-(%d,%d) with (%d,%d)-(%d,%d) -> %lld\n",a.x,a.y,b.x,b.y,c.x,c.y,d.x,d.y,den);
	if(den==0) {
		ll side=(a-c)^(d-c); bool hor=d.x==c.x;
		//printf("\t\t%lld %s\n",side,hor?"HOR":"VERT");
		if(side!=0) return;
		r[nr].num=!hor?a.x-c.x:a.y-c.y,r[nr].den=!hor?d.x-c.x:d.y-c.y,r[nr].type=2,++nr;
		r[nr].num=!hor?b.x-c.x:b.y-c.y,r[nr].den=!hor?d.x-c.x:d.y-c.y,r[nr].type=2,++nr;
	} else {
		ll num1=(a-c)^(d-c),num2=(a-c)^(b-a);
		if(den<0) num1=-num1,num2=-num2,den=-den;
		//printf("\t\t%lld/%lld and %lld/%lld\n",num1,den,num2,den);
		if(num1<0||num1>den) return;
		r[nr].num=num2,r[nr].den=den,r[nr].type=num1==0?(((b-c)^(d-c))>0?+1:-1):num1==den?(((a-c)^(d-c))>0?+1:-1):0,++nr;
	}
}

void run() {
	scanf("%d%d",&n,&nq); REP(i,n) p[i].x=read(),p[i].y=read(); p[n]=p[0];

	REP(qi,nq) {
		P a,b; a.x=read(),a.y=read(),b.x=read(),b.y=read();
		nr=0; REP(i,n) intersect(p[i],p[i+1],a,b); REP(i,n) if(r[i].den<0) r[i].den=-r[i].den,r[i].num=-r[i].num; sort(r,r+nr);
		//printf("%d:",nr); REP(i,nr) printf(" %c%.4lf",r[i].type==0?'|':r[i].type==1?'+':r[i].type==-1?'-':'=',1.0*r[i].num/r[i].den); puts("");
		double ret=0; int ctype=0;
		for(int at=0,to=at;at<nr;at=to++) {
			if(ctype!=0) ret+=1.0*r[at].num/r[at].den-1.0*r[at-1].num/r[at-1].den;
			while(to<nr&&!(r[at]<r[to])) ++to;
			if(to-at==1) {
				assert(ctype==0||ctype==2); assert(r[at].type==0);
				ctype=2-ctype;
			} else if(to-at==2) {
				assert(r[at].type!=0&&r[at+1].type!=0);
				if(ctype==0||ctype==2) {
					assert(r[at].type!=2||r[at+1].type!=2);
					if(r[at].type==r[at+1].type) ctype=ctype;
					else if(r[at].type==-r[at+1].type) ctype=2-ctype;
					else ctype=ctype==0?r[at].type+r[at+1].type-2:2-r[at].type-r[at+1].type;
				} else {
					assert(r[at].type==2||r[at+1].type==2);
					if(r[at].type==2&&r[at+1].type==2) ctype=ctype;
					else if(ctype==r[at].type||ctype==r[at+1].type) ctype=0;
					else ctype=2;
				}
			} else assert(false);
		}
		assert(ctype==0);
		ret*=sqrt((b-a)*(b-a))/100;
		printf("%.9lf\n",ret);
	}
}

int main() {
	run();
	return 0;
}
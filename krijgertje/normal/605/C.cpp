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

const int MAXN=100000;
typedef struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} } P;
bool operator<(const P &a,const P &b) { if(a.x!=b.x) return a.x<b.x; return a.y<b.y; }
const P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
const ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }
int side(const P &a,const P &b,const P &c) { ll res=(b-a)^(c-a); return res<0?-1:res>0?+1:0; }
bool intersect(const P &a,const P &b,const P &c,const P &d, double &res) { ll num1=(a-c)^(d-c),num2=(a-c)^(b-a),den=(d-c)^(b-a); if(den<0) num1=-num1,num2=-num2,den=-den; if(num2<0||num2>den) return false; res=1.0*num1/den; return true; }

int n;
P want;
P p[MAXN];

P h[MAXN+2]; int nh;
void addh(const P &a) { while(nh>=2&&side(h[nh-2],h[nh-1],a)>=0) --nh; h[nh++]=a; }

void run() {
	scanf("%d",&n); scanf("%d%d",&want.x,&want.y); REP(i,n) scanf("%d%d",&p[i].x,&p[i].y); sort(p,p+n);
	int mxx=p[0].x; REP(i,n) if(p[i].x>mxx) mxx=p[i].x;
	int mxy=p[0].y; REP(i,n) if(p[i].y>mxy) mxy=p[i].y;

	nh=0; addh(P(0,mxy)); REP(i,n) addh(p[i]); addh(P(mxx,0));
	//REP(i,nh) printf("(%d,%d)",h[i].x,h[i].y); puts("");

	double ret=want.x+want.y;
	REP(i,nh-1) {
		double cur;
		if(!intersect(P(0,0),want,h[i],h[i+1],cur)) continue; else cur=1/cur;
		//printf("(%d,%d)-(%d,%d): %.9lf (%.9lf)\n",h[i].x,h[i].y,h[i+1].x,h[i+1].y,cur,1/cur);
		if(cur<ret) ret=cur;
	}
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}
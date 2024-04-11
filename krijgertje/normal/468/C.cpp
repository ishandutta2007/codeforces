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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

ll MOD;
typedef struct Res { ull times; ull rem; Res() {} Res(ull x) { times=x/MOD; rem=x%MOD; } } Res;
Res operator+(const Res &a,const Res &b) { Res ret; ret.times=a.times+b.times; ret.rem=a.rem+b.rem; if(ret.rem>=MOD) ret.rem-=MOD,++ret.times; return ret; }
Res operator*(const Res &a,const ull &b) { Res ret(0); REP(i,b) ret=ret+a; return ret; }


int d[20]; int nd;
Res calc(ull x) {
	if(x==0) return 0;
	nd=0; for(ull y=x;y!=0;y/=10) d[nd++]=y%10;
	int sum=0; REP(i,nd) sum+=d[i];
	Res mult(1),pmult(0);
	Res ret(sum);
	REP(i,nd) {
		sum-=d[i];
		ret=ret+mult*sum*d[i];
		ret=ret+mult*(d[i]*(d[i]-1)/2);
		ret=ret+pmult*i*d[i]*45;
		pmult=mult; mult=mult*10; 
	}
	return ret;
}

map<ull,ull> have;

void run() {
	cin>>MOD;
	REP(i,1000) {
		ull l=0,h=1;
		while(calc(h).times<i) l=h,h+=h+1;
		while(l+1<h) {
			ull m=l+(h-l)/2;
			if(calc(m).times<i) l=m; else h=m;
		}
		Res cur=calc(h);
		if(cur.times!=i) continue;
		//printf("%d -> %llu -> %llu / %llu\n",i,h,cur.times,cur.rem);
		if(have.count(cur.rem)) {
			ull a=have[cur.rem]+1,b=h;
			cout<<a<<" "<<b<<endl;
			break;
		} else {
			have[cur.rem]=h;
		}
	}
}

int main() {
	run();
	return 0;
}
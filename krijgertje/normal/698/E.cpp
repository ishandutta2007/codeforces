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

int sec,mn,hour,wday,day,month;
int nq;

int bdaysinmonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool isleap(int y) { return y%4==0&&y%100!=0||y%400==0; }
int daysinmonth(int y,int m) { return bdaysinmonth[m-1]+(m==2&&isleap(y)?1:0); }

int daystoyear(int y) {
	int cnt=y-1970,cnt4=(cnt+1)/4,cnt100=(cnt+69)/100,cnt400=(cnt+369)/400,cnt366=cnt4-cnt100+cnt400;
	int ret=cnt*365+cnt366;
	//int check=0; FOR(i,1970,y) check+=isleap(i)?366:365; if(check!=ret) printf("%d: expect %d got %d\n",y,check,ret);
	return ret;
}

void parse(ll x,int &s,int &m,int &h,int &wd,int &D,int &M,int &Y) {
	s=x%60; x/=60;
	m=x%60; x/=60;
	h=x%24; x/=24;
	wd=(4+x)%7; if(wd==0) wd=7;
	int ll=1970,hh=ll+1; while(x>=daystoyear(hh)) hh+=hh-ll;
	while(ll+1<hh) { int mm=ll+(hh-ll)/2; if(x>=daystoyear(mm)) ll=mm; else hh=mm; }
	Y=ll; x-=daystoyear(ll);
	M=1; while(x>=daysinmonth(Y,M)) x-=daysinmonth(Y,M++);
	D=x+1;
}
ll format(int s,int m,int h,int D,int M,int Y) {
	ll ret=daystoyear(Y);
	FOR(i,1,M) ret+=daysinmonth(Y,i);
	ret+=D-1;
	ret=((ret*24+h)*60+m)*60+s;
	return ret;
}

void incdays(int &s,int &m,int &h,int &wd,int &D,int &M,int &Y,int delta) { s=m=h=0; wd=(wd+delta)%7; if(wd==0) wd=7; D+=delta; while(true) { int cnt=daysinmonth(Y,M); if(D<=cnt) break; D-=cnt; if(M<12) ++M; else M=1,++Y; } }
ll calcwday(int s,int m,int h,int wd,int D,int M,int Y) {
	if(wday==-1&&day!=-1) return LLONG_MAX;
	//printf("wday from %4d-%2d-%2d %d %2d:%2d:%2d\n",Y,M,D,wd,h,m,s);
	while(true) {
		int os=s,om=m,oh=h,owd=wd,oD=D,oM=M,oY=Y;
		if(month!=-1) while(M!=month) incdays(s,m,h,wd,D,M,Y,daysinmonth(Y,M)-D+1);
		if(wday!=-1) while(wd!=wday) incdays(s,m,h,wd,D,M,Y,1);
		if(hour!=-1) if(h<hour) h=hour,m=s=0; else if(h>hour) incdays(s,m,h,wd,D,M,Y,1),h=hour;
		if(mn!=-1) if(m<mn) m=mn,s=0; else if(m>mn) if(h<23) ++h,m=mn,s=0; else incdays(s,m,h,wd,D,M,Y,1),m=mn;
		if(sec!=-1) if(s<sec) s=sec; else if(s>sec) if(m<60) ++m,s=sec; else if(h<23) ++h,m=0,s=sec; else incdays(s,m,h,wd,D,M,Y,1),s=sec;
		if(os==s&&om==m&&oh==h&&owd==wd&&oD==D&&oM==M&&oY==Y) break;
	}
	//printf("       -> %4d-%2d-%2d %d %2d:%2d:%2d\n",Y,M,D,wd,h,m,s);
	ll ret=format(s,m,h,D,M,Y);
	//parse(ret,s,m,h,wd,D,M,Y);	printf("        ( %4d-%2d-%2d %d %2d:%2d:%2d )\n",Y,M,D,wd,h,m,s);
	return ret;
}
ll calcday(int s,int m,int h,int wd,int D,int M,int Y) {
	if(day==-1&&wday!=-1) return LLONG_MAX;
	//printf(" day from %4d-%2d-%2d %d %2d:%2d:%2d\n",Y,M,D,wd,h,m,s);
	while(true) {
		int os=s,om=m,oh=h,owd=wd,oD=D,oM=M,oY=Y;
		if(month!=-1) while(M!=month) incdays(s,m,h,wd,D,M,Y,daysinmonth(Y,M)-D+1);
		if(day!=-1&&D!=day) incdays(s,m,h,wd,D,M,Y,D<day?day-D:daysinmonth(Y,M)-D+day);
		if(hour!=-1) if(h<hour) h=hour,m=s=0; else if(h>hour) incdays(s,m,h,wd,D,M,Y,1),h=hour;
		if(mn!=-1) if(m<mn) m=mn,s=0; else if(m>mn) if(h<23) ++h,m=mn,s=0; else incdays(s,m,h,wd,D,M,Y,1),m=mn;
		if(sec!=-1) if(s<sec) s=sec; else if(s>sec) if(m<60) ++m,s=sec; else if(h<23) ++h,m=0,s=sec; else incdays(s,m,h,wd,D,M,Y,1),s=sec;
		if(os==s&&om==m&&oh==h&&owd==wd&&oD==D&&oM==M&&oY==Y) break;
	}
	//printf("       -> %4d-%2d-%2d %d %2d:%2d:%2d\n",Y,M,D,wd,h,m,s);
	ll ret=format(s,m,h,D,M,Y);
	//parse(ret,s,m,h,wd,D,M,Y);	printf("        ( %4d-%2d-%2d %d %2d:%2d:%2d )\n",Y,M,D,wd,h,m,s);
	return ret;
}


void run() {
	scanf("%d%d%d%d%d%d%d",&sec,&mn,&hour,&wday,&day,&month,&nq);
	REP(qi,nq) {
		ll x; scanf("%lld",&x); ++x;
		int s,m,h,wd,D,M,Y; parse(x,s,m,h,wd,D,M,Y);
		ll a=calcwday(s,m,h,wd,D,M,Y),b=calcday(s,m,h,wd,D,M,Y);
		printf("%lld\n",min(a,b));
	}

}

int main() {
	run();
	return 0;
}
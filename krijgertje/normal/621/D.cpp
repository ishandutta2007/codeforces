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


const double eps=1e-9;

//lg(x^(y^z))=lg(x)*y^z					lg(lg(x^(y^z)))=lg(lg(x))+lg(y)*z
//lg((x^y)^z)=lg(x^(y*z))=lg(x)*y*z		lg(lg((x^y)^z))=lg(lg(x)*y*z)=lg(lg(x))+lg(y)+lg(z)

char ret[10]; bool any; double res;

void solve(char* s,double x,double y,double z,int type) {
	double lnx=log(x); bool mn=lnx<0; if(mn) lnx=-lnx;
	double cur=log(lnx)+(type==0?log(y)*z:log(y)+log(z));
	if(!any||!mn&&cur>res+eps||mn&&cur<res-eps) strcpy(ret,s),any=true,res=cur;
}

double x,y,z;
void run() {
	scanf("%lf%lf%lf",&x,&y,&z);
	
	strcpy(ret,"???"); any=false;
	if(x>=1||y<1&&z<1) solve("x^y^z",x,y,z,0);
	if(x>=1||y<1&&z<1) solve("x^z^y",x,z,y,0);
	if(x>=1||y<1&&z<1) solve("(x^y)^z",x,y,z,1);
	if(x>=1||y<1&&z<1) solve("(x^z)^y",x,z,y,1);
	if(y>=1||x<1&&z<1) solve("y^x^z",y,x,z,0);
	if(y>=1||x<1&&z<1) solve("y^z^x",y,z,x,0);
	if(y>=1||x<1&&z<1) solve("(y^x)^z",y,x,z,1);
	if(y>=1||x<1&&z<1) solve("(y^z)^x",y,z,x,1);
	if(z>=1||x<1&&y<1) solve("z^x^y",z,x,y,0);
	if(z>=1||x<1&&y<1) solve("z^y^x",z,y,x,0);
	if(z>=1||x<1&&y<1) solve("(z^x)^y",z,x,y,1);
	if(z>=1||x<1&&y<1) solve("(z^y)^x",z,y,x,1);
	printf("%s\n",ret);
}

int main() {
	run();
	return 0;
}
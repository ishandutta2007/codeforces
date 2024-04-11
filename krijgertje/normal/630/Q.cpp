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

int l3,l4,l5;

double calc3(double r) {
	double x=r/2;
	double y=r/6*sqrt(3);
	double z=sqrt(r*r-x*x-y*y);
	double ret=z*r*r/12*sqrt(3);
	//printf("3: %lf,%lf,%lf -> %lf\n",x,y,z,ret);
	return ret;
}

double calc4(double r) {
	double x=r/2;
	double y=r/2;
	double z=sqrt(r*r-x*x-y*y);
	double ret=z*r*r/3;
	//printf("4: %lf,%lf,%lf -> %lf\n",x,y,z,ret);
	return ret;
}

double calc5(double r) {
	double x=r/2;
	double y=r/2*(sqrt(5)+1)/sqrt(10-2*sqrt(5));
	double z=sqrt(r*r-x*x-y*y);
	double ret=z*r*r*5/4/sqrt(5-sqrt(20))/3;
	//printf("tan(54)=%lf=%lf\n",tan(1.0*54/360*2*acos(-1)),(sqrt(5)+1)/(sqrt(10-2*sqrt(5))));
	//printf("tan(36)=%lf=%lf\n",tan(1.0*36/360*2*acos(-1)),sqrt(5-sqrt(20)));
	//printf("5: %lf,%lf,%lf -> %lf\n",x,y,z,ret);
	return ret;
}


void run() {
	scanf("%d%d%d",&l3,&l4,&l5);
	printf("%.12lf\n",calc3(l3)+calc4(l4)+calc5(l5));

}

int main() {
	run();
	return 0;
}
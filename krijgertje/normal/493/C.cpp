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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int a[200000],na;
int b[200000],nb;

int reta,retb;

void run() {
	scanf("%d",&na); REP(i,na) scanf("%d",&a[i]); sort(a,a+na);
	scanf("%d",&nb); REP(i,nb) scanf("%d",&b[i]); sort(b,b+nb);
	int x=0,ai=0,bi=0; reta=3*na; retb=3*nb;
	while(ai<na||bi<nb) {
		x=bi>=nb||ai<na&&a[ai]<b[bi]?a[ai]:b[bi];
		while(ai<na&&a[ai]<=x) ++ai;
		while(bi<nb&&b[bi]<=x) ++bi;
		int cura=ai*2+(na-ai)*3,curb=bi*2+(nb-bi)*3;
		if(cura-curb>reta-retb||cura-curb==reta-retb&&cura>reta) reta=cura,retb=curb;
	}
	printf("%d:%d\n",reta,retb);
}

int main() {
	run();
	return 0;
}
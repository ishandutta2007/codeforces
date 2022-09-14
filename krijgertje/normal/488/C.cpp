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

int myhp,myatk,mydef;
int ophp,opatk,opdef;
int chp,catk,cdef;

void run() {
	scanf("%d%d%d",&myhp,&myatk,&mydef);
	scanf("%d%d%d",&ophp,&opatk,&opdef);
	scanf("%d%d%d",&chp,&catk,&cdef);

	myatk-=opdef;
	opatk-=mydef;

	int ret=INT_MAX,cur=0;
	if(myatk<=0) { int need=1-myatk; myatk+=need; cur+=catk*need; }
	do {
		int turns=(ophp+myatk-1)/myatk;
		FORE(copatk,0,max(0,opatk)) {
			int opdmg=turns*copatk;
			int ndef=copatk>=opatk?0:opatk-copatk,nhp=myhp>=opdmg+1?0:opdmg+1-myhp;
			int now=cur+ndef*cdef+nhp*chp;
			if(now<ret) ret=now;
		}
		myatk++; cur+=catk;
	} while(myatk<=ophp);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
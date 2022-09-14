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

const int MAXN=1179858;

int num,den;

bool isprm[MAXN+1];
bool ispal[MAXN+1];
int cntprm[MAXN+1];
int cntpal[MAXN+1];


void run() {
	scanf("%d%d",&num,&den);

	memset(isprm,true,sizeof(isprm));
	isprm[0]=isprm[1]=false;
	for(int i=2;i*i<=MAXN;++i) if(isprm[i]) for(int j=i*i;j<=MAXN;j+=i) isprm[j]=false;
	cntprm[0]=isprm[0]?1:0; FORE(i,1,MAXN) cntprm[i]=cntprm[i-1]+(isprm[i]?1:0);

	memset(ispal,false,sizeof(ispal));
	for(int x=1;;++x) { int y=x; for(int xx=x;xx!=0;xx/=10) y=y*10+xx%10; if(y>MAXN) break; ispal[y]=true; }
	for(int x=1;;++x) { int y=x; for(int xx=x/10;xx!=0;xx/=10) y=y*10+xx%10; if(y>MAXN) break; ispal[y]=true; }
	cntpal[0]=ispal[0]?1:0; FORE(i,1,MAXN) cntpal[i]=cntpal[i-1]+(ispal[i]?1:0);

	int ret=-1;
	FORE(i,1,MAXN) {
		//printf("%d: %d/%d = %lf\n",i,cntprm[i],cntpal[i],1.0*cntprm[i]/cntpal[i]);
		if((ll)cntprm[i]*den<=(ll)num*cntpal[i]) ret=i;
		if((ll)cntprm[i]*den>=(ll)num*cntpal[i]+den*cntpal[i]) break;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}
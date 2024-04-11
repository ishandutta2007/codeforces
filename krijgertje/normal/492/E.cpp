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

// res.first*a+res.second*b==gcd(a,b)
pair<int,int> egcd(int a,int b) {
	if(b==0) return MP(1,0);
	pair<int,int> res=egcd(b,a%b);
	//printf("\t%d,%d -> %d,%d\n",b,a%b,res.first,res.second);
	// res.first*b+res.second*(a-a/b*b)=gcd(a,b)
	return MP(res.second,res.first-res.second*(a/b));
}

int sz,nt,dx,dy;
int tx[100000],ty[100000];
int res[1000000];

void run() {
	//1000000 100 341397 841347
	scanf("%d%d%d%d",&sz,&nt,&dx,&dy); REP(i,nt) scanf("%d%d",&tx[i],&ty[i]);
	pair<int,int> g=egcd(dx,sz);
	//printf("%d*%d+%d*%d=%lld\n",g.first,dx,g.second,sz,(ll)g.first*dx+(ll)g.second*sz);
	memset(res,0,sizeof(res));
	REP(i,nt) {
		int q=((ll)g.first*-tx[i])%sz; if(q<0) q+=sz;
		int x=(tx[i]+(ll)q*dx)%sz;
		int y=(ty[i]+(ll)q*dy)%sz;
		res[y]++;
		//printf("(%d,%d) in %d steps to (%d,%d)\n",tx[i],ty[i],q,x,y);
	}
	int ret=0; FOR(i,1,sz) if(res[i]>res[ret]) ret=i; printf("%d %d\n",0,ret);

}

int main() {
	run();
	return 0;
}
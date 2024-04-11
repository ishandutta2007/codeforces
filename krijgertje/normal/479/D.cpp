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

int n,len,x,y;
int a[100000];

int pos(int want,int margin) {
	int p=0,q=0;
	while(q<n) {
		if(a[q]-a[p]==want&&(a[n-1]-a[q]>=margin||a[p]-a[0]>=margin)) return a[p];
		if(a[q]-a[p]<want) ++q; else ++p;
	}
	return -1;
}

int ans[2],nans;
void calc() {
	int posx=pos(x,0),posy=pos(y,0);
	if(posx!=-1&&posy!=-1) { nans=0; return; }
	if(posx!=-1) { ans[0]=a[0]+y; nans=1; return; }
	if(posy!=-1) { ans[0]=a[0]+x; nans=1; return; }
	int posplus=pos(x+y,0);
	if(posplus!=-1) { ans[0]=posplus+x; nans=1; return; }
	int posmin=pos(y-x,x);
	if(posmin!=-1&&posmin-x>=a[0]) { ans[0]=posmin-x; nans=1; return; }
	if(posmin!=-1&&posmin+y<=a[n-1]) { ans[0]=posmin+y; nans=1; return; }
	ans[0]=a[0]+x; ans[1]=a[0]+y; nans=2;
}

void run() {
	scanf("%d%d%d%d",&n,&len,&x,&y);
	REP(i,n) scanf("%d",&a[i]);

	calc();
	printf("%d\n",nans);
	REP(i,nans) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}